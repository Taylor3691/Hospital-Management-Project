#ifndef MEDICINE_PRECRIBING_VIEW_H
#define MEDICINE_PRECRIBING_VIEW_H

#include <QPushButton>
#include "ui_MedicinePrecribingView.h"
#include "../utils/QueryTypes.h"
#include "../models/Doctor.h"
#include "../models/Nurse.h"
#include "../models/Receptionist.h"

namespace Ui {
    class MedicinePrecribingView;
}

class MedicinePrecribingView : public QDialog {
    Q_OBJECT

private:
    Ui::MedicinePrecribingView* _ui;

public:
    explicit MedicinePrecribingView(const QString& styleSheet = "", QWidget* parent = nullptr);
    ~MedicinePrecribingView();

private:
    void setup(const QString& styleSheet);
    void setConnections();
};

#endif // !MEDICINE_PRECRIBING_VIEW_H
