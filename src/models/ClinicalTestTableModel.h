#ifndef CLINICAL_TEST_TABLE_MODEL_H
#define CLINICAL_TEST_TABLE_MODEL_H

#include "TableModel.h"
#include "ClinicalTest.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class ClinicalTestTableModel : public TableModel {
    Q_OBJECT

private:
    QVector<const ClinicalTest*> _data;

public:
    explicit ClinicalTestTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void setData(const QVector<const ClinicalTest*>& data);
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !CLINICAL_TEST_TABLE_MODEL_H
