#include "HomeView.h"

HomeView::HomeView(QWidget* parent) 
    : QMainWindow(parent)
    , _ui(new Ui::HomeView) 
    , _loginView(new LoginView(this))
    , _managementView(new ManagementView(this))
    , _loginView_stack(new QStackedWidget(this))
    , _managementView_stack(new QStackedWidget(this))
{
    setup();
    setConnections();
}

HomeView::~HomeView() {
    delete _ui;
}

void HomeView::setup() {
    _ui->setupUi(this);
    
    _loginView->setStyleSheet("");
    _managementView->setStyleSheet("");
    setStyleSheet("");
    qApp->setStyleSheet(themeStyleSheet());

    _ui->home_action->setEnabled(0);
    _ui->light_action->setEnabled(0);
    _ui->logout_action->setEnabled(0);
    _ui->detailManagement_frame->setVisible(0);

    _loginView_stack->addWidget(_ui->centralwidget);
    _loginView_stack->addWidget(_loginView);
    _loginView_stack->setCurrentIndex(1);
    setCentralWidget(_loginView_stack);

    _managementView_stack->addWidget(_ui->instructions_textBrowser);
    _managementView_stack->addWidget(_managementView);
    _ui->central_horizontalLayout->addWidget(_managementView_stack);
}

void HomeView::setConnections() {
    connect(_ui->navigate_menu, &QMenu::triggered, this, [this](QAction* action) {
        if (action->text() == QStringLiteral("Trang chủ")) {
            updateCheckedState();
            _ui->manage_pushButton->setChecked(0);
            _loginView_stack->setCurrentIndex(0);
            _managementView_stack->setCurrentIndex(0);
        }
        else if (action->text() == QStringLiteral("Thoát")) {
            close();
        }
    });

    connect(_ui->theme_menu, &QMenu::triggered, this, [this](QAction* action) {
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

    connect(_ui->account_menu, &QMenu::triggered, this, [this](QAction*) {
        _loginView_stack->setCurrentIndex(1);
        _ui->home_action->setEnabled(0);
        _ui->logout_action->setEnabled(0);
    });

    connect(_loginView, &LoginView::loginSucceeded, this, [this]() {
        _loginView_stack->setCurrentIndex(0);
        _ui->home_action->setEnabled(1);
        _ui->logout_action->setEnabled(1);
    });

    connect(_ui->manage_pushButton, &QPushButton::toggled, this, [this](bool checked) {
        _ui->detailManagement_frame->setVisible(checked);
    });

    connect(_ui->patient_pushButton, &QPushButton::clicked, this, [this](bool) {
        updateCheckedState();
        _managementView_stack->setCurrentIndex(1);
        _managementView->changeModel(Model::Patient);
    });

    connect(_ui->department_pushButton, &QPushButton::clicked, this, [this](bool) {
        updateCheckedState();
        _managementView_stack->setCurrentIndex(1);
        _managementView->changeModel(Model::Department);
    });

    connect(_ui->employee_pushButton, &QPushButton::clicked, this, [this](bool) {
        updateCheckedState();
        _managementView_stack->setCurrentIndex(1);
        _managementView->changeModel(Model::Employee);
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

void HomeView::updateCheckedState() {
    auto& children = _ui->detailManagement_frame->children();
    for (auto& child : children) {
        if (sender() != child) {
            auto button = qobject_cast<QPushButton*>(child);
            if (button) {
                button->setChecked(0);
            }
        }
    }
}
