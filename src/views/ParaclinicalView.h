#ifndef PARACLINICAL_VIEW_H
#define PARACLINICAL_VIEW_H

#include <QPushButton>
#include "ui_ParaclinicalView.h"

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
};

#endif // !PARACLINICAL_VIEW_H
