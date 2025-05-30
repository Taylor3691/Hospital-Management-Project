#include "PatientTableModel.h"

PatientTableModel::PatientTableModel(QObject* parent)
    : TableModel(
        {
            "Mã bệnh nhân",
            "Họ Tên",
            "Giới tính",
            "Địa chỉ",
            "Điện thoại",
            "Ngày sinh",
            "Bảo hiểm y tế",
        },
        parent)
{
    auto data = ServiceLocator::instance()->patientRepository()->data();
    _cachedData = QVector<const Patient*>(data.begin(), data.end());
}

int PatientTableModel::rowCount(const QModelIndex&) const {
    return _cachedData.size();
}

QVariant PatientTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto patient = _cachedData[row];

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(patient)));
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    switch (col) {
    case 0: return QString::fromStdString(patient->id());
    case 1: return QString::fromStdString(patient->name());
    case 2: return QString::fromStdString(patient->gender());
    case 3: return QString::fromStdString(patient->address());
    case 4: return QString::fromStdString(patient->phone());
    case 5: return QString::fromStdString(Date::toString(patient->dob()));
    case 6: {
        const auto& insurance = patient->insuranceCard();
        return QString::fromStdString(insurance ? insurance->id() : "");
    }
    default: return {};
    }
}

void PatientTableModel::add(std::unique_ptr<Patient> patient) {
    ServiceLocator::instance()->patientManager()->add(std::move(patient));
    refresh();
}

void PatientTableModel::update(const Patient& patient) {
    ServiceLocator::instance()->patientManager()->update(patient);
    refresh();
}

void PatientTableModel::removeByIds(const std::vector<std::string>& ids) {
    ServiceLocator::instance()->patientManager()->removeByIds(ids);
    refresh();
}

void PatientTableModel::find(const std::vector<RFilter<Patient>>& filters) {
    beginResetModel();
    auto filteredData = ServiceLocator::instance()->patientManager()->find(filters);
    _cachedData = QVector<const Patient*>(filteredData.begin(), filteredData.end());
    endResetModel();
}

void PatientTableModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::instance()->patientRepository()->data();
    _cachedData = QVector<const Patient*>(data.begin(), data.end());
    endResetModel();
}

void PatientTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(_cachedData.begin(), _cachedData.end(),
        [column, order](const Patient* a, const Patient* b) {
            int compareResult = 0;
            switch (column) {
            case 0: compareResult = compare(a->id(), b->id()); break;
            case 1: compareResult = compare(a->name(), b->name()); break;
            case 2: compareResult = compare(a->gender(), b->gender()); break;
            case 3: compareResult = compare(a->address(), b->address()); break;
            case 4: compareResult = compare(a->phone(), b->phone()); break;
            case 5: compareResult = compare(a->dob(), b->dob()); break;
            case 6: {
                const auto insuranceA = a->insuranceCard();
                const auto insuranceB = b->insuranceCard();
                compareResult = (insuranceA && insuranceB) ?
                    compare(insuranceA->id(), insuranceB->id()) :
                    (!insuranceA && !insuranceB) ? 0 : insuranceA ? 1 : -1;
                break;
            }
            default: return false;
            }

            if (compareResult == 0) {
                return false;
            }
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}
