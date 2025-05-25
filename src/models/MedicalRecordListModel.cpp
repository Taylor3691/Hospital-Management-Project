#include "MedicalRecordListModel.h"

MedicalRecordListModel::MedicalRecordListModel(QObject* parent)
    : QAbstractListModel(parent)
    , _items(
        {
            // Mock data
            "Id hồ sơ 1",
            "Id hồ sơ 2",
            "Id hồ sơ 3",
            "Id hồ sơ 4",
        }) {
}

int MedicalRecordListModel::rowCount(const QModelIndex& parent) const {
    return _items.size();
}

QVariant MedicalRecordListModel::data(
    const QModelIndex& index,
    int role
) const {
    if (!index.isValid()) {
        return {};
    }

    if (role == Qt::DisplayRole) {
        return _items[index.row()];
    }

    return {};
}
