#ifndef DOORUI_H
#define DOORUI_H

#include <QWidget>
#include <QGraphicsLineItem>
#include "include/core/Observer.h"
#include "include/core/Door.h"

namespace Ui {
class DoorUI;
}

class DoorUI : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit DoorUI(QWidget *parent = 0);
    ~DoorUI();

    enum {
        isOPEN,
        isCLOSE
    };
    void open();
    void close();

    void updateV(Subject* subject);

private slots:
     void updateDoor(QGraphicsLineItem* item1, QGraphicsLineItem* item2);
signals:
     void notifyDoorChanged(QGraphicsLineItem* item1, QGraphicsLineItem* item2);

private: 
    Ui::DoorUI *ui;

    void setUp();
    void setDoors();

    QGraphicsScene* m_scene;
};

#endif // DOORUI_H
