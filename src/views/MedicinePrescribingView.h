#ifndef MEDICINE_PRESCRIBING_VIEW_H
#define MEDICINE_PRESCRIBING_VIEW_H

#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include "ui_MedicinePrescribingView.h"
#include "../models/MedicineTableModel.h"
#include "../ServiceLocator.h"

namespace Ui {
    class MedicinePrescribingView;
}

class MedicinePrescribingView : public QDialog {
    Q_OBJECT

private:
    Ui::MedicinePrescribingView* _ui;

public:
    explicit MedicinePrescribingView(QWidget* parent = nullptr);
    ~MedicinePrescribingView();

private:
    void setConnections();

public:
    bool checkValid();
    std::unique_ptr<MedicineUsage> getUsage();
};

#endif // !MEDICINE_PRESCRIBING_VIEW_H
