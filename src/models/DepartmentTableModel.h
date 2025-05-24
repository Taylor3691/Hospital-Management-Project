#ifndef DEPARTMENT_TABLE_MODEL_H
#define DEPARTMENT_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QVector>
#include "../ServiceLocator.h"
#include "Department.h"

class DepartmentTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    QVector<QString> _headers;
    QVector<const Department*> _cachedData;

public:
    explicit DepartmentTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;
    void add(std::unique_ptr<Department> department);
    void update(const Department& department);
    void removeByIds(const std::vector<std::string>& ids);
    void find(const std::vector<RFilter<Department>>& filters);
    void refresh();
};

#endif // !DEPARTMENT_TABLE_MODEL_H
