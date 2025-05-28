#include "MedicineTableModel.h"

MedicineTableModel::MedicineTableModel(QObject* parent)
    : TableModel(
        {
            "Mã thuốc",
            "Tên thuốc",
            "Đơn vị tính",
            "Đơn giá",
            "Số lượng",
        },
        parent)
{
    auto data = ServiceLocator::getInstance()->medicineRepository()->data();
    _cachedData = QVector<const Medicine*>(data.begin(), data.end());
}

int MedicineTableModel::rowCount(const QModelIndex&) const {
    return _cachedData.size();
}

QVariant MedicineTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto medicine = _cachedData[row];

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(medicine)));
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    switch (col) {
    case 0: return QString::fromStdString(medicine->id());
    case 1: return QString::fromStdString(medicine->name());
    case 2: return QString::fromStdString(medicine->unit());
    case 3: return medicine->pricePerUnit();
    case 4: return medicine->quantity();
    default: return {};
    }
}

void MedicineTableModel::add(std::unique_ptr<Medicine> medicine) {
    ServiceLocator::getInstance()->medicineManager()->add(std::move(medicine));
    refresh();
}

void MedicineTableModel::update(const Medicine& medicine) {
    ServiceLocator::getInstance()->medicineManager()->update(medicine);
    refresh();
}

void MedicineTableModel::removeByIds(const std::vector<std::string>& ids) {
    ServiceLocator::getInstance()->medicineManager()->removeByIds(ids);
    refresh();
}

void MedicineTableModel::find(const std::vector<RFilter<Medicine>>& filters) {
    beginResetModel();
    auto filteredData = ServiceLocator::getInstance()->medicineManager()->find(filters);
    _cachedData = QVector<const Medicine*>(filteredData.begin(), filteredData.end());
    endResetModel();
}

void MedicineTableModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::getInstance()->medicineRepository()->data();
    _cachedData = QVector<const Medicine*>(data.begin(), data.end());
    endResetModel();
}

void MedicineTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(_cachedData.begin(), _cachedData.end(),
        [column, order](const Medicine* a, const Medicine* b) {
            int compareResult = 0;
            switch (column) {
            case 0: compareResult = compare(a->id(), b->id()); break;
            case 1: compareResult = compare(a->name(), b->name()); break;
            case 2: compareResult = compare(a->unit(), b->unit()); break;
            case 3: compareResult = compare(a->pricePerUnit(), b->pricePerUnit()); break;
            case 4: compareResult = compare(a->quantity(), b->quantity()); break;
            default: return false;
            }

            if (compareResult == 0) {
                return false;
            }
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}
