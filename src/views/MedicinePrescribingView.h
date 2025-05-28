#ifndef MEDICINE_PRESCRIBING_VIEW_H
#define MEDICINE_PRESCRIBING_VIEW_H

#include <QPushButton>
#include "ui_MedicinePrescribingView.h"

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
};

#endif // !MEDICINE_PRESCRIBING_VIEW_H
