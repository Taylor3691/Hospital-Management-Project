#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QString>

class TableModel : public QAbstractTableModel {
    Q_OBJECT

protected:
    QVector<QString> _headers;

public:
    explicit TableModel(const QVector<QString>& headers, QObject* parent = nullptr);

public:
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;
    virtual void refresh() = 0;
};

#endif // !TABLE_MODEL_H
