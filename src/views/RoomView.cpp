#include "RoomView.h"

RoomView::RoomView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::RoomView)
{
    setup();
    setConnections();
}

RoomView::~RoomView() {
    delete _ui;
}

void RoomView::setup() {
    _ui->setupUi(this);
    _ui->record_listView->setModel(new MedicalRecordListModel(this));
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Kết thúc khám");
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet(
        "padding-left: 10px; padding-right: 10px;");
    _ui->precribedDate_dateEdit->setDate(QDate::currentDate());

    createCompleter();

    /*auto& comboBox = _ui->quickSpecify_comboBox;
    auto tableView = new QTableView(comboBox);
    auto model = new PatientTableModel(this);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->verticalHeader()->hide();
    tableView->setModel(model);
    comboBox->setView(tableView);
    comboBox->setModel(model);*/
}

void RoomView::setConnections() {
    connect(_ui->record_listView, &QListView::clicked, this,
        [this](const QModelIndex& index) {
            _ui->recordId_label->setText(index.data().toString());
        });

    connect(_ui->doctorName_lineEdit, &QLineEdit::textChanged, this,
        [this](const QString& text) {
            _ui->precribingDoctorName_lineEdit->setText(text);
        });

    connect(_ui->quickPrecribe_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            MedicinePrecribingView view(qApp->styleSheet());
            QString title = "Xác nhận thêm thuốc";
            QString msg = "Bạn có chắc chắn muốn thêm thuốc?";
            if (view.exec() == QDialog::DialogCode::Accepted && confirm(title, msg)) {
                
            }
        });
}

void RoomView::createCompleter() {
    QStringList doctorNames;
    for (const auto& employee : ServiceLocator::getInstance()->employeeRepository()->data()) {
        if (auto doctor = dynamic_cast<const Doctor*>(employee)) {
            doctorNames << QString::fromStdString(doctor->name());
        }
    }

    QCompleter* completer = new QCompleter(doctorNames, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    _ui->doctorName_lineEdit->setCompleter(completer);
}

void RoomView::changeRoom(int index) {
    auto room = ServiceLocator::getInstance()->roomExaminationRepository()->data()[index];
    _ui->id_label->setText(QString::fromStdString(room->id()));
    _ui->name_label->setText(QString::fromStdString(room->name()));
}
