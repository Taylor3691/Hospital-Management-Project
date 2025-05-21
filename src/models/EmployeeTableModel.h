#ifndef EMPLOYEE_TABLE_MODEL_H
#define EMPLOYEE_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QVector>
#include "../ServiceLocator.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Receptionist.h"

class EmployeeTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    QVector<QString> _headers;
    QVector<const Employee*> _cachedData;

public:
    explicit EmployeeTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;
    void add(std::unique_ptr<Employee> employee);
    void update(const Employee& employee);
    void removeByIds(const std::vector<std::string>& ids);
    void refresh();
};

#endif // !EMPLOYEE_TABLE_MODEL_H
