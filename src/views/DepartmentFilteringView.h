#ifndef DEPARTMENT_FILTERING_VIEW_H
#define DEPARTMENT_FILTERING_VIEW_H

#include <vector>
#include <QPushButton>
#include "ui_DepartmentFilteringView.h"
#include "../utils/QueryTypes.h"
#include "../models/Department.h"

namespace Ui {
    class DepartmentFilteringView;
}

class DepartmentFilteringView : public QDialog {
    Q_OBJECT

private:
    Ui::DepartmentFilteringView* _ui;

public:
    explicit DepartmentFilteringView(const QString& styleSheet = "", QWidget* parent = nullptr);
    ~DepartmentFilteringView();

private:
    void setup(const QString& styleSheet);
    void setConnections();

public:
    std::vector<RFilter<Department>> getFilters() const;
};

#endif // !DEPARTMENT_FILTERING_VIEW_H
