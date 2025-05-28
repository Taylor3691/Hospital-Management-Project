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
    explicit PatientRecordView(Role role = Role::Add,
        QWidget* parent = nullptr);
    ~PatientRecordView();

private:
    void setConnections();
    void setInsuranceFieldsEnabled(bool enable);

public:
    std::unique_ptr<Patient> getPatient() const;
    void setPatient(const Patient* patient);
};

#endif // !PATIENT_RECORD_VIEW_H
