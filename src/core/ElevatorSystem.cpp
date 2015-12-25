//
//  @ Project : Elevator System
//  @ File Name : Elevator.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//


#include "include/core/ElevatorSystem.h"
#include <iostream>
#include <cassert>

ElevatorSystem::ElevatorSystem(Elevator* el, std::vector<Floor*> floors)
    : m_elevator(el),
      m_scheduler(new Scheduler(m_elevator)),
      m_floors(floors)
{
}

void ElevatorSystem::updateV(Subject* subject)
{
    if( dynamic_cast<Button*>(subject) != 0){
        Button* but =  dynamic_cast<Button*>(subject);
        processButtonChange(but);
        return;
    }

    if (dynamic_cast<Sensor*>(subject) != 0) {
        Sensor* sensor =  dynamic_cast<Sensor*>(subject);
        processSensorChange(sensor);
        return;
    }

    std::cout << "Can't reach this point\n";
    assert(1==0);
}

void ElevatorSystem::processButtonChange(Button* button)
{
    Button::ButtonType type = button->getType();
    switch (type) {
    case Button::ButtonType::NUMBUTTON:
        callElevator(button->getFloorNumber());
        break;
    case Button::ButtonType::OPENBUTTON:
        openDoors();
        break;
    case Button::ButtonType::CLOSEBUTTON:
        closeDoors();
        break;
    default:
        std::cout << "THE PROGRAMM SHOULD NOT ENTER TO THIS SCOPE\n";
        std::cout << "Please clearly specify the type of the button\n";
        assert(0==1);
        break;
    }
}

void ElevatorSystem::processSensorChange(Sensor* sensor)
{
    int floorNumber = sensor->getFloorNumber();
    floorIntersection(floorNumber);
}

void ElevatorSystem::floorIntersection(int floorNumber)
{
    int dst = m_elevator->getDestination();
    m_elevator->setCurrentFloor(floorNumber);
    if(floorNumber == dst){
        m_elevator->stopCar();
        openDoors();
    }

    //closeDoors();
    m_scheduler->schedule();
    m_elevator->moveCar();
    m_elevator->setDisplay(floorNumber);
}

void ElevatorSystem::callElevator(int floorNumber)
{
    closeDoors();
    m_scheduler->processRequest(floorNumber);
    if(m_elevator->getStatus() == Elevator::ElevatorStatus::INMOTION)
        return;
    if(floorNumber == m_elevator->getCurrentFloor()){
        m_elevator->stopCar();
        openDoors();
        return;
    }
    m_elevator->moveCar();
}

void ElevatorSystem::openDoors()
{
    Elevator::ElevatorStatus status = m_elevator->getStatus();
    if(status == Elevator::ElevatorStatus::INMOTION) {
        std::cout << "During Elevator motion it is not allowed to open Doors\n";
        return;
    }
    int currPos = m_elevator->getCurrentFloor();
    m_elevator->openDoors();
    assert(currPos-1>=0 && "ELEVATOR SYSTEM openDoors out of the currPos bound");
    Floor* currFloor = m_floors.at(currPos-1);
    currFloor->openDoors();
}

void ElevatorSystem::closeDoors()
{
    int currPos = m_elevator->getCurrentFloor();
    m_elevator->closeDoors();
    assert(currPos-1>=0 && "ELEVATOR SYSTEM closeDoors out of the currPos bound");
    Floor* currFloor = m_floors.at(currPos-1);
    currFloor->closeDoors();
}
