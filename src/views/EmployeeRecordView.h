#ifndef EMPLOYEE_RECORD_VIEW_H
#define EMPLOYEE_RECORD_VIEW_H

#include <QPushButton>
#include "ui_EmployeeRecordView.h"
#include "../models/Doctor.h"
#include "../models/Nurse.h"
#include "../models/Receptionist.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"
#include "../ServiceLocator.h"

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
    QVector<QString> _newIds;

public:
    explicit EmployeeRecordView(const QString& styleSheet = "",
        Role role = Role::Add, QWidget* parent = nullptr);
    ~EmployeeRecordView();

private:
    void setup(const QString& styleSheet, Role role);
    void createNewIds();

public:
    std::unique_ptr<Employee> getEmployee() const;
    void setEmployee(const Employee* employee);
};

#endif // !EMPLOYEE_RECORD_VIEW_H
