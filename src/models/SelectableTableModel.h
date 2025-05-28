#ifndef SELECTABLE_TABLE_MODEL_H
#define SELECTABLE_TABLE_MODEL_H

#include "TableModel.h"
#include "../utils/utils.h"

class SelectableTableModel : public TableModel {
    Q_OBJECT

protected:
    Role _role;

public:
    explicit SelectableTableModel(const QVector<QString>& headers,
        Role role = Role::Display, QObject* parent = nullptr);

public:
    virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual void selectAll() = 0;
    virtual void clearAll() = 0;
};

#endif // !SELECTABLE_TABLE_MODEL_H
