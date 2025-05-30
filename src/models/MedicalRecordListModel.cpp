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

    if (role == Qt::DisplayRole) {
        return _data[index.row()].c_str();
    }

    return {};
}

void MedicalRecordListModel::setData(const QVector<const MedicalRecord*>& data) {
    beginResetModel();
    _data.clear();
    for (const auto& record : data) {
        _data.push_back(record->id());
    }
    endResetModel();
}

void MedicalRecordListModel::refresh() {
    beginResetModel();
    auto data = ServiceLocator::instance()
        ->medicalRecordRepository()->data();
    _data.clear();
    for (const auto& record : data) {
        _data.push_back(record->id());
    }
    endResetModel();
}
