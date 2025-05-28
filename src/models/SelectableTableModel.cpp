#include "SelectableTableModel.h"

SelectableTableModel::SelectableTableModel(
    const QVector<QString>& headers,
    Role role,
    QObject* parent
)
    : TableModel(headers, parent)
    , _role(role) {}

Qt::ItemFlags SelectableTableModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags defaultFlags = TableModel::flags(index);

    if (_role == Role::Select && index.column() == 0) {
        return defaultFlags | Qt::ItemIsUserCheckable;
    }

    return defaultFlags;
}
