#include "EmployeeTableModel.h"

EmployeeTableModel::EmployeeTableModel(QObject* parent)
    : TableModel(
        {
            "Mã nhân viên",
            "Họ Tên",
            "Giới tính",
            "Địa chỉ",
            "Điện thoại",
            "Ngày sinh",
            "Học vấn",
            "Lương cơ bản",
            "Mã khoa",
            "Giấy phép",
            "Trách nhiệm",
            "Phụ cấp",
            "Số ngày làm việc",
        },
        parent)
{
    auto data = ServiceLocator::getInstance()->employeeRepository()->data();
    _cachedData = QVector<const Employee*>(data.begin(), data.end());
}

int EmployeeTableModel::rowCount(const QModelIndex&) const {
    return _cachedData.size();
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

void EmployeeTableModel::add(std::unique_ptr<Employee> employee) {
    ServiceLocator::getInstance()->employeeManager()->add(std::move(employee));
    refresh();
}

void EmployeeTableModel::update(const Employee& employee) {
    ServiceLocator::getInstance()->employeeManager()->update(employee);
    refresh();
}

void EmployeeTableModel::removeByIds(const std::vector<std::string>& ids) {
    ServiceLocator::getInstance()->employeeManager()->removeByIds(ids);
    refresh();
}

void EmployeeTableModel::find(const std::vector<RFilter<Employee>>& filters) {
    beginResetModel();
    auto filteredData = ServiceLocator::getInstance()->employeeManager()->find(filters);
    _cachedData = QVector<const Employee*>(filteredData.begin(), filteredData.end());
    endResetModel();
}

void EmployeeTableModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::getInstance()->employeeRepository()->data();
    _cachedData = QVector<const Employee*>(data.begin(), data.end());
    endResetModel();
}

void EmployeeTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(_cachedData.begin(), _cachedData.end(),
        [column, order](const Employee* a, const Employee* b) {
            int compareResult = 0;
            switch (column) {
            case 0: compareResult = compare(a->id(), b->id()); break;
            case 1: compareResult = compare(a->name(), b->name()); break;
            case 2: compareResult = compare(a->gender(), b->gender()); break;
            case 3: compareResult = compare(a->address(), b->address()); break;
            case 4: compareResult = compare(a->phone(), b->phone()); break;
            case 5: compareResult = compare(a->dob(), b->dob()); break;
            case 6: compareResult = compare(a->education(), b->education()); break;
            case 7: compareResult = compare(a->baseSalary(), b->baseSalary()); break;
            case 8: {
                auto docA = dynamic_cast<const Doctor*>(a);
                auto docB = dynamic_cast<const Doctor*>(b);
                compareResult = (docA && docB) ? compare(docA->specialty(), docB->specialty()) :
                    (!docA && !docB) ? 0 : docA ? 1 : -1;
                break;
            }
            case 9: {
                auto docA = dynamic_cast<const Doctor*>(a);
                auto docB = dynamic_cast<const Doctor*>(b);
                compareResult = (docA && docB) ? compare(docA->license(), docB->license()) :
                    (!docA && !docB) ? 0 : docA ? 1 : -1;
                break;
            }
            case 10: {
                auto nurseA = dynamic_cast<const Nurse*>(a);
                auto nurseB = dynamic_cast<const Nurse*>(b);
                compareResult = (nurseA && nurseB) ? compare(nurseA->duty(), nurseB->duty()) :
                    (!nurseA && !nurseB) ? 0 : nurseA ? 1 : -1;
                break;
            }
            case 11: {
                auto recA = dynamic_cast<const Receptionist*>(a);
                auto recB = dynamic_cast<const Receptionist*>(b);
                compareResult = (recA && recB) ? compare(recA->subsidies(), recB->subsidies()) :
                    (!recA && !recB) ? 0 : recA ? 1 : -1;
                break;
            }
            case 12: {
                auto recA = dynamic_cast<const Receptionist*>(a);
                auto recB = dynamic_cast<const Receptionist*>(b);
                compareResult = (recA && recB) ? compare(recA->workingDays(), recB->workingDays()) :
                    (!recA && !recB) ? 0 : recA ? 1 : -1;
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
