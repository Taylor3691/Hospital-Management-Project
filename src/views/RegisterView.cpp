#include "RegisterView.h"

RegisterView::RegisterView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::RegisterView)
    , _roomButtonGroup(new QButtonGroup(this))
{
    _ui->setupUi(this);
    _ui->id_label->setEnabled(0);
    _ui->id_lineEdit->setEnabled(0);
    _ui->dob_dateEdit->setDate(QDate::currentDate());
    _ui->issueDate_dateEdit->setDate(QDate::currentDate());
    _ui->expiryDate_dateEdit->setDate(QDate::currentDate());
    _ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Đăng ký");

    auto data = ServiceLocator::instance()->patientRepository()->data();
    auto objData = std::vector<const Object*>(data.begin(), data.end());
    auto patientId = createId(objData, getFormat<Patient>());
    _ui->id_lineEdit->setText(QString::fromStdString(patientId));

    setStyleSheet("");
    setConnections();
    setupRooms();
}

RegisterView::~RegisterView() {
    delete _ui;
}

void RegisterView::setConnections() {
    connect(_ui->buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this,
        [this](bool) {
            if (!checkValid()) {
                return;
            }

            auto insurance = createInsurance();
            auto patient = createPatient(std::move(insurance));
            auto roomId = _roomButtonGroup->checkedButton()
                ->property("roomId").toString().toStdString();
            auto record = ServiceLocator::instance()->registrationService()
                ->createMedicalRecord(patient, roomId);

            updateRoomInfo();
            notify("Kết quả đăng ký", "Bạn đã đăng ký thành công!");
            resetInputs();
        });
}

void RegisterView::setupRooms() {
    auto rooms = ServiceLocator::instance()->roomExaminationRepository()->data();
    for (int i = 0; i < rooms.size(); ++i) {
        auto frame = new QFrame(_ui->room_frame);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setMaximumSize(QSize(145, 175));

        auto verticalLayout = new QVBoxLayout(frame);

        auto room_title = new QPushButton(frame);
        room_title->setCheckable(1);
        room_title->setStyleSheet(
            "font-size: 10pt; font-weight: bold; padding: 5px;");
        room_title->setText(QString("Phòng %1").arg(i + 1));
        room_title->setProperty("roomId", rooms[i]->id().c_str());

        verticalLayout->addWidget(room_title);
        _roomButtonGroup->addButton(room_title);

        auto room_name_label = new QLabel(frame);
        room_name_label->setAlignment(Qt::AlignCenter);
        room_name_label->setWordWrap(1);
        room_name_label->setText(QString::fromStdString(rooms[i]->name()));

        verticalLayout->addWidget(room_name_label);

        auto waitings_label = new QLabel(frame);
        waitings_label->setAlignment(Qt::AlignCenter);
        waitings_label->setText(QString("Số lượt chờ: %1").arg(rooms[i]->waitingCount()));

        verticalLayout->addWidget(waitings_label);

        qobject_cast<QGridLayout*>(_ui->room_frame->layout())->addWidget(frame, 0, i, 1, 1);
    }
}

bool RegisterView::checkValid() {
    // TODO: Validate Patient and HealthInsurance infos

    if (!_ui->symptoms_plainTextEdit->toPlainText().length()) {
        warn("Triệu chứng không thể để trống!");
        return false;
    }

    if (!_roomButtonGroup->checkedButton()) {
        warn("Vui lòng chọn phòng!");
        return false;
    }

    return true;
}

Patient* RegisterView::createPatient(std::unique_ptr<HealthInsurance> insurance) const {
    auto dob = _ui->dob_dateEdit->date();

    auto symptoms = _ui->symptoms_plainTextEdit->toPlainText();
    std::vector<std::string> symptomList;
    for (const auto& symptom : symptoms.split(',', Qt::SkipEmptyParts)) {
        auto trimmed = symptom.trimmed();
        if (trimmed.size()) {
            symptomList.push_back(trimmed.toStdString());
        }
    }

    return ServiceLocator::instance()->registrationService()->createPatient(
        _ui->id_lineEdit->text().toStdString(),
        _ui->name_lineEdit->text().toStdString(),
        _ui->gender_comboBox->currentText().toStdString(),
        _ui->address_lineEdit->text().toStdString(),
        _ui->phone_lineEdit->text().toStdString(),
        Date(dob.day(), dob.month(), dob.year()),
        symptomList,
        std::move(insurance)
    );
}

std::unique_ptr<HealthInsurance> RegisterView::createInsurance() const {
    if (!_ui->insurance_checkBox->isChecked()) {
        return nullptr;
    }

    auto issueDate = _ui->issueDate_dateEdit->date();
    auto expiryDate = _ui->expiryDate_dateEdit->date();

    return std::make_unique<HealthInsurance>(
        _ui->cardId_lineEdit->text().toStdString(),
        Date(issueDate.day(), issueDate.month(), issueDate.year()),
        Date(expiryDate.day(), expiryDate.month(), expiryDate.year()),
        _ui->coveragePercent_doubleSpinBox->value()
    );
}

void RegisterView::resetInputs() {
    auto data = ServiceLocator::instance()->patientRepository()->data();
    auto objData = std::vector<const Object*>(data.begin(), data.end());
    auto patientId = createId(objData, getFormat<Patient>());
    _ui->id_lineEdit->setText(QString::fromStdString(patientId));

    _ui->name_lineEdit->clear();
    _ui->gender_comboBox->setCurrentIndex(0);
    _ui->address_lineEdit->clear();
    _ui->phone_lineEdit->clear();
    _ui->dob_dateEdit->setDate(QDate::currentDate());
    _ui->symptoms_plainTextEdit->clear();

    _ui->insurance_checkBox->setChecked(1);
    _ui->insuranceInfo_groupBox->setEnabled(1);
    _ui->cardId_lineEdit->clear();
    _ui->issueDate_dateEdit->setDate(QDate::currentDate());
    _ui->expiryDate_dateEdit->setDate(QDate::currentDate());
    _ui->coveragePercent_doubleSpinBox->setValue(0.0);

    if (auto checkedButton = _roomButtonGroup->checkedButton()) {
        _roomButtonGroup->setExclusive(0);
        checkedButton->setChecked(0);
        _roomButtonGroup->setExclusive(1);
    }
}

void RegisterView::updateRoomInfo() {
    for (const auto& button : _roomButtonGroup->buttons()) {
        auto roomId = button->property("roomId").toString().toStdString();
        auto room = ServiceLocator::instance()
            ->registrationService()->findRoomById(roomId);
        static_cast<QLabel*>(button->parentWidget()->layout()->itemAt(2)->widget())
            ->setText(QString("Số lượt chờ: %1").arg(room->waitingCount()));
    }
}
