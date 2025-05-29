#include "ClinicalTestTableModel.h"

ClinicalTestTableModel::ClinicalTestTableModel(QObject* parent)
    : TableModel(
        {
            "Mã phiếu",
            "Mã dịch vụ",
            "Tên dịch vụ",
            "Trạng thái",
            "Chi phí",
            "Kết quả",
        },
        parent) {}

int ClinicalTestTableModel::rowCount(const QModelIndex&) const {
    return _data.size();
}

QVariant ClinicalTestTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto clinicalTest = _data[row];

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(clinicalTest)));
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    switch (col) {
    case 0: return QString::fromStdString(clinicalTest->id());
    case 1: return QString::fromStdString(clinicalTest->testId());
    case 2: return QString::fromStdString(clinicalTest->name());
    case 3: return clinicalTest->completed() ? "Đã kiểm tra" : "Chưa kiểm tra";
    case 4: return QString::number(clinicalTest->cost(), 'f', 2);
    case 5: return QString::fromStdString(clinicalTest->result());
    default: return {};
    }
}

void ClinicalTestTableModel::setData(const QVector<const ClinicalTest*>& data) {
    _data = data;
    refresh();
}

void ClinicalTestTableModel::refresh() {
    beginResetModel();
    endResetModel();
}

void ClinicalTestTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(_data.begin(), _data.end(),
        [column, order](const ClinicalTest* a, const ClinicalTest* b) {
            int compareResult = 0;
            switch (column) {
            case 0: compareResult = compare(a->id(), b->id()); break;
            case 1: compareResult = compare(a->testId(), b->testId()); break;
            case 2: compareResult = compare(a->name(), b->name()); break;
            case 3: compareResult = compare(a->completed(), b->completed()); break;
            case 4: compareResult = compare(a->cost(), b->cost()); break;
            case 5: compareResult = compare(a->result(), b->result()); break;
            default: return false;
            }

            if (compareResult == 0) {
                return false;
            }
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}
