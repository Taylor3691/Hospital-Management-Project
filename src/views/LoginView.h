#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <QWidget>
#include "ui_LoginView.h"

namespace Ui {
    class LoginView;
}

class LoginView : public QWidget {
    Q_OBJECT

private:
    Ui::LoginView* _ui;

public:
    LoginView(QWidget* parent = nullptr);
    ~LoginView();

private:
    bool checkPassword() const;

signals:
    void loginSucceeded();
};

#endif
