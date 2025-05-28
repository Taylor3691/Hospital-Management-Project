#ifndef SELECTING_VIEW_H
#define SELECTING_VIEW_H

#include <QPushButton>
#include "ui_SelectingView.h"
#include "../ServiceLocator.h"
#include "../models/SelectableTableModel.h"

namespace Ui {
    class SelectingView;
}

class SelectingView : public QDialog {
    Q_OBJECT

public:
    Ui::SelectingView* _ui;

public:
    explicit SelectingView(QWidget* parent = nullptr);
    ~SelectingView();

public:
    void setModel(SelectableTableModel* model);
};

#endif // !SELECTING_VIEW_H
