#ifndef REGISTER_VIEW_H
#define REGISTER_VIEW_H

#include <QPushButton>
#include <QButtonGroup>
#include "ui_RegisterView.h"
#include "../ServiceLocator.h"
#include "../models/RegistrationService.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"

namespace Ui {
    class RegisterView;
}

class RegisterView : public QWidget {
    Q_OBJECT

private:
    Ui::RegisterView* _ui;
    std::unique_ptr<RegistrationService> _service;
    QButtonGroup* _roomButtonGroup;

public:
    explicit RegisterView(QWidget* parent = nullptr);
    ~RegisterView();

private:
    void setConnections();
    void setupRooms();
    Patient* createPatient() const;
    std::unique_ptr<HealthInsurance> createInsurance() const;
    void assignRoom(MedicalRecord* record) const;
    void resetInputs();
    void updateRoomInfo();
};

#endif // !REGISTER_VIEW_H
