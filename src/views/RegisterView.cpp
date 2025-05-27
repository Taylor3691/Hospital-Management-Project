#include "RegisterView.h"

RegisterView::RegisterView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::RegisterView)
    , _service(std::make_unique<RegistrationService>(
        ServiceLocator::getInstance()->patients(),
        ServiceLocator::getInstance()->records(),
        ServiceLocator::getInstance()->rooms()))
{
    setup();
    setConnections();
}

RegisterView::~RegisterView() {
    delete _ui;
}

void RegisterView::setup() {
    _ui->setupUi(this);

    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Đăng ký");

    setupRooms();
}

void RegisterView::setConnections() {
    connect(_ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this,
        [this](bool) {
            auto patient = createPatient();
            if (_ui->insurance_checkBox->isChecked()) {
                patient->setInsuranceCard(createInsurance());
            }
            auto record = _service->createMedicalRecord(patient);
            assignRooms(record);

            notify(
                "Kết quả đăng ký",
                "Bạn đã đăng ký thành công!"
            );
        });
}

void RegisterView::setupRooms() {
    auto rooms = ServiceLocator::getInstance()->rooms()->data();
    for (int i = 0; i < rooms.size(); ++i) {
        auto frame = new QFrame(_ui->room_frame);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setMaximumSize(QSize(145, 175));

        auto verticalLayout = new QVBoxLayout(frame);

        auto room_title = new QCheckBox(frame);
        room_title->setStyleSheet("font-size: 10pt; font-weight: bold;");
        room_title->setText(QString("Phòng %1").arg(i + 1));
        room_title->setProperty("roomId", rooms[i]->id().c_str());

        verticalLayout->addWidget(room_title);

        auto room_name_label = new QLabel(frame);
        room_name_label->setAlignment(Qt::AlignCenter);
        room_name_label->setWordWrap(1);
        room_name_label->setText(QString::fromStdString(rooms[i]->name()));

        verticalLayout->addWidget(room_name_label);

        auto waitings_label = new QLabel(frame);
        waitings_label->setAlignment(Qt::AlignCenter);
        waitings_label->setText(QString("Số lượt chờ: %1").arg(rooms[i]->getQueueCount()));

        verticalLayout->addWidget(waitings_label);

        qobject_cast<QGridLayout*>(_ui->room_frame->layout())->addWidget(frame, 0, i, 1, 1);
    }
}

Patient* RegisterView::createPatient() const {
    auto dob = _ui->dob_dateEdit->date();

    auto symptoms = _ui->symptoms_plainTextEdit->toPlainText();
    std::vector<std::string> symptomList;
    for (const auto& symptom : symptoms.split(',', Qt::SkipEmptyParts)) {
        symptomList.push_back(symptom.toStdString());
    }

    return _service->createPatient(
        _ui->id_lineEdit->text().toStdString(),
        _ui->name_lineEdit->text().toStdString(),
        _ui->gender_comboBox->currentText().toStdString(),
        _ui->address_lineEdit->text().toStdString(),
        _ui->phone_lineEdit->text().toStdString(),
        Date(dob.day(), dob.month(), dob.year()),
        symptomList
    );
}

std::unique_ptr<HealthInsurance> RegisterView::createInsurance() const {
    auto issueDate = _ui->issueDate_dateEdit->date();
    auto expiryDate = _ui->expiryDate_dateEdit->date();

    return std::make_unique<HealthInsurance>(
        _ui->cardId_lineEdit->text().toStdString(),
        Date(issueDate.day(), issueDate.month(), issueDate.year()),
        Date(expiryDate.day(), expiryDate.month(), expiryDate.year()),
        _ui->coveragePercent_doubleSpinBox->value()
    );
}

void RegisterView::assignRooms(MedicalRecord* record) const {
    std::string roomId;
    for (const auto checkBox : _ui->room_frame->findChildren<QCheckBox*>()) {
        if (checkBox->isChecked()) {
            roomId = checkBox->property("roomId").toString().toStdString();
            _service->assignRoom(roomId, record);
        }
    }
}
