#include "MedicalRecordListModel.h"

MedicalRecordListModel::MedicalRecordListModel(QObject* parent)
    : QAbstractListModel(parent) {}

int MedicalRecordListModel::rowCount(const QModelIndex& parent) const {
    return _data.size();
}

QVariant MedicalRecordListModel::data(
    const QModelIndex& index,
    int role
) const {
    if (!index.isValid()) {
        return {};
    }

    if (role == Qt::UserRole) {
        return QVariant::fromValue(
            const_cast<void*>(static_cast<const void*>(_data[index.row()])));
    }

    if (role == Qt::DisplayRole) {
        return _data[index.row()]->id().c_str();
    }

    return {};
}

void MedicalRecordListModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::getInstance()
        ->medicalRecordRepository()->data();
    _data = QVector<const MedicalRecord*>(data.begin(), data.end());
    endResetModel();
}

void MedicalRecordListModel::changeFilter(const std::string& roomId) {
    beginResetModel();
    auto data = ServiceLocator::getInstance()
        ->medicalRecordRepository()->data();
    auto results = from(data)
        .where(&MedicalRecord::roomId, roomId)
        .find();
    _data = QVector<const MedicalRecord*>(results.begin(), results.end());
    endResetModel();
}
