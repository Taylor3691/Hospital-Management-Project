#ifndef EMPLOYEE_FILTERING_VIEW_H
#define EMPLOYEE_FILTERING_VIEW_H

#include <vector>
#include <QPushButton>
#include "ui_EmployeeFilteringView.h"
#include "../utils/QueryTypes.h"
#include "../models/Doctor.h"
#include "../models/Nurse.h"
#include "../models/Receptionist.h"

namespace Ui {
    class EmployeeFilteringView;
}

class EmployeeFilteringView : public QDialog {
    Q_OBJECT

private:
    Ui::EmployeeFilteringView* _ui;

public:
    explicit EmployeeFilteringView(const QString& styleSheet = "", QWidget* parent = nullptr);
    ~EmployeeFilteringView();

private:
    void setup(const QString& styleSheet);
    void setConnections();

public:
    std::vector<RFilter<Employee>> getFilters() const;
};

#endif // !EMPLOYEE_FILTERING_VIEW_H
