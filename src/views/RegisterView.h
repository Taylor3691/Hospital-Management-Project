#ifndef REGISTER_VIEW_H
#define REGISTER_VIEW_H

#include <QPushButton>
#include <QButtonGroup>
#include "ui_RegisterView.h"
#include "../ServiceLocator.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"

namespace Ui {
    class RegisterView;
}

class RegisterView : public QWidget {
    Q_OBJECT

private:
    Ui::RegisterView* _ui;
    QButtonGroup* _roomButtonGroup;

public:
    explicit RegisterView(QWidget* parent = nullptr);
    ~RegisterView();

private:
    void setConnections();
    void setupRooms();
    bool checkValid();
    std::unique_ptr<HealthInsurance> createInsurance() const;
    Patient* createPatient(std::unique_ptr<HealthInsurance> insurance) const;
    void resetInputs();

public:
    void updateRoomInfo();
};

#endif // !REGISTER_VIEW_H
