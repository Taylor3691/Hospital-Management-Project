#include "LoginView.h"

LoginView::LoginView(QWidget* parent) 
    : QWidget(parent), _ui(new Ui::LoginView) 
{
    _ui->setupUi(this);
    _ui->loginFailed_label->setText("");

    // Just for development
    _ui->username_lineEdit->setText("admin");
    _ui->password_lineEdit->setText("password");

    connect(_ui->showPassword_checkBox, &QCheckBox::stateChanged, this, [this](int state) {
        if (state == Qt::CheckState::Checked) {
            _ui->password_lineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        }
        else {
            _ui->password_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        }
    });
    
    connect(_ui->password_lineEdit, &QLineEdit::returnPressed, this, [this]() {
        _ui->login_pushButton->click();
    });

    connect(_ui->login_pushButton, &QPushButton::clicked, this, [this](bool) {
        if (_ui->username_lineEdit->text().size() && checkPassword()) {
            _ui->password_lineEdit->setText("");
            _ui->loginFailed_label->setText("");
            emit loginSucceeded();
        }
        else {
            _ui->loginFailed_label->setText("*Tên đăng nhập hoặc mật khẩu không đúng");
        }
    });
}

LoginView::~LoginView() {
    delete _ui;
}

bool LoginView::checkPassword() const {
    return _ui->password_lineEdit->text() == "password"; // Temporary logic
}
