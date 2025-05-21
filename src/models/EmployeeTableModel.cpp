#include "EmployeeTableModel.h"

EmployeeTableModel::EmployeeTableModel(QObject* parent)
    : QAbstractTableModel(parent)
    , _headers(
        {
            "ID",
            "Họ Tên",
            "Giới tính",
            "Địa chỉ",
            "Điện thoại",
            "Ngày sinh",
            "Học vị",
            "Lương cơ bản",
            "ID khoa",
            "Giấy phép",
            "Trách nhiệm",
            "Phụ cấp",
            "Số ngày làm việc",
        })
{
    auto data = ServiceLocator::employeeManager()->getAll();
    _cachedData = QVector<const Employee*>(data.begin(), data.end());
}

int EmployeeTableModel::rowCount(const QModelIndex&) const {
    return _cachedData.size();
}

int EmployeeTableModel::columnCount(const QModelIndex&) const {
    return _headers.size();
}

QVariant EmployeeTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto employee = _cachedData[row];

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(employee)));
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    switch (col) {
    case 0: return QString::fromStdString(employee->id());
    case 1: return QString::fromStdString(employee->name());
    case 2: return QString::fromStdString(employee->gender());
    case 3: return QString::fromStdString(employee->address());
    case 4: return QString::fromStdString(employee->phone());
    case 5: return QString::fromStdString(Date::toString(employee->dob()));
    case 6: return QString::fromStdString(employee->education());
    case 7: return QString::number(employee->baseSalary(), 'f', 2);
    case 8:
        if (auto doctor = dynamic_cast<const Doctor*>(employee)) {
            return QString::fromStdString(doctor->specialty());
        }
        return "";
    case 9:
        if (auto doctor = dynamic_cast<const Doctor*>(employee)) {
            return QString::fromStdString(doctor->license());
        }
        return "";
    case 10:
        if (auto nurse = dynamic_cast<const Nurse*>(employee)) {
            return QString::fromStdString(nurse->duty());
        }
        return "";
    case 11:
        if (auto receptionist = dynamic_cast<const Receptionist*>(employee)) {
            return QString::number(receptionist->subsidies(), 'f', 2);
        }
        return "";
    case 12:
        if (auto receptionist = dynamic_cast<const Receptionist*>(employee)) {
            return QString::number(receptionist->workingDays());
        }
        return "";
    default: return {};
    }
}

QVariant EmployeeTableModel::headerData(
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
    } else if (orientation == Qt::Vertical) {
        return section + 1;
    }
    return {};
}

void EmployeeTableModel::add(std::unique_ptr<Employee> employee) {
    ServiceLocator::employeeManager()->add(std::move(employee));
    refresh();
}

void EmployeeTableModel::update(const Employee& employee) {
    ServiceLocator::employeeManager()->update(employee);
    refresh();
}

void EmployeeTableModel::removeByIds(const std::vector<std::string>& ids) {
    ServiceLocator::employeeManager()->removeByIds(ids);
    refresh();
}

void EmployeeTableModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::employeeManager()->getAll();
    _cachedData = QVector<const Employee*>(data.begin(), data.end());
    endResetModel();
}
