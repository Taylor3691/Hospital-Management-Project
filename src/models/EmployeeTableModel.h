#ifndef EMPLOYEE_TABLE_MODEL_H
#define EMPLOYEE_TABLE_MODEL_H

#include "TableModel.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Receptionist.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class EmployeeTableModel : public TableModel {
    Q_OBJECT

private:
    QVector<const Employee*> _cachedData;

public:
    explicit EmployeeTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void add(std::unique_ptr<Employee> employee);
    void update(const Employee& employee);
    void removeByIds(const std::vector<std::string>& ids);
    void find(const std::vector<RFilter<Employee>>& filters);
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !EMPLOYEE_TABLE_MODEL_H
