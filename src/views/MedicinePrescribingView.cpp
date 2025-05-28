#include "MedicinePrescribingView.h"

MedicinePrescribingView::MedicinePrescribingView(QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::MedicinePrescribingView)
{
    _ui->setupUi(this);
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Thêm");
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Hủy");

    setWindowTitle("Kê thuốc");
    setStyleSheet("");
}

MedicinePrescribingView::~MedicinePrescribingView() {
    delete _ui;
}
