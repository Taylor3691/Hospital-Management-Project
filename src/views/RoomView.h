#ifndef ROOM_VIEW_H
#define ROOM_VIEW_H

#include <QCompleter>
#include <QStringList>
#include "ui_RoomView.h"
#include "../ServiceLocator.h"
#include "../models/MedicalRecordListModel.h"
#include "../models/Doctor.h"
#include "../utils/Date.h"
#include "MedicinePrescribingView.h"
#include "../utils/utils.h"
#include "../models/TestServiceTableModel.h"

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

public:
    void changeRoom(int index);
};

#endif // !ROOM_VIEW_H
