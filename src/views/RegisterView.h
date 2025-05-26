#ifndef REGISTER_VIEW_H
#define REGISTER_VIEW_H

#include <QPushButton>
#include "ui_RegisterView.h"
#include "../ServiceLocator.h"
#include "../utils/utils.h"

namespace Ui {
    class RegisterView;
}

class RegisterView : public QWidget {
    Q_OBJECT

private:
    Ui::RegisterView* _ui;

public:
    explicit RegisterView(QWidget* parent = nullptr);
    ~RegisterView();

private:
    void setup();
    void setConnections();
    void setupRooms();
};

#endif // !REGISTER_VIEW_H
