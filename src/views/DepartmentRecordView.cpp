#include "DepartmentRecordView.h"

DepartmentRecordView::DepartmentRecordView(Role role, QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::DepartmentRecordView)
{
    _ui->setupUi(this);

    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Hủy");

    _ui->id_label->setEnabled(0);
    _ui->id_lineEdit->setEnabled(0);

    if (role == Role::Add) {
        setWindowTitle("Thêm khoa");
        _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Thêm");

        auto data = ServiceLocator::instance()->departmentRepository()->data();
        std::vector<const Object*> objectData(data.begin(), data.end());
        auto newId = createId(objectData, getFormat<Department>());
        _ui->id_lineEdit->setText(QString::fromStdString(newId));
    }
    else if (role == Role::Update) {
        setWindowTitle("Cập nhật thông tin");
        _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Lưu");
    }

    setStyleSheet("");
}

DepartmentRecordView::~DepartmentRecordView() {
    delete _ui;
}

std::unique_ptr<Department> DepartmentRecordView::getDepartment() const {
    auto department = std::make_unique<Department>();

    department->setId(_ui->id_lineEdit->text().toStdString());
    department->setName(_ui->name_lineEdit->text().toStdString());
    auto date = _ui->foundation_dateEdit->date();
    department->setFoundationDate({ date.day(), date.month(), date.year() });
    department->setDescription(_ui->description_plainTextEdit
        ->toPlainText().toStdString());
    department->setHeadId(_ui->head_lineEdit->text().toStdString());

    return std::move(department);
}

void DepartmentRecordView::setDepartment(const Department* department) {
    if (!department) {
        return;
    }

    _ui->id_lineEdit->setText(QString::fromStdString(department->id()));
    _ui->name_lineEdit->setText(QString::fromStdString(department->name()));
    auto foundationDate = department->foundationDate();
    _ui->foundation_dateEdit->setDate(
        { foundationDate.year(), foundationDate.month(), foundationDate.day() });
    _ui->description_plainTextEdit
        ->setPlainText(QString::fromStdString(department->description()));
    _ui->head_lineEdit->setText(QString::fromStdString(department->headId()));
}
