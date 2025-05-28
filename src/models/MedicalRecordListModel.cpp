#include "MedicalRecordListModel.h"

MedicalRecordListModel::MedicalRecordListModel(QObject* parent)
    : QAbstractListModel(parent) {}

int MedicalRecordListModel::rowCount(const QModelIndex& parent) const {
    return _recordIds.size();
}

QVariant MedicalRecordListModel::data(
    const QModelIndex& index,
    int role
) const {
    if (!index.isValid()) {
        return {};
    }

    if (role == Qt::DisplayRole) {
        return _recordIds[index.row()];
    }

    return {};
}

void MedicalRecordListModel::refresh() {
    beginResetModel();
    _recordIds.clear();
    auto repo = ServiceLocator::getInstance()->medicalRecordRepository();
    for (const auto& record : repo->data()) {
        _recordIds.push_back(QString::fromStdString(record->id()));
    }
    endResetModel();
}

void MedicalRecordListModel::changeFilter(const std::string& roomId) {
    beginResetModel();
    auto data = ServiceLocator::getInstance()
        ->medicalRecordRepository()->data();
    auto results = from(data)
        .where(&MedicalRecord::roomId, roomId)
        .find();
    _recordIds.clear();
    for (const auto& record : results) {
        _recordIds.push_back(QString::fromStdString(record->id()));
    }
    endResetModel();
}
