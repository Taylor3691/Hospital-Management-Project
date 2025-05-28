#ifndef RECEIPT_VIEW_H
#define RECEIPT_VIEW_H

#include <QPushButton>
#include "ui_ReceiptView.h"
#include "../ServiceLocator.h"

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
};

#endif // !RECEIPT_VIEW_H
