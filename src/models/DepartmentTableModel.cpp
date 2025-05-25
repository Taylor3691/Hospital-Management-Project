#include "DepartmentTableModel.h"

DepartmentTableModel::DepartmentTableModel(QObject* parent)
    : QAbstractTableModel(parent)
    , _headers(
        {
            "ID",
            "Tên khoa",
            "Ngày thành lập",
            "Mô tả",
            "ID trưởng khoa",
        })
{
    auto data = ServiceLocator::departmentManager()->getAll();
    _cachedData = QVector<const Department*>(data.begin(), data.end());
}

int DepartmentTableModel::rowCount(const QModelIndex&) const {
    return _cachedData.size();
}

int DepartmentTableModel::columnCount(const QModelIndex&) const {
    return _headers.size();
}

QVariant DepartmentTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto department = _cachedData[row];

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(department)));
    }

    if (role != Qt::DisplayRole) {
        return {};
    }

    switch (col) {
    case 0: return QString::fromStdString(department->id());
    case 1: return QString::fromStdString(department->name());
    case 2: return QString::fromStdString(Date::toString(department->foundationDate()));
    case 3: return QString::fromStdString(department->description());
    case 4: return QString::fromStdString(department->headId());
    default: return {};
    }
}

QVariant DepartmentTableModel::headerData(
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

void DepartmentTableModel::add(std::unique_ptr<Department> department) {
    ServiceLocator::departmentManager()->add(std::move(department));
    refresh();
}

void DepartmentTableModel::update(const Department& department) {
    ServiceLocator::departmentManager()->update(department);
    refresh();
}

void DepartmentTableModel::removeByIds(const std::vector<std::string>& ids) {
    ServiceLocator::departmentManager()->removeByIds(ids);
    refresh();
}

void DepartmentTableModel::find(const std::vector<RFilter<Department>>& filters) {
    beginResetModel();
    auto filteredData = ServiceLocator::departmentManager()->find(filters);
    _cachedData = QVector<const Department*>(filteredData.begin(), filteredData.end());
    endResetModel();
}

void DepartmentTableModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::departmentManager()->getAll();
    _cachedData = QVector<const Department*>(data.begin(), data.end());
    endResetModel();
}

void DepartmentTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(_cachedData.begin(), _cachedData.end(),
        [column, order](const Department* a, const Department* b) {
            int compareResult = 0;
            switch (column) {
            case 0: compareResult = compare(a->id(), b->id()); break;
            case 1: compareResult = compare(a->name(), b->name()); break;
            case 2: compareResult = compare(a->foundationDate(), b->foundationDate()); break;
            case 3: compareResult = compare(a->description(), b->description()); break;
            case 4: compareResult = compare(a->headId(), b->headId()); break;
            default: return false;
            }

            if (compareResult == 0) {
                return false;
            }
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}
