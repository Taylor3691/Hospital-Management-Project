#ifndef MANAGEMENT_VIEW_H
#define MANAGEMENT_VIEW_H

#include <QVector>
#include "ui_ManagementView.h"
#include "../utils/utils.h"
#include "../models/EmployeeTableModel.h"
#include "EmployeeRecordView.h"
#include "EmployeeFilteringView.h"
#include "../models/DepartmentTableModel.h"
#include "DepartmentRecordView.h"
#include "DepartmentFilteringView.h"
#include "../models/PatientTableModel.h"
#include "PatientRecordView.h"
#include "PatientFilteringView.h"
#include "../models/MedicineTableModel.h"
#include "MedicineManagementView.h"

namespace Ui {
    class ManagementView;
}

enum class ModelType {
    Patient,
    Department,
    Employee,
    Medicine,
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
    void setConnections();

public:
    void changeModel(ModelType model);
};

#endif // !MANAGEMENT_VIEW_H
