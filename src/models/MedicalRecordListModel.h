#ifndef MEDICAL_RECORD_LIST_MODEL_H
#define MEDICAL_RECORD_LIST_MODEL_H

#include <QAbstractListModel>
#include "../ServiceLocator.h"
#include "../utils/QueryBuilder.h"

class MedicalRecordListModel : public QAbstractListModel {
    Q_OBJECT

private:
    QVector<const MedicalRecord*> _data;

public:
    MedicalRecordListModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index,
        int role = Qt::DisplayRole) const override;
    void refresh();
    void changeFilter(const std::string& roomId);
};

#endif // !MEDICAL_RECORD_LIST_MODEL_H
