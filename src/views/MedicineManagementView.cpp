#include "MedicineManagementView.h"

MedicineManagementView::MedicineManagementView(
    const QString& styleSheet,
    Role role,
    QWidget* parent
)
    : QDialog(parent)
    , _ui(new Ui::MedicineManagementView)
{
    setup(styleSheet, role);
}

MedicineManagementView::~MedicineManagementView() {
    delete _ui;
}

void MedicineManagementView::setup(const QString& styleSheet, Role role) {
    _ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::Sheet);
    setStyleSheet(styleSheet);

    _ui->buttonBox->button(QDialogButtonBox::StandardButton::Cancel)->setText("Hủy");

    _ui->id_label->setEnabled(0);
    _ui->id_lineEdit->setEnabled(0);

    if (role == Role::Add) {
        setWindowTitle("Thêm thuốc");
        _ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setText("Thêm");
        _ui->buttonBox->button(QDialogButtonBox::StandardButton::Reset)->setVisible(0);
        _ui->price_comboBox->setVisible(0);
        _ui->quantity_comboBox->setVisible(0);

        auto data = ServiceLocator::getInstance()->medicines()->data();
        std::vector<const Object*> objectData(data.begin(), data.end());
        auto newId = createId(objectData, getFormat<Medicine>());
        _ui->id_lineEdit->setText(QString::fromStdString(newId));
    }
    else if (role == Role::Update) {
        setWindowTitle("Cập nhật thông tin");
        _ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setText("Lưu");
        _ui->buttonBox->button(QDialogButtonBox::StandardButton::Reset)->setVisible(0);
        _ui->price_comboBox->setVisible(0);
        _ui->quantity_comboBox->setVisible(0);
    }
    else if (role == Role::Filter) {
        setWindowTitle("Lọc thuốc");
        resize(450, 450);
        _ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setText("Lọc");
        _ui->buttonBox->button(QDialogButtonBox::StandardButton::Reset)->setText("Đặt lại");

        connect(_ui->buttonBox->button(QDialogButtonBox::StandardButton::Reset), &QPushButton::clicked, this,
            [this](bool) {
                _ui->id_lineEdit->setText("");
                _ui->name_lineEdit->setText("");
                _ui->unit_lineEdit->setText("");
                _ui->price_doubleSpinBox->setValue(0.0);
                _ui->price_comboBox->setCurrentIndex(0);
                _ui->quantity_spinBox->setValue(0);
                _ui->quantity_comboBox->setCurrentIndex(0);
            });
    }
}

std::unique_ptr<Medicine> MedicineManagementView::getMedicine() const {
    auto medicine = std::make_unique<Medicine>();

    medicine->setId(_ui->id_lineEdit->text().toStdString());
    medicine->setName(_ui->name_lineEdit->text().toStdString());
    medicine->setUnit(_ui->unit_lineEdit->text().toStdString());
    medicine->setPricePerUnit(_ui->price_doubleSpinBox->value());
    medicine->setQuantity(_ui->quantity_spinBox->value());

    return std::move(medicine);
}

void MedicineManagementView::setMedicine(const Medicine* medicine) {
    if (!medicine) {
        return;
    }

    _ui->id_lineEdit->setText(QString::fromStdString(medicine->id()));
    _ui->name_lineEdit->setText(QString::fromStdString(medicine->name()));
    _ui->unit_lineEdit->setText(QString::fromStdString(medicine->unit()));
    _ui->price_doubleSpinBox->setValue(medicine->pricePerUnit());
    _ui->quantity_spinBox->setValue(medicine->quantity());
}

std::vector<RFilter<Medicine>> MedicineManagementView::getFilters() const {
    std::vector<RFilter<Medicine>> filters;

    auto id = _ui->id_lineEdit->text().toStdString();
    if (id != "") {
        FilterCriteria criteria;
        criteria.value = id;
        filters.push_back({ criteria, &Medicine::id });
    }

    auto name = _ui->name_lineEdit->text().toStdString();
    if (name != "") {
        FilterCriteria criteria;
        criteria.value = name;
        filters.push_back({ criteria, &Medicine::name });
    }

    auto unit = _ui->unit_lineEdit->text().toStdString();
    if (unit != "") {
        FilterCriteria criteria;
        criteria.value = unit;
        filters.push_back({ criteria, &Medicine::unit });
    }

    auto price = _ui->price_doubleSpinBox->value();
    if (price) {
        FilterCriteria criteria;
        criteria.value = price;
        filters.push_back({ criteria, &Medicine::pricePerUnit });
    }

    auto quantity = _ui->quantity_spinBox->value();
    if (quantity) {
        FilterCriteria criteria;
        criteria.value = quantity;
        filters.push_back({ criteria, &Medicine::quantity });
    }

    return filters;
}
