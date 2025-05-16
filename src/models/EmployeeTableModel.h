#ifndef EMPLOYEE_TABLE_MODEL_H
#define EMPLOYEE_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QVector>
#include "../models/Employee.h"

class EmployeeTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    QVector<QString> _headers;
    QVector<const Employee*> _data;

public:
    explicit EmployeeTableModel(const QVector<QString>& headers,
        const QVector<const Employee*>& data, QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;
};

#endif // !EMPLOYEE_TABLE_MODEL_H
