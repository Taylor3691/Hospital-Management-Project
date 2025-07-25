#include "PatientFilteringView.h"

PatientFilteringView::PatientFilteringView(QWidget* parent)
    : QDialog(parent)
    , _ui(new Ui::PatientFilteringView)
{
    _ui->setupUi(this);
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Lọc");
    _ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Hủy");
    _ui->buttonBox->button(QDialogButtonBox::Reset)->setText("Đặt lại");

    setWindowTitle("Lọc bệnh nhân");
    setStyleSheet("");
    setConnections();
}

PatientFilteringView::~PatientFilteringView() {
    delete _ui;
}

void PatientFilteringView::setConnections() {
    connect(_ui->buttonBox->button(QDialogButtonBox::Reset), &QPushButton::clicked, this,
        [this](bool) {
            _ui->id_lineEdit->setText("");
            _ui->name_lineEdit->setText("");
            _ui->address_lineEdit->setText("");
            _ui->phone_lineEdit->setText("");
            _ui->dob_dateEdit->setDate({ 1900, 1, 1 });
            _ui->dob_comboBox->setCurrentIndex(0);
        });
}

std::vector<RFilter<Patient>> PatientFilteringView::getFilters() const {
    std::vector<RFilter<Patient>> filters;

    auto id = _ui->id_lineEdit->text().toStdString();
    if (id != "") {
        FilterCriteria criteria;
        criteria.value = id;
        filters.push_back({ criteria, &Patient::id });
    }

    auto name = _ui->name_lineEdit->text().toStdString();
    if (name != "") {
        FilterCriteria criteria;
        criteria.value = name;
        filters.push_back({ criteria, &Patient::name });
    }

    auto address = _ui->address_lineEdit->text().toStdString();
    if (address != "") {
        FilterCriteria criteria;
        criteria.value = address;
        filters.push_back({ criteria, &Patient::address });
    }

    auto phone = _ui->phone_lineEdit->text().toStdString();
    if (phone != "") {
        FilterCriteria criteria;
        criteria.value = phone;
        filters.push_back({ criteria, &Patient::phone });
    }

    auto date = _ui->dob_dateEdit->date();
    if (date != QDate(1900, 1, 1)) {
        FilterCriteria criteria;
        criteria.value = Date(date.day(), date.month(), date.year());
        criteria.op = (ComparisonOperator)_ui->dob_comboBox->currentIndex();
        filters.push_back({ criteria, &Patient::dob });
    }

    return filters;
}
