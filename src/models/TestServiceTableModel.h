#ifndef TEST_SERVICE_TABLE_MODEL_H
#define TEST_SERVICE_TABLE_MODEL_H

#include "SelectableTableModel.h"
#include "TestService.h"
#include "../ServiceLocator.h"
#include "../utils/utils_template.h"

class TestServiceTableModel : public SelectableTableModel {
    Q_OBJECT

private:
    QVector<const TestService*> _data;
    QVector<std::string> _selectedTests;

public:
    explicit TestServiceTableModel(
        const QVector<std::string>& selectedTests = {},
        QObject* parent = nullptr);

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    void refresh() override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    void selectAll() override;
    void clearAll() override;
    QVector<std::string> selectedItems();
};

#endif // !TEST_SERVICE_TABLE_MODEL_H
