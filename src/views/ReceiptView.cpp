#include "ReceiptView.h"

ReceiptView::ReceiptView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ReceiptView)
{
    setup();
    setConnections();
}

ReceiptView::~ReceiptView() {
    delete _ui;
}

void ReceiptView::setup() {
    _ui->setupUi(this);

    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Thanh toán");
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet(
        "padding-left: 10px; padding-right: 10px;");
}

void ReceiptView::setConnections() {

}
