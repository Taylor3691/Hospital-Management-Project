#ifndef EMPLOYEE_RECORD_VIEW_H
#define EMPLOYEE_RECORD_VIEW_H

#include <QPushButton>
#include "ui_EmployeeRecordView.h"
#include "../models/Doctor.h"
#include "../models/Nurse.h"
#include "../models/Receptionist.h"

enum class EmployeeType {
    Doctor,
    Nurse,
    Receptionist
};

namespace Ui {
    class EmployeeRecordView;
}

class EmployeeRecordView : public QDialog {
    Q_OBJECT

private:
    Ui::EmployeeRecordView* _ui;

public:
    explicit EmployeeRecordView(const QString& styleSheet = "", QWidget* parent = nullptr);
    ~EmployeeRecordView();

private:
    void setup(const QString& styleSheet);
    void setConnections();

public:
    std::unique_ptr<Employee> getEmployee() const;
    void setEmployee(const Employee* employee);
    void setAcceptButtonText(const QString& text);
    void disableNotEditableFields();
};

#endif // !EMPLOYEE_RECORD_VIEW_H
