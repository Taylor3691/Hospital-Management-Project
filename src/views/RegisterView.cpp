#include "RegisterView.h"

RegisterView::RegisterView(QWidget* parent)
    : QWidget(parent)
    , _ui(new Ui::RegisterView)
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

}

void RegisterView::setupRooms() {
    auto& rooms = ServiceLocator::rooms();
    for (int i = 0; i < rooms.size(); ++i) {
        auto frame = new QFrame(_ui->room_frame);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setMaximumSize(QSize(145, 175));

        auto verticalLayout = new QVBoxLayout(frame);

        auto room_title = new QCheckBox(frame);
        room_title->setStyleSheet("font-size: 10pt; font-weight: bold;");
        room_title->setText(QString("Phòng %1").arg(i + 1));

        verticalLayout->addWidget(room_title);

        auto room_name_label = new QLabel(frame);
        room_name_label->setAlignment(Qt::AlignCenter);
        room_name_label->setWordWrap(1);
        room_name_label->setText(QString::fromStdString(rooms[i].name));

        verticalLayout->addWidget(room_name_label);

        auto waitings_label = new QLabel(frame);
        waitings_label->setAlignment(Qt::AlignCenter);
        waitings_label->setText(QString("Số lượt chờ: %1").arg(rooms[i].waitings));

        verticalLayout->addWidget(waitings_label);

        qobject_cast<QGridLayout*>(_ui->room_frame->layout())->addWidget(frame, 0, i, 1, 1);
    }
}
