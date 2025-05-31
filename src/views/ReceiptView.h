#ifndef RECEIPT_VIEW_H
#define RECEIPT_VIEW_H

#include <QPushButton>
#include "ui_ReceiptView.h"
#include "../ServiceLocator.h"
#include "../models/MedicalRecordListModel.h"
#include "../models/BillableComponentTableModel.h"
#include "../models/PaidState.h"

namespace Ui {
    class ReceiptView;
}

class ReceiptView : public QWidget {
    Q_OBJECT

private:
    Ui::ReceiptView* _ui;

public:
    explicit ReceiptView(QWidget* parent = nullptr);
    ~ReceiptView();

private:
    void setConnections();
    void triggerRecordFilter();
    void setReceiptInfo(const std::string& recordId);
    void clearReceiptInfo();

public:
    void updateView();
};

#endif // !RECEIPT_VIEW_H
