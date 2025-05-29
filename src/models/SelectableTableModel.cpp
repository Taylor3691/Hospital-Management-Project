#include "SelectableTableModel.h"

SelectableTableModel::SelectableTableModel(
    const QVector<QString>& headers,
    QObject* parent
)
    : TableModel(headers, parent) {}

Qt::ItemFlags SelectableTableModel::flags(const QModelIndex& index) const {
    Qt::ItemFlags defaultFlags = TableModel::flags(index);

    if (index.column() == 0) {
        return defaultFlags | Qt::ItemIsUserCheckable;
    }

    return defaultFlags;
}
