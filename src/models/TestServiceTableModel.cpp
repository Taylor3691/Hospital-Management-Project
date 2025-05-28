#include "TestServiceTableModel.h"

TestServiceTableModel::TestServiceTableModel(Role role, QObject* parent)
    : SelectableTableModel(
        {
            "Mã dịch vụ",
            "Tên dịch vụ",
            "Chi phí",
        }, role, parent)
{
    if (role == Role::Select) {
        _headers.insert(0, "");

        auto data = ServiceLocator::getInstance()->testServiceRepository()->data();
        _data = QVector<const TestService*>(data.begin(), data.end());
    }
    else if (role == Role::Display) {
        _selectedItems.clear();
    }
}

int TestServiceTableModel::rowCount(const QModelIndex&) const {
    if (_role == Role::Display) {
        return _selectedItems.size();
    }
    return _data.size();
}

QVariant TestServiceTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    int row = index.row();
    int col = index.column();
    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return {};
    }

    auto service = _role == Role::Display ? _selectedItems[row] : _data[row];

    if (_role == Role::Select) {
        if (col == 0) {
            if (role == Qt::CheckStateRole) {
                return _selectedItems.contains(service) ? Qt::Checked : Qt::Unchecked;
            }
            return {};
        }
        col--;
    }

    if (role == Qt::TextAlignmentRole && col == 2) {
        return int(Qt::AlignVCenter | Qt::AlignRight);
    }

    if (role == Qt::DisplayRole) {
        switch (col) {
            case 0: return QString::fromStdString(service->id());
            case 1: return QString::fromStdString(service->name());
            case 2: return QString::number(service->cost(), 'f', 2);
            default: return {};
        }
    }

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(service)));
    }

    return {};
}

bool TestServiceTableModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (_role != Role::Select || index.column() != 0 || role != Qt::CheckStateRole) {
        return false;
    }

    int row = index.row();
    if (row < 0 || row >= rowCount()) {
        return {};
    }

    auto service = _data[row];
    bool checked = value.toInt() == Qt::Checked;
    
    if (checked) {
        if (!_selectedItems.contains(service)) {
            _selectedItems.push_back(service);
            emit dataChanged(index, index, { Qt::CheckStateRole });
        }
    } else {
        if (_selectedItems.contains(service)) {
            _selectedItems.removeOne(service);
            emit dataChanged(index, index, { Qt::CheckStateRole });
        }
    }

    return true;
}

void TestServiceTableModel::refresh() {
    beginResetModel();
    endResetModel();
}

void TestServiceTableModel::sort(int column, Qt::SortOrder order) {
    beginResetModel();
    std::stable_sort(
        _role == Role::Display ? _selectedItems.begin() : _data.begin(),
        _role == Role::Display ? _selectedItems.end() : _data.end(),
        [=](const TestService* a, const TestService* b) {
            int compareResult = 0;
            switch (column) {
                case 0: compareResult = compare(a->id(), b->id()); break;
                case 1: compareResult = compare(a->name(), b->name()); break;
                case 2: compareResult = compare(a->cost(), b->cost()); break;
                default: return false;
            }

            if (compareResult == 0) return false;
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}

void TestServiceTableModel::selectAll() {
    if (_selectedItems.size() == _data.size())

    beginResetModel();
    _selectedItems = _data;
    endResetModel();
}

void TestServiceTableModel::clearAll() {
    if (_selectedItems.isEmpty()) {
        return;
    }

    beginResetModel();
    _selectedItems.clear();
    endResetModel();
}
