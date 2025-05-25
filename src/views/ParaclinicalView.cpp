#include "ParaclinicalView.h"

ParaclinicalView::ParaclinicalView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::ParaclinicalView)
{
    setup();
    setConnections();
}

ParaclinicalView::~ParaclinicalView() {
    delete _ui;
}

void ParaclinicalView::setup() {
    _ui->setupUi(this);
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Xong");
}

void ParaclinicalView::setConnections() {

}
