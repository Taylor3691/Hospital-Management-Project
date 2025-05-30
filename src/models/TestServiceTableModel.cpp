#include "TestServiceTableModel.h"

TestServiceTableModel::TestServiceTableModel(
    const QVector<std::string>& selectedItems,
    QObject* parent
)
    : SelectableTableModel(
        {
            "",
            "Mã dịch vụ",
            "Tên dịch vụ",
            "Chi phí",
        }, parent)
    , _selectedTests(selectedItems)
{
    auto data = ServiceLocator::instance()->testServiceRepository()->data();
    _data = QVector<const TestService*>(data.begin(), data.end());
}

int TestServiceTableModel::rowCount(const QModelIndex&) const {
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

    auto service = _data[row];

    if (col == 0) {
        if (role == Qt::CheckStateRole) {
            return _selectedTests.contains(service->id()) ? Qt::Checked : Qt::Unchecked;
        }
        return {};
    }

    if (role == Qt::TextAlignmentRole && col == 3) {
        return int(Qt::AlignVCenter | Qt::AlignRight);
    }

    if (role == Qt::DisplayRole) {
        switch (col) {
            case 1: return QString::fromStdString(service->id());
            case 2: return QString::fromStdString(service->name());
            case 3: return QString::number(service->cost(), 'f', 2);
            default: return {};
        }
    }

    if (role == Qt::UserRole) {
        return QVariant::fromValue(const_cast<void*>(static_cast<const void*>(service)));
    }

    return {};
}

bool TestServiceTableModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (index.column() != 0 || role != Qt::CheckStateRole) {
        return false;
    }

    int row = index.row();
    if (row < 0 || row >= rowCount()) {
        return {};
    }

    auto service = _data[row];
    bool checked = value.toInt() == Qt::Checked;
    
    if (checked) {
        if (!_selectedTests.contains(service->id())) {
            _selectedTests.push_back(service->id());
            emit dataChanged(index, index, { Qt::CheckStateRole });
        }
    } else {
        if (_selectedTests.contains(service->id())) {
            _selectedTests.removeOne(service->id());
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
    std::stable_sort(_data.begin(), _data.end(),
        [=](const TestService* a, const TestService* b) {
            int compareResult = 0;
            switch (column) {
                case 1: compareResult = compare(a->id(), b->id()); break;
                case 2: compareResult = compare(a->name(), b->name()); break;
                case 3: compareResult = compare(a->cost(), b->cost()); break;
                default: return false;
            }

            if (compareResult == 0) return false;
            return order == Qt::AscendingOrder ? (compareResult < 0) : (compareResult > 0);
        });
    endResetModel();
}

void TestServiceTableModel::selectAll() {
    if (_selectedTests.size() == _data.size())

    beginResetModel();
    for (const auto& test : _data) {
        _selectedTests.push_back(test->id());
    }
    endResetModel();
}

void TestServiceTableModel::clearAll() {
    if (_selectedTests.isEmpty()) {
        return;
    }

    beginResetModel();
    _selectedTests.clear();
    endResetModel();
}

QVector<std::string> TestServiceTableModel::selectedItems() {
    return _selectedTests;
}
