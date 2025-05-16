#ifndef MANAGEMENT_VIEW_H
#define MANAGEMENT_VIEW_H

#include <QVector>
#include "ui_ManagementView.h"
#include "../models/EmployeeTableModel.h"

namespace Ui {
    class ManagementView;
}

enum class Model {
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

public:
    void changeModel(Model model);
};

#endif // !MANAGEMENT_VIEW_H
