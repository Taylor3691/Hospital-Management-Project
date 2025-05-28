#ifndef PATIENT_FILTERING_VIEW_H
#define PATIENT_FILTERING_VIEW_H

#include <vector>
#include <QPushButton>
#include "ui_PatientFilteringView.h"
#include "../utils/QueryTypes.h"
#include "../models/Patient.h"

namespace Ui {
    class PatientFilteringView;
}

class PatientFilteringView : public QDialog {
    Q_OBJECT

private:
    Ui::PatientFilteringView* _ui;

public:
    explicit PatientFilteringView(QWidget* parent = nullptr);
    ~PatientFilteringView();

private:
    void setConnections();

public:
    std::vector<RFilter<Patient>> getFilters() const;
};

#endif // !PATIENT_FILTERING_VIEW_H
