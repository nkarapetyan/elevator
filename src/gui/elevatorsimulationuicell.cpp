#include "include/gui/elevatorsimulationuicell.h"
#include "ui_elevatorsimulationuicell.h"

#include <QString>
#include <QGraphicsRectItem>

ElevatorSimulationUICell::ElevatorSimulationUICell(Button* button, Door* door, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElevatorSimulationUICell),
    m_button(button),
    m_door(door),
    m_doorUi(new DoorUI),
    m_displayUi(new DisplayUI)
{
    ui->setupUi(this);
    ui->floorDisplayHorizontalLayout->addWidget(m_displayUi);

    this->setWindowTitle("Floors");
    m_door->attach(m_doorUi);
    Display* display = Display::getInstance();
    display->attach(m_displayUi);

    ui->floorNumberLabel->setText("Floor " + QString::number(m_button->getFloorNumber()));
    ui->doorHorizontalLayout->addWidget(m_doorUi);

    connect(ui->floorPushButton, SIGNAL(clicked()), this, SLOT(floorButtonPressed()));
}

void ElevatorSimulationUICell::floorButtonPressed()
{
    m_button->pressButton();
}

ElevatorSimulationUICell::~ElevatorSimulationUICell()
{
    delete ui;
}
