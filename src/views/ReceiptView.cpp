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

    //_ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Đăng ký");
}

void ReceiptView::setConnections() {

}
