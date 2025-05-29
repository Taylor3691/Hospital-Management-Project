#ifndef ROOM_VIEW_H
#define ROOM_VIEW_H

#include <QCompleter>
#include <QStringList>
#include "ui_RoomView.h"
#include "../controllers/ExaminationService.h"
#include "../models/ClinicalTestTableModel.h"
#include "../models/Doctor.h"
#include "../models/MedicalRecordListModel.h"
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
    std::unique_ptr<ExaminationService> _service;

public:
    explicit RoomView(QWidget* parent = nullptr);
    ~RoomView();

private:
    void setConnections();
    void createCompleter();
    const MedicalRecord* currentRecord();
    void setExaminationInfo();
    void setPatientInfo();
    void setClinicalTests();
    void clearExaminationInfo();
    void clearPatientInfo();
    void clearClinicalTests();
    void addTests(const QVector<std::string>& specifiedTests);

public:
    void changeRoom(int index);
};

#endif // !ROOM_VIEW_H
