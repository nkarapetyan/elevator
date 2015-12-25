//
//  @ Project : Elevator System
//  @ File Name : Elevator.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//


#include "include/core/Elevator.h"

void Elevator::openDoors()
{
    m_elDoor->open();
}

void Elevator::closeDoors()
{
    m_elDoor->close();
}

int Elevator::getCurrentFloor() const
{
    return m_currFloorNumber;
}

Elevator::Elevator(std::vector<Button *> elButtons, Sensor* sensor, Door *door, Engine *engine)
    : m_status(ElevatorStatus::IDLE),
      m_currFloorNumber(1),
      m_dstFloorNumber(-1),
      m_elDoor(door),
      m_buttons(elButtons),
      m_sensor(sensor),
      m_engine(engine)
{
}

void Elevator::stopCar()
{
    m_engine->turnOff();
    m_dstFloorNumber = -1;
    m_status = ElevatorStatus::WAITING;
    //openDoors();
}

void Elevator::moveCar()
{
    if(m_dstFloorNumber == -1) {
        m_status = ElevatorStatus::IDLE;
        //m_direction = -1;
        m_engine->turnOff();
        return;
    }
    m_status = ElevatorStatus::INMOTION;
    if(m_direction == Direction::UP){
        m_engine->move(1);
    } else {
        m_engine->move(-1);
    }
    setDisplay(m_currFloorNumber);
}

void Elevator::setDisplay(int floorNumber)
{
    std::string dirS = "-";
    if(m_direction == Direction::UP) {
        dirS = "UP";
    } else if(m_direction == Direction::DOWN) {
        dirS = "DOWN";
    }
    if(m_status == ElevatorStatus::IDLE) {
        dirS = "-";
    }
    m_display = Display::getInstance();
    m_display->setDisplay(floorNumber, dirS);
}

void Elevator::setStatus(ElevatorStatus status)
{
    m_status = status;
}

void Elevator::setDestination(int dst)
{
    m_dstFloorNumber = dst;
}

int Elevator::getDestination() const
{
    return m_dstFloorNumber;
}

void Elevator::setCurrentFloor(int floorNumber)
{
    m_currFloorNumber = floorNumber;
}

Elevator::ElevatorStatus Elevator::getStatus() const
{
    return m_status;
}

Elevator::Direction Elevator::getDirection() const
{
    return m_direction;
}

void Elevator::setDirection(Direction dir)
{
    m_direction = dir;
}
