#ifndef REGISTER_VIEW_H
#define REGISTER_VIEW_H

#include <QPushButton>
#include "ui_RegisterView.h"
#include "../ServiceLocator.h"
#include "../models/RegistrationService.h"
#include "../utils/utils.h"

namespace Ui {
    class RegisterView;
}

class RegisterView : public QWidget {
    Q_OBJECT

private:
    Ui::RegisterView* _ui;
    std::unique_ptr<RegistrationService> _service;

public:
    explicit RegisterView(QWidget* parent = nullptr);
    ~RegisterView();

private:
    void setConnections();
    void setupRooms();
    Patient* createPatient() const;
    std::unique_ptr<HealthInsurance> createInsurance() const;
    void assignRooms(MedicalRecord* record) const;
};

#endif // !REGISTER_VIEW_H
