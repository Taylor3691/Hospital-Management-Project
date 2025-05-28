#include "DepartmentFilteringView.h"

DepartmentFilteringView::DepartmentFilteringView(QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::DepartmentFilteringView)
{
    _ui->setupUi(this);
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Lọc");
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Hủy");
    _ui->buttonBox->button(QDialogButtonBox::Reset)->setText("Đặt lại");

    setWindowTitle("Lọc khoa");
    setStyleSheet("");
    setConnections();
}

DepartmentFilteringView::~DepartmentFilteringView() {
    delete _ui;
}

void DepartmentFilteringView::setConnections() {
    connect(_ui->buttonBox->button(QDialogButtonBox::Reset), &QPushButton::clicked, this,
        [this](bool) {
            _ui->id_lineEdit->setText("");
            _ui->name_lineEdit->setText("");
            _ui->foundation_dateEdit->setDate({1900, 1, 1});
            _ui->foundation_comboBox->setCurrentIndex(0);
        });
}

std::vector<RFilter<Department>> DepartmentFilteringView::getFilters() const {
    std::vector<RFilter<Department>> filters;

    auto id = _ui->id_lineEdit->text().toStdString();
    if (id != "") {
        FilterCriteria criteria;
        criteria.value = id;
        filters.push_back({ criteria, &Department::id });
    }

    auto name = _ui->name_lineEdit->text().toStdString();
    if (name != "") {
        FilterCriteria criteria;
        criteria.value = name;
        filters.push_back({ criteria, &Department::name });
    }

    auto date = _ui->foundation_dateEdit->date();
    if (date != QDate(1900, 1, 1)) {
        FilterCriteria criteria;
        criteria.value = Date(date.day(), date.month(), date.year());
        criteria.op = (ComparisonOperator)_ui->foundation_comboBox->currentIndex();
        filters.push_back({ criteria, &Department::foundationDate });
    }

    return filters;
}
