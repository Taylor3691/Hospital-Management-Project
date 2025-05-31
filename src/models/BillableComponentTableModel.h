#ifndef BILLABLE_COMPONENT_TABLE_MODEL_H
#define BILLABLE_COMPONENT_TABLE_MODEL_H

#include "TableModel.h"
#include "ClinicalTest.h"
#include "MedicineUsage.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class BillableComponentTableModel: public TableModel {
    Q_OBJECT

private:
    std::vector<std::unique_ptr<BillableComponent>> _data;

public:
    explicit BillableComponentTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void setData(const std::vector<const BillableComponent*>& data);
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !BILLABLE_COMPONENT_TABLE_MODEL_H
