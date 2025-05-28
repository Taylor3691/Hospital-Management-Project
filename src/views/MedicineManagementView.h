#ifndef MEDICINE_MANAGEMENT_VIEW_H
#define MEDICINE_MANAGEMENT_VIEW_H

#include <vector>
#include <QPushButton>
#include "ui_MedicineManagementView.h"
#include "../models/Medicine.h"
#include "../utils/utils.h"
#include "../utils/utils_template.h"
#include "../ServiceLocator.h"
#include "../utils/QueryTypes.h"

namespace Ui {
    class MedicineManagementView;
}

class MedicineManagementView : public QDialog {
    Q_OBJECT

private:
    Ui::MedicineManagementView* _ui;

public:
    explicit MedicineManagementView(Role role = Role::Add,
        QWidget* parent = nullptr);
    ~MedicineManagementView();

public:
    std::unique_ptr<Medicine> getMedicine() const;
    void setMedicine(const Medicine* medicine);
    std::vector<RFilter<Medicine>> getFilters() const;
};

#endif // !MEDICINE_MANAGEMENT_VIEW_H
