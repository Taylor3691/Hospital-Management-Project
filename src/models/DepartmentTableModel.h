#ifndef DEPARTMENT_TABLE_MODEL_H
#define DEPARTMENT_TABLE_MODEL_H

#include "TableModel.h"
#include "Department.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class DepartmentTableModel : public TableModel {
    Q_OBJECT

private:
    QVector<const Department*> _cachedData;

public:
    explicit DepartmentTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void add(std::unique_ptr<Department> department);
    void update(const Department& department);
    void removeByIds(const std::vector<std::string>& ids);
    void find(const std::vector<RFilter<Department>>& filters);
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !DEPARTMENT_TABLE_MODEL_H
