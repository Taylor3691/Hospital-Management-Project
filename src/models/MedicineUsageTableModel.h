#ifndef MEDICINE_USAGE_TABLE_MODEL_H
#define MEDICINE_USAGE_TABLE_MODEL_H

#include "TableModel.h"
#include "MedicineUsage.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class MedicineUsageTableModel : public TableModel {
    Q_OBJECT

private:
    QVector<const MedicineUsage*> _data;

public:
    explicit MedicineUsageTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void setData(const QVector<const MedicineUsage*>& data);
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !MEDICINE_USAGE_TABLE_MODEL_H
