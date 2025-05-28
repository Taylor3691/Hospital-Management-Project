#include "ParaclinicalView.h"

ParaclinicalView::ParaclinicalView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ParaclinicalView)
{
    _ui->setupUi(this);
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Xong");

    setStyleSheet("");
    setConnections();
}

ParaclinicalView::~ParaclinicalView() {
    delete _ui;
}

void ParaclinicalView::setConnections() {

}
