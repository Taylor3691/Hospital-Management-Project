#ifndef ROOM_VIEW_H
#define ROOM_VIEW_H

#include <QCompleter>
#include <QStringList>
#include "ui_RoomView.h"
#include "../models/ClinicalTestTableModel.h"
#include "../models/Doctor.h"
#include "../models/MedicalRecordListModel.h"
#include "../models/MedicineUsageTableModel.h"
#include "../models/TestServiceTableModel.h"
#include "../ServiceLocator.h"
#include "../utils/Date.h"
#include "../utils/utils.h"
#include "MedicinePrescribingView.h"
#include "SelectingView.h"

namespace Ui {
    class RoomView;
}

class RoomView : public QWidget {
    Q_OBJECT

private:
    Ui::RoomView* _ui;

public:
    explicit RoomView(QWidget* parent = nullptr);
    ~RoomView();

private:
    void setConnections();
    void createCompleter();
    void update(const MedicalRecord& record);
    void setExaminationInfo(const std::string& recordId);
    void setPatientInfo();
    void setClinicalTests();
    void setMedicineUsages();
    void clearExaminationInfo();
    void clearPatientInfo();
    void clearClinicalTests();
    void clearMedicineUsages();
    void addTests(const QVector<std::string>& specifiedTests);
    void triggerRecordFilter();

public:
    void changeRoom(int index);
};

#endif // !ROOM_VIEW_H
