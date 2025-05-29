#include "MedicineUsageTableModel.h"

MedicineUsageTableModel::MedicineUsageTableModel(QObject* parent)
    : TableModel(
        {
            "Mã đơn",
            "Mã thuốc",
            "Tên thuốc",
            "Đơn vị tính",
            "Đơn giá",
            "Số lượng",
            "Cách dùng",
        },
        parent) {}

int MedicineUsageTableModel::rowCount(const QModelIndex&) const {
    return _data.size();
}

QVariant MedicineUsageTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto usage = _data[row];

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(usage)));
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    switch (col) {
    case 0: return QString::fromStdString(usage->id());
    case 1: return QString::fromStdString(usage->medicineId());
    case 2: return QString::fromStdString(usage->name());
    case 3: {
        auto data = ServiceLocator::getInstance()->medicineRepository()->data();
        auto unit = from(data)
            .where(&Medicine::id, usage->medicineId())
            .findOne()->unit();
        return QString::fromStdString(unit);
    }
    case 4: return QString::number(usage->price(), 'f', 2);
    case 5: return QString::number(usage->usedQuantity());
    case 6: return QString::fromStdString(usage->description());
    default: return {};
    }
}

void MedicineUsageTableModel::setData(const QVector<const MedicineUsage*>& data) {
    _data = data;
    refresh();
}

void MedicineUsageTableModel::refresh() {
    beginResetModel();
    endResetModel();
}

void MedicineUsageTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(_data.begin(), _data.end(),
        [column, order](const MedicineUsage* a, const MedicineUsage* b) {
            int compareResult = 0;
            switch (column) {
            case 0: compareResult = compare(a->id(), b->id()); break;
            case 1: compareResult = compare(a->medicineId(), b->medicineId()); break;
            case 2: compareResult = compare(a->name(), b->name()); break;
            case 3: {
                auto data = ServiceLocator::getInstance()->medicineRepository()->data();
                auto unitA = from(data)
                    .where(&Medicine::id, a->medicineId())
                    .findOne()->unit();
                auto unitB = from(data)
                    .where(&Medicine::id, b->medicineId())
                    .findOne()->unit();
                compareResult = compare(unitA, unitB); break;
            }
            case 4: compareResult = compare(a->price(), b->price()); break;
            case 5: compareResult = compare(a->usedQuantity(), b->usedQuantity()); break;
            case 6: compareResult = compare(a->description(), b->description()); break;
            default: return false;
            }

            if (compareResult == 0) {
                return false;
            }
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}
