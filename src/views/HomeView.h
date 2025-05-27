#ifndef HOME_VIEW_H
#define HOME_VIEW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QStackedWidget>
#include <QButtonGroup>
#include "ui_HomeView.h"
#include "LoginView.h"
#include "ManagementView.h"
#include "RegisterView.h"
#include "RoomView.h"
#include "ParaclinicalView.h"
#include "ReceiptView.h"

enum class View {
    Home,
    Management,
    Register,
    Room,
    Paraclinical,
    Receipt,
};

namespace Ui {
    class HomeView;
}

class HomeView : public QMainWindow {
    Q_OBJECT

private:
    Ui::HomeView* _ui;
    LoginView* _loginView;
    ManagementView* _managementView;
    RegisterView* _registerView;
    RoomView* _roomView;
    ParaclinicalView* _paraclinicalView;
    ReceiptView* _receiptView;
    QStackedWidget* _loginStack;
    QStackedWidget* _mainStack;
    QButtonGroup* _managementButtonGroup;
    QButtonGroup* _roomButtonGroup;
    QButtonGroup* _mainButtonGroup;

public:
    HomeView(QWidget* parent = nullptr);
    ~HomeView();

private:
    void setup();
    void setConnections();
    QString themeStyleSheet(const QString& theme = "light");
    void switchToLogin(bool yes);
    void switchToView(View view);
    void clearButtonGroupSelection(QButtonGroup* group);
    void createRoomButtons();
};

#endif // !HOME_VIEW_H
