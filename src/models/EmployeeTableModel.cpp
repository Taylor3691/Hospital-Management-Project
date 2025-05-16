#include "EmployeeTableModel.h"

EmployeeTableModel::EmployeeTableModel(
    const QVector<QString>& headers,
    const QVector<const Employee*>& data,
    QObject* parent
)
    : QAbstractTableModel(parent)
    , _headers(headers)
    , _data(data) {}

int EmployeeTableModel::rowCount(const QModelIndex&) const {
    return _data.size();
}

int EmployeeTableModel::columnCount(const QModelIndex&) const {
    return _headers.size();
}

QVariant EmployeeTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto& employee = _data[row];
    switch (col) {
    case 0: return QString::fromStdString(employee->id());
    case 1: return QString::fromStdString(employee->name());
    case 2: return QString::fromStdString(Date::toString(employee->dob()));
    case 3: return QString::fromStdString(employee->gender());
    case 4: return QString::fromStdString(employee->phone());
    case 5: return QString::fromStdString(employee->address());
    case 6: return QString::fromStdString(employee->education());
    case 7: return employee->baseSalary();
    default: return {};
    }
}

QVariant EmployeeTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
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
