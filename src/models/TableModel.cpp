#include "TableModel.h"

TableModel::TableModel(const QVector<QString>& headers, QObject* parent)
    : QAbstractTableModel(parent), _headers(headers) {}

int TableModel::columnCount(const QModelIndex&) const {
    return _headers.size();
}

QVariant TableModel::headerData(
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
