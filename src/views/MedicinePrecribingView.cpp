#include "MedicinePrecribingView.h"

MedicinePrecribingView::MedicinePrecribingView(const QString& styleSheet, QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::MedicinePrecribingView)
{
    setup(styleSheet);
    setConnections();
}

MedicinePrecribingView::~MedicinePrecribingView() {
    delete _ui;
}

void MedicinePrecribingView::setup(const QString& styleSheet) {
    _ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::Sheet);
    setStyleSheet(styleSheet);
    setWindowTitle("Kê thuốc");

    _ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setText("Thêm");
    _ui->buttonBox->button(QDialogButtonBox::StandardButton::Cancel)->setText("Hủy");
}

void MedicinePrecribingView::setConnections() {
    
}
