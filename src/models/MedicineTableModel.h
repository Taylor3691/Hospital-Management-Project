#ifndef MEDICINE_TABLE_MODEL_H
#define MEDICINE_TABLE_MODEL_H

#include "TableModel.h"
#include "Medicine.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class MedicineTableModel : public TableModel {
    Q_OBJECT

private:
    QVector<const Medicine*> _cachedData;

public:
    explicit MedicineTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void add(std::unique_ptr<Medicine> department);
    void update(const Medicine& department);
    void removeByIds(const std::vector<std::string>& ids);
    void find(const std::vector<RFilter<Medicine>>& filters);
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !MEDICINE_TABLE_MODEL_H
