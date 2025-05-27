#ifndef DEPARTMENT_RECORD_VIEW_H
#define DEPARTMENT_RECORD_VIEW_H

#include <QPushButton>
#include "ui_DepartmentRecordView.h"
#include "../models/Department.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"
#include "../ServiceLocator.h"

namespace Ui {
    class DepartmentRecordView;
}

class DepartmentRecordView : public QDialog {
    Q_OBJECT

private:
    Ui::DepartmentRecordView* _ui;

public:
    explicit DepartmentRecordView(const QString& styleSheet = "",
        Role role = Role::Add, QWidget* parent = nullptr);
    ~DepartmentRecordView();

private:
    void setup(const QString& styleSheet, Role role);

public:
    std::unique_ptr<Department> getDepartment() const;
    void setDepartment(const Department* department);
};

#endif // !DEPARTMENT_RECORD_VIEW_H
