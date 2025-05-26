#ifndef PATIENT_RECORD_VIEW_H
#define PATIENT_RECORD_VIEW_H

#include <QPushButton>
#include "ui_PatientRecordView.h"
#include "../models/Patient.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"
#include "../ServiceLocator.h"

namespace Ui {
    class PatientRecordView;
}

class PatientRecordView : public QDialog {
    Q_OBJECT

private:
    Ui::PatientRecordView* _ui;

public:
    explicit PatientRecordView(const QString& styleSheet = "",
        Role role = Role::Add, QWidget* parent = nullptr);
    ~PatientRecordView();

private:
    void setup(const QString& styleSheet, Role role);
    void setConnections();
    void setInsuranceFieldsEnabled(bool enable);

public:
    std::unique_ptr<Patient> getPatient() const;
    void setPatient(const Patient* patient);
    void setAcceptButtonText(const QString& text);
    void disableNotEditableFields();
};

#endif // !PATIENT_RECORD_VIEW_H
