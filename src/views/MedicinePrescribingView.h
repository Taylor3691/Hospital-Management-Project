#ifndef MEDICINE_PRESCRIBING_VIEW_H
#define MEDICINE_PRESCRIBING_VIEW_H

#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include "ui_MedicinePrescribingView.h"
#include "../models/MedicineTableModel.h"
#include "../models/MedicineUsage.h"
#include "../controllers/ExaminationService.h"
#include "../ServiceLocator.h"

namespace Ui {
    class MedicinePrescribingView;
}

class MedicinePrescribingView : public QDialog {
    Q_OBJECT

private:
    Ui::MedicinePrescribingView* _ui;
    std::unique_ptr<ExaminationService> _service;

public:
    explicit MedicinePrescribingView(QWidget* parent = nullptr);
    ~MedicinePrescribingView();

private:
    void setConnections();

public:
    std::unique_ptr<MedicineUsage> getUsage();
};

#endif // !MEDICINE_PRESCRIBING_VIEW_H
