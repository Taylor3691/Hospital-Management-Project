#ifndef PATIENT_TABLE_MODEL_H
#define PATIENT_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QVector>
#include "../ServiceLocator.h"
#include "Patient.h"
#include "../utils/utils_template.h"

class PatientTableModel : public QAbstractTableModel {
    Q_OBJECT

private:
    QVector<QString> _headers;
    QVector<const Patient*> _cachedData;

public:
    explicit PatientTableModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;
    void add(std::unique_ptr<Patient> patient);
    void update(const Patient& patient);
    void removeByIds(const std::vector<std::string>& ids);
    void find(const std::vector<RFilter<Patient>>& filters);
    void refresh();
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
};

#endif // !PATIENT_TABLE_MODEL_H
