#include "include/gui/doorui.h"
#include "ui_doorui.h"

DoorUI::DoorUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoorUI),
    m_scene(new QGraphicsScene)
{
    setUp();
    connect(this, SIGNAL(notifyDoorChanged(QGraphicsLineItem*,QGraphicsLineItem*)),
            this, SLOT(updateDoor(QGraphicsLineItem*,QGraphicsLineItem*)));
    setDoors();
}

DoorUI::~DoorUI()
{
    delete ui;
}

void DoorUI::setUp()
{
    // TODO support multiple floor interface by providing number of floors
    //sinchronized with number of buttons
    ui->setupUi(this);
    ui->floorDoorsGraphicsView->setScene(m_scene);
    ui->floorDoorsGraphicsView->setFixedSize(126, 192);
}


void DoorUI::setDoors()
{
    QGraphicsLineItem* item1 = new QGraphicsLineItem(0, 0, 0, 187);
    QGraphicsLineItem* item2 = new QGraphicsLineItem(0, 0, 0, 187);
    emit notifyDoorChanged(item1, item2);
}

void DoorUI::close()
{
    //if(m_status == isCLOSE)
      //  return;
    for(int i = 60; i>=0; i-=5) {
        QGraphicsLineItem* item1 = new QGraphicsLineItem(-i, 0, -i, 187);
        QGraphicsLineItem* item2 = new QGraphicsLineItem(i, 0, i, 187);
        emit notifyDoorChanged(item1, item2);
    }
    //m_status = isCLOSE;
}

void DoorUI::open()
{
    //if(m_status == isOPEN)
      //  return;
    for(int i = 2; i<=60; i+=5) {
        QGraphicsLineItem* item1 = new QGraphicsLineItem(-i, 0,
                                                         -i,187);
        QGraphicsLineItem* item2 = new QGraphicsLineItem(i, 0,
                                                         i,187);
        emit notifyDoorChanged(item1, item2);
    }
    //m_status = isOPEN;
}

void DoorUI::updateDoor(QGraphicsLineItem* item1,
                        QGraphicsLineItem* item2)
{
    ui->floorDoorsGraphicsView->scene()->clear();
    ui->floorDoorsGraphicsView->scene()->addItem(item1);
    ui->floorDoorsGraphicsView->scene()->addItem(item2);
}

void DoorUI::updateV(Subject *subject)
{
    Door* door = dynamic_cast<Door*>(subject);
    Door::Status st = door->getStatus();
    if(st == Door::Status::ISCLOSE){
        close();
        return;
    }
    if(st == Door::Status::ISOPEN){
        open();
        return;
    }
}
