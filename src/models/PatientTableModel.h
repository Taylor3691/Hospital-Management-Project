#ifndef PATIENT_TABLE_MODEL_H
#define PATIENT_TABLE_MODEL_H

#include "TableModel.h"
#include "Patient.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class PatientTableModel : public TableModel {
    Q_OBJECT

private:
    QVector<const Patient*> _cachedData;

public:
    explicit PatientTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void add(std::unique_ptr<Patient> patient);
    void update(const Patient& patient);
    void removeByIds(const std::vector<std::string>& ids);
    void find(const std::vector<RFilter<Patient>>& filters);
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !PATIENT_TABLE_MODEL_H
