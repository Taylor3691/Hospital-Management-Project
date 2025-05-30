#include "HomeView.h"

HomeView::HomeView(QWidget* parent) 
    : QMainWindow(parent)
    , _ui(new Ui::HomeView) 
    , _loginView(new LoginView(this))
    , _managementView(new ManagementView(this))
    , _registerView(new RegisterView(this))
    , _roomView(new RoomView(this))
    , _paraclinicalView(new ParaclinicalView(this))
    , _receiptView(new ReceiptView(this))
    , _loginStack(new QStackedWidget(this))
    , _mainStack(new QStackedWidget(this))
{
    _ui->setupUi(this);
    
    _ui->home_action->setEnabled(0);
    _ui->light_action->setEnabled(0);
    _ui->logout_action->setEnabled(0);
    _ui->detailManagement_frame->setVisible(0);
    _ui->room_frame->setVisible(0);

    _loginStack->addWidget(_ui->centralwidget);
    _loginStack->addWidget(_loginView);
    _loginStack->setCurrentIndex(1);
    setCentralWidget(_loginStack);

    _mainStack->addWidget(_ui->instructions_textBrowser);
    _mainStack->addWidget(_managementView);
    _mainStack->addWidget(_registerView);
    _mainStack->addWidget(_roomView);
    _mainStack->addWidget(_paraclinicalView);
    _mainStack->addWidget(_receiptView);
    _ui->central_horizontalLayout->addWidget(_mainStack);

    _managementButtonGroup = new QButtonGroup(this);
    _managementButtonGroup->addButton(_ui->patient_pushButton);
    _managementButtonGroup->addButton(_ui->department_pushButton);
    _managementButtonGroup->addButton(_ui->employee_pushButton);

    _roomButtonGroup = new QButtonGroup(this);
    createRoomButtons();

    _mainButtonGroup = new QButtonGroup(this);
    _mainButtonGroup->addButton(_ui->manage_pushButton);
    _mainButtonGroup->addButton(_ui->register_pushButton);
    _mainButtonGroup->addButton(_ui->room_pushButton);
    _mainButtonGroup->addButton(_ui->paraclinical_pushButton);
    _mainButtonGroup->addButton(_ui->receipt_pushButton);
    _mainButtonGroup->addButton(_ui->medicine_pushButton);
    
    qApp->setStyleSheet(themeStyleSheet());
    setStyleSheet("");
    setConnections();
}

HomeView::~HomeView() {
    delete _ui;
}

void HomeView::setConnections() {
    connect(_ui->navigate_menu, &QMenu::triggered, this,
        [this](QAction* action) {
            if (action->text() == QStringLiteral("Trang chủ")) {
                clearButtonGroupSelection(_mainButtonGroup);
                clearButtonGroupSelection(_managementButtonGroup);
                clearButtonGroupSelection(_roomButtonGroup);
                switchToView(View::Home);
            }
            else if (action->text() == QStringLiteral("Thoát")) {
                close();
            }
        });

    connect(_ui->theme_menu, &QMenu::triggered, this,
        [this](QAction* action) {
            if (action->text() == QStringLiteral("Tối")) {
                qApp->setStyleSheet(themeStyleSheet("dark"));
                _ui->dark_action->setEnabled(0);
                _ui->light_action->setEnabled(1);
            }
            else if (action->text() == QStringLiteral("Sáng")) {
                qApp->setStyleSheet(themeStyleSheet("light"));
                _ui->dark_action->setEnabled(1);
                _ui->light_action->setEnabled(0);
            }
        });

    connect(_ui->account_menu, &QMenu::triggered, this,
        [this](QAction*) {
            switchToLogin(1);
            _ui->home_action->setEnabled(0);
            _ui->logout_action->setEnabled(0);
        });

    connect(_loginView, &LoginView::loginSucceeded, this,
        [this]() {
            switchToLogin(0);
            _ui->home_action->setEnabled(1);
            _ui->logout_action->setEnabled(1);
        });

    connect(
        _mainButtonGroup,
        QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
        this,
        [this](QAbstractButton*, bool checked) {
            if (!checked) {
                clearButtonGroupSelection(_managementButtonGroup);
                clearButtonGroupSelection(_roomButtonGroup);
            }
        });

    connect(_ui->manage_pushButton, &QPushButton::toggled, this,
        [this](bool checked) {
            _ui->detailManagement_frame->setVisible(checked);
        });

    connect(_ui->patient_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            switchToView(View::Management);
            _managementView->changeModel(ModelType::Patient);
        });

    connect(_ui->department_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            switchToView(View::Management);
            _managementView->changeModel(ModelType::Department);
        });

    connect(_ui->employee_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            switchToView(View::Management);
            _managementView->changeModel(ModelType::Employee);
        });

    connect(_ui->register_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            switchToView(View::Register);
            _registerView->updateRoomInfo();
        });

    connect(_ui->room_pushButton, &QPushButton::toggled, this,
        [this](bool checked) {
            _ui->room_frame->setVisible(checked);
        });

    connect(
        _roomButtonGroup,
        QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
        this,
        [this](QAbstractButton* button, bool checked) {
            if (checked) {
                auto buttons = _roomButtonGroup->buttons();
                auto it = std::find(buttons.begin(), buttons.end(), button);
                _roomView->changeRoom(it - buttons.begin());
                switchToView(View::Room);
            }
        });

    connect(_ui->paraclinical_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            switchToView(View::Paraclinical);
            _paraclinicalView->updateView();
        });

    connect(_ui->receipt_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            switchToView(View::Receipt);
        });

    connect(_ui->medicine_pushButton, &QPushButton::clicked, this,
        [this](bool) {
            switchToView(View::Management);
            _managementView->changeModel(ModelType::Medicine);
        });
}

QString HomeView::themeStyleSheet(const QString& theme) {
    QString filePath = QString(":qdarkstyle/%1/%1style.qss").arg(theme);
    QFile f(filePath);
    if (!f.exists()) {
        printf("Unable to set stylesheet, file not found\n");
        return "";
    }
    else {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        return ts.readAll();
    }
}

void HomeView::switchToLogin(bool yes) {
    _loginStack->setCurrentIndex(yes);
}

void HomeView::switchToView(View view) {
    _mainStack->setCurrentIndex((int)view);
}

void HomeView::clearButtonGroupSelection(QButtonGroup* group) {
    if (group) {
        group->setExclusive(0);
        for (auto button : group->buttons()) {
            button->setChecked(0);
        }
        group->setExclusive(1);
    }
}

void HomeView::createRoomButtons() {
    auto layout = _ui->room_frame->layout();
    QPushButton* button = nullptr;
    auto numRooms = ServiceLocator::instance()->roomExaminationRepository()->data().size();
    for (int i = 0; i < numRooms; ++i) {
        button = new QPushButton(_ui->room_frame);
        button->setText(QString("Phòng %1").arg(i + 1));
        button->setSizePolicy(
            QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed)
        );
        button->setMinimumSize(QSize(140, 30));
        button->setCheckable(1);

        layout->addWidget(button);
        _roomButtonGroup->addButton(button);
    }
}
