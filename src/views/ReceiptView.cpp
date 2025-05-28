#include "ReceiptView.h"

ReceiptView::ReceiptView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ReceiptView)
{
    _ui->setupUi(this);

    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Thanh toán");
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet(
        "padding-left: 10px; padding-right: 10px;");

    setStyleSheet("");
    setConnections();
}

ReceiptView::~ReceiptView() {
    delete _ui;
}

void ReceiptView::setConnections() {

}
