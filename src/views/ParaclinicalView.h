#ifndef PARACLINICAL_VIEW_H
#define PARACLINICAL_VIEW_H

#include <QPushButton>
#include "ui_ParaclinicalView.h"
#include "../models/MedicalRecordListModel.h"
#include "../models/ClinicalTestTableModel.h"
#include "../models/ExaminingState.h"

namespace Ui {
    class ParaclinicalView;
}

class ParaclinicalView : public QWidget {
    Q_OBJECT

private:
    Ui::ParaclinicalView* _ui;

public:
    explicit ParaclinicalView(QWidget* parent = nullptr);
    ~ParaclinicalView();

private:
    void setConnections();
    void triggerRecordFilter();
    void triggerTestFilter();
    void setClinicalTest(const ClinicalTest* test);
    std::unique_ptr<ClinicalTest> getClinicalTest();
    void clearTestInfo();

public:
    void updateView();
};

#endif // !PARACLINICAL_VIEW_H
