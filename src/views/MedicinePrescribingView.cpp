#include "MedicinePrescribingView.h"

MedicinePrescribingView::MedicinePrescribingView(QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::MedicinePrescribingView)
{
    _ui->setupUi(this);
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Thêm");
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Hủy");

    auto model = new MedicineTableModel(_ui->id_comboBox);
    auto view = new QTableView(_ui->id_comboBox);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSortingEnabled(1);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    view->verticalHeader()->hide();
    view->setModel(model);
    _ui->id_comboBox->setModel(model);
    _ui->id_comboBox->setView(view);
    _ui->id_comboBox->setCurrentIndex(-1);

    setWindowTitle("Kê thuốc");
    setStyleSheet("");
    setConnections();
}

MedicinePrescribingView::~MedicinePrescribingView() {
    delete _ui;
}

void MedicinePrescribingView::setConnections() {
    connect(_ui->id_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
        [this](int index) {
            _ui->name_lineEdit->setText(
                _ui->id_comboBox->model()->index(index, 1)
                .data(Qt::DisplayRole).toString());
            _ui->price_doubleSpinBox->setValue(
                _ui->id_comboBox->model()->index(index, 3)
                .data(Qt::DisplayRole).toDouble());
        });
}

std::unique_ptr<MedicineUsage> MedicinePrescribingView::getUsage() {
    return ServiceLocator::instance()->examinationService()->createMedicineUsage(
        _ui->id_comboBox->currentText().toStdString(),
        _ui->name_lineEdit->text().toStdString(),
        _ui->quantity_spinBox->value(),
        _ui->price_doubleSpinBox->value(),
        _ui->description_lineEdit->text().toStdString()
    );
}
