#ifndef MANAGEMENT_VIEW_H
#define MANAGEMENT_VIEW_H

#include <QVector>
#include "ui_ManagementView.h"
#include "../utils/utils.h"
#include "../models/EmployeeTableModel.h"
#include "../views/EmployeeRecordView.h"
#include "../views/EmployeeFilteringView.h"
#include "../models/DepartmentTableModel.h"
#include "../views/DepartmentRecordView.h"
#include "../views/DepartmentFilteringView.h"
#include "../models/PatientTableModel.h"
#include "../views/PatientRecordView.h"
#include "../views/PatientFilteringView.h"

namespace Ui {
    class ManagementView;
}

enum class ModelType {
    Patient,
    Department,
    Employee,
};

class ManagementView : public QWidget {
    Q_OBJECT

private:
    Ui::ManagementView* _ui;
    QVector<QAbstractTableModel*> _models;

public:
    explicit ManagementView(QWidget* parent = nullptr);
    ~ManagementView();

private:
    void setup();
    void setConnections();

public:
    void changeModel(ModelType model);
};

#endif // !MANAGEMENT_VIEW_H
