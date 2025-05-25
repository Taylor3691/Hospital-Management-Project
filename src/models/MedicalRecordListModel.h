#include <QAbstractListModel>

class MedicalRecordListModel : public QAbstractListModel {
private:
    QVector<QString> _items;

public:
    MedicalRecordListModel(QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};
