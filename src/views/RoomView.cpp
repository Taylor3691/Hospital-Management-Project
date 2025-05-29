#include "RoomView.h"
#include "SelectingView.h"

RoomView::RoomView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::RoomView)
{
    _ui->setupUi(this);

    _ui->record_listView->setModel(new MedicalRecordListModel(this));

    _ui->recordId_label->setText("Vui lòng chọn một hồ sơ để tiếp tục!");
    _ui->examinationSection_frame->setEnabled(0);

    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Kết thúc khám");
    _ui->buttonBox->button(QDialogButtonBox::Ok)
        ->setStyleSheet("padding-left: 10px; padding-right: 10px;");

    _ui->prescribedDate_dateEdit->setDate(QDate::currentDate());

    _ui->specifiedTests_tableView
        ->setModel(new TestServiceTableModel(Role::Display, this));
    _ui->specifiedTests_tableView->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::ResizeToContents);
    _ui->specifiedTests_tableView->verticalHeader()
        ->setStyleSheet("QHeaderView::section { padding-right: 10px; }");

    setStyleSheet("");
    setConnections();
    createCompleter();
}

RoomView::~RoomView() {
    delete _ui;
}

void RoomView::setConnections() {
    connect(_ui->record_listView, &QListView::clicked, this,
        [this](const QModelIndex& index) {
            _ui->recordId_label->setText(index.data().toString());
            _ui->examinationSection_frame->setEnabled(1);
        });

    connect(_ui->doctorName_lineEdit, &QLineEdit::textChanged, this,
        [this](const QString& text) {
            _ui->prescribingDoctorName_lineEdit->setText(text);
        });

    connect(_ui->quickSpecify_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            TestServiceTableModel model;
            SelectingView view;
            view.setModel(&model);

            connect(&model, &QAbstractTableModel::dataChanged,
                static_cast<TableModel*>(_ui->specifiedTests_tableView->model()),
                &TableModel::refresh);

            connect(&model, &QAbstractTableModel::modelReset,
                static_cast<TableModel*>(_ui->specifiedTests_tableView->model()),
                &TableModel::refresh);

            view.exec();
        });

    connect(_ui->quickPrescribe_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            MedicinePrescribingView view;
            QString title = "Xác nhận thêm thuốc";
            QString msg = "Bạn có chắc chắn muốn thêm thuốc?";
            if (view.exec() == QDialog::Accepted && confirm(title, msg)) {
                
            }
        });
}

void RoomView::createCompleter() {
    QStringList doctorNames;
    auto repo = ServiceLocator::getInstance()->employeeRepository();
    for (const auto& employee : repo->data()) {
        if (auto doctor = dynamic_cast<const Doctor*>(employee)) {
            doctorNames << QString::fromStdString(doctor->name());
        }
    }

    QCompleter* completer = new QCompleter(doctorNames, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    _ui->doctorName_lineEdit->setCompleter(completer);
}

void RoomView::changeRoom(int index) {
    auto room = ServiceLocator::getInstance()
        ->roomExaminationRepository()->data()[index];
    _ui->id_label->setText(QString::fromStdString(room->id()));
    _ui->name_label->setText(QString::fromStdString(room->name()));
    static_cast<MedicalRecordListModel*>(_ui->record_listView->model())
        ->changeFilter(room->id());
}
