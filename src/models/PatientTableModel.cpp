#include "PatientTableModel.h"

PatientTableModel::PatientTableModel(QObject* parent)
    : QAbstractTableModel(parent)
    , _headers(
        {
            "ID",
            "Họ Tên",
            "Giới tính",
            "Địa chỉ",
            "Điện thoại",
            "Ngày sinh",
            "Bảo hiểm y tế",
        })
{
    auto data = ServiceLocator::patientManager()->getAll();
    _cachedData = QVector<const Patient*>(data.begin(), data.end());
}

int PatientTableModel::rowCount(const QModelIndex&) const {
    return _cachedData.size();
}

int PatientTableModel::columnCount(const QModelIndex&) const {
    return _headers.size();
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

    const auto& insurance = patient->insuranceCard();
    switch (col) {
    case 0: return QString::fromStdString(patient->id());
    case 1: return QString::fromStdString(patient->name());
    case 2: return QString::fromStdString(patient->gender());
    case 3: return QString::fromStdString(patient->address());
    case 4: return QString::fromStdString(patient->phone());
    case 5: return QString::fromStdString(Date::toString(patient->dob()));
    case 6:
        return QString::fromStdString(insurance ? insurance->id() : "");
    default: return {};
    }
}

QVariant PatientTableModel::headerData(
    int section, Qt::Orientation orientation, int role
) const {
    if (role == Qt::TextAlignmentRole && orientation == Qt::Vertical) {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    if (orientation == Qt::Horizontal) {
        if (section >= 0 && section < _headers.size()) {
            return _headers[section];
        }
        return {};
    }
    else if (orientation == Qt::Vertical) {
        return section + 1;
    }
    return {};
}

void PatientTableModel::add(std::unique_ptr<Patient> patient) {
    ServiceLocator::patientManager()->add(std::move(patient));
    refresh();
}

void PatientTableModel::update(const Patient& patient) {
    ServiceLocator::patientManager()->update(patient);
    refresh();
}

void PatientTableModel::removeByIds(const std::vector<std::string>& ids) {
    ServiceLocator::patientManager()->removeByIds(ids);
    refresh();
}

void PatientTableModel::find(const std::vector<RFilter<Patient>>& filters) {
    beginResetModel();
    auto filteredData = ServiceLocator::patientManager()->find(filters);
    _cachedData = QVector<const Patient*>(filteredData.begin(), filteredData.end());
    endResetModel();
}

void PatientTableModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::patientManager()->getAll();
    _cachedData = QVector<const Patient*>(data.begin(), data.end());
    endResetModel();
}
