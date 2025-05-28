#include "EmployeeFilteringView.h"

EmployeeFilteringView::EmployeeFilteringView(QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::EmployeeFilteringView)
{
    _ui->setupUi(this);
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Lọc");
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Hủy");
    _ui->buttonBox->button(QDialogButtonBox::Reset)->setText("Đặt lại");

    setWindowTitle("Lọc nhân viên");
    setStyleSheet("");
    setConnections();
}

EmployeeFilteringView::~EmployeeFilteringView() {
    delete _ui;
}

void EmployeeFilteringView::setConnections() {
    connect(_ui->buttonBox->button(QDialogButtonBox::Reset), &QPushButton::clicked, this,
        [this](bool) {
            _ui->id_lineEdit->setText("");
            _ui->name_lineEdit->setText("");
            _ui->salary_doubleSpinBox->setValue(0.0);
            _ui->salary_comboBox->setCurrentIndex(0);
            _ui->education_comboBox->setCurrentIndex(0);
            _ui->role_comboBox->setCurrentIndex(0);
        });
}

std::vector<RFilter<Employee>> EmployeeFilteringView::getFilters() const {
    std::vector<RFilter<Employee>> filters;

    auto id = _ui->id_lineEdit->text().toStdString();
    if (id != "") {
        FilterCriteria criteria;
        criteria.value = id;
        filters.push_back({ criteria, &Employee::id });
    }

    auto name = _ui->name_lineEdit->text().toStdString();
    if (name != "") {
        FilterCriteria criteria;
        criteria.value = name;
        filters.push_back({ criteria, &Employee::name });
    }

    auto salary = _ui->salary_doubleSpinBox->value();
    if (salary != 0.0) {
        FilterCriteria criteria;
        criteria.value = salary;
        criteria.op = (ComparisonOperator)_ui->salary_comboBox->currentIndex();
        filters.push_back({ criteria, &Employee::baseSalary });
    }

    if (_ui->education_comboBox->currentIndex()) {
        FilterCriteria criteria;
        criteria.value = _ui->education_comboBox->currentText().toStdString();
        filters.push_back({ criteria, &Employee::education });
    }

    std::vector<std::string> roles = {
        std::string(typeid(Doctor).name()),
        std::string(typeid(Nurse).name()),
        std::string(typeid(Receptionist).name()),
    };
    auto index = _ui->role_comboBox->currentIndex();
    if (index) {
        FilterCriteria criteria;
        criteria.value = roles[index - 1];

        Getter<Employee> getter = [](auto& e) {
            return std::string(typeid(e).name());
        };

        filters.push_back({ criteria, getter });
    }

    return filters;
}
