#ifndef ELEVATORSIMULATIONUICELL_H
#define ELEVATORSIMULATIONUICELL_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPolygonF>

#include "include/gui/doorui.h"
#include "include/gui/displayui.h"

#include "include/core/Button.h"

namespace Ui {
class ElevatorSimulationUICell;
}

class ElevatorSimulationUICell : public QWidget
{
    Q_OBJECT

public:
    explicit ElevatorSimulationUICell(Button *button, Door* door, QWidget *parent = 0);
    ~ElevatorSimulationUICell();

public slots:
    void floorButtonPressed();

private:
    Ui::ElevatorSimulationUICell *ui;
    QGraphicsScene* m_scene;

    Button* m_button;
    Door* m_door;
    DoorUI* m_doorUi;
    DisplayUI* m_displayUi;

};

#endif // ELEVATORSIMULATIONUICELL_H
