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
    explicit DepartmentRecordView(Role role = Role::Add,
        QWidget* parent = nullptr);
    ~DepartmentRecordView();

public:
    std::unique_ptr<Department> getDepartment() const;
    void setDepartment(const Department* department);
    bool checkValidHeadId();
};

#endif // !DEPARTMENT_RECORD_VIEW_H
