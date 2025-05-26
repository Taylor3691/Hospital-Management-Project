#ifndef MEDICAL_RECORD_LIST_MODEL_H
#define MEDICAL_RECORD_LIST_MODEL_H

#include <QAbstractListModel>

class MedicalRecordListModel : public QAbstractListModel {
    Q_OBJECT

private:
    QVector<QString> _items;

public:
    MedicalRecordListModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};

#endif // !MEDICAL_RECORD_LIST_MODEL_H
