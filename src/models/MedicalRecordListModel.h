#ifndef MEDICAL_RECORD_LIST_MODEL_H
#define MEDICAL_RECORD_LIST_MODEL_H

#include <QAbstractListModel>
#include "../ServiceLocator.h"
#include "../utils/QueryBuilder.h"

class MedicalRecordListModel : public QAbstractListModel {
    Q_OBJECT

private:
    QVector<std::string> _data;

public:
    MedicalRecordListModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void setData(const std::vector<const MedicalRecord*>& data);
    void setData(const std::vector<std::unique_ptr<MedicalRecord>>& data);
    void refresh();
};

#endif // !MEDICAL_RECORD_LIST_MODEL_H
