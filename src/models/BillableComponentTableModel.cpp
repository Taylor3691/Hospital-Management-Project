#include "BillableComponentTableModel.h"

BillableComponentTableModel::BillableComponentTableModel(QObject* parent)
    : TableModel(
        {
            "Mã phiếu",
            "Tên",
            "Đơn vị tính",
            "Đơn giá",
            "Số lượng",
            "Thành tiền",
        },
        parent) {
}

int BillableComponentTableModel::rowCount(const QModelIndex&) const {
    return static_cast<int>(_data.size());
}

QVariant BillableComponentTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto usage = _data[row].get();

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(usage)));
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    switch (col) {
    case 0: return QString::fromStdString(usage->id());
    case 1: return QString::fromStdString(usage->name());
    case 2: {
        if (auto medicineUsage = dynamic_cast<MedicineUsage*>(usage)) {
            auto data = ServiceLocator::instance()->medicineRepository()->data();
            auto unit = from(data)
                .where(&Medicine::id, medicineUsage->medicineId())
                .findOne()->unit();
            return QString::fromStdString(unit);
        }
        return "dịch vụ";
    }
    case 3: {
        if (auto medicineUsage = dynamic_cast<MedicineUsage*>(usage)) {
            return QString::number(medicineUsage->price(), 'f', 2);
        }
        else if (auto test = dynamic_cast<ClinicalTest*>(usage)) {
            return QString::number(test->cost(), 'f', 2);
        }
        return 0.0;
    }
    case 4: {
        if (auto medicineUsage = dynamic_cast<MedicineUsage*>(usage)) {
            return medicineUsage->usedQuantity();
        }
        return 1;
    }
    case 5:
        return QString::number(usage->calculateFee(), 'f', 2);
    default: return {};
    }
}

void BillableComponentTableModel::setData(const std::vector<const BillableComponent*>& data) {
    _data.clear();
    for (const auto& usage : data) {
        _data.push_back(std::unique_ptr<BillableComponent>(
            static_cast<BillableComponent*>(usage->clone())));
    }
    refresh();
}

void BillableComponentTableModel::refresh() {
    beginResetModel();
    endResetModel();
}

void BillableComponentTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(_data.begin(), _data.end(),
        [column, order](
            const std::unique_ptr<BillableComponent>& a,
            const std::unique_ptr<BillableComponent>& b
        ) {
            int compareResult = 0;
            switch (column) {
            case 0: compareResult = compare(a->id(), b->id()); break;
            case 1: compareResult = compare(a->name(), b->name()); break;
            case 2: {
                std::string unitA;
                if (auto usage = dynamic_cast<MedicineUsage*>(a.get())) {
                    auto data = ServiceLocator::instance()->medicineRepository()->data();
                    auto unit = from(data)
                        .where(&Medicine::id, usage->medicineId())
                        .findOne()->unit();
                    unitA = unit;
                }
                else {
                    unitA = "dịch vụ";
                }
                std::string unitB;
                if (auto usage = dynamic_cast<MedicineUsage*>(b.get())) {
                    auto data = ServiceLocator::instance()->medicineRepository()->data();
                    auto unit = from(data)
                        .where(&Medicine::id, usage->medicineId())
                        .findOne()->unit();
                    unitB = unit;
                }
                else {
                    unitB = "dịch vụ";
                }
                compareResult = compare(unitA, unitB); break;
            }
            case 3: {
                auto priceA = 0.0;
                if (auto usage = dynamic_cast<MedicineUsage*>(a.get())) {
                    priceA = usage->price();
                }
                else if (auto test = dynamic_cast<ClinicalTest*>(a.get())) {
                    priceA = test->cost();
                }
                auto priceB = 0.0;
                if (auto usage = dynamic_cast<MedicineUsage*>(b.get())) {
                    priceB = usage->price();
                }
                else if (auto test = dynamic_cast<ClinicalTest*>(b.get())) {
                    priceB = test->cost();
                }
                compareResult = compare(priceA, priceB); break;
            }
            case 4: {
                auto quantityA = 1;
                if (auto usage = dynamic_cast<MedicineUsage*>(a.get())) {
                    quantityA = usage->usedQuantity();
                }
                auto quantityB = 1;
                if (auto usage = dynamic_cast<MedicineUsage*>(b.get())) {
                    quantityB = usage->usedQuantity();
                }
                compareResult = compare(quantityA, quantityB); break;
            }
            case 5: compareResult = compare(a->calculateFee(), b->calculateFee()); break;
            default: return false;
            }

            if (compareResult == 0) {
                return false;
            }
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}
