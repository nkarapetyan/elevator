//
//  @ Project : Elevator System
//  @ File Name : Scheduler.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//

#include "include/core/Scheduler.h"

#include <cassert>
#include <iostream>

Scheduler::Scheduler(Elevator* elevator) :
    m_elevator(elevator)
{
}

void Scheduler::processRequest(int floorNumber)
{
    int currPos = m_elevator->getCurrentFloor();
    int dst = m_elevator->getDestination();


    if(m_elevator->getStatus() == Elevator::ElevatorStatus::IDLE) {
        m_elevator->setDestination(floorNumber);
        if(floorNumber > currPos) {
            m_elevator->setDirection(Elevator::Direction::UP);
        } else {
            m_elevator->setDirection(Elevator::Direction::DOWN);
        }
        return;
    }

    if(dst == floorNumber)
        return;
    if(currPos > floorNumber) {
        m_downwardList.insert(floorNumber);
    } else {
        m_upwardList.insert(floorNumber);
    }
    schedule();
}

void Scheduler::schedule()
{
    int dst = m_elevator->getDestination();

    if(m_upwardList.empty() && m_downwardList.empty())
        return;

    if(m_upwardList.empty() && m_downwardList.empty() && dst == -1) {
        m_elevator->setStatus(Elevator::ElevatorStatus::IDLE);
        m_elevator->setDestination(-1);
        return;
    }

    Elevator::Direction elDir = m_elevator->getDirection();

    if(elDir == Elevator::Direction::UP && m_upwardList.empty() && dst == -1) {
        int newJob = *(m_downwardList.begin());
        m_elevator->setDestination(newJob);
        m_elevator->setDirection(Elevator::Direction::DOWN);
        m_downwardList.erase(m_downwardList.begin());
        return;
    }

    if(elDir == Elevator::Direction::DOWN && m_downwardList.empty() && dst == -1) {
        int newJob = *(m_upwardList.begin());
        m_elevator->setDestination(newJob);
        m_elevator->setDirection(Elevator::Direction::UP);
        m_upwardList.erase(m_upwardList.begin());
        return;
    }

    if(elDir == Elevator::Direction::UP && dst ==-1) {
        int newJob = *(m_upwardList.begin());
        m_elevator->setDestination(newJob);
        m_upwardList.erase(m_upwardList.begin());
        return;
    }

    if(elDir == Elevator::Direction::DOWN && dst ==-1) {
        int newJob = *(m_downwardList.begin());
        m_elevator->setDestination(newJob);
        m_downwardList.erase(m_downwardList.begin());
        return;
    }

    if(elDir == Elevator::Direction::UP) {
        int newJob = *(m_upwardList.begin());
        if(newJob < dst) {
            m_elevator->setDestination(newJob);
            m_upwardList.erase(m_upwardList.begin());
            m_upwardList.insert(dst);
            return;
        }
        return;
    }

    if(elDir == Elevator::Direction::DOWN) {
        int newJob = *(m_downwardList.begin());
        if(newJob > dst) {
            m_elevator->setDestination(newJob);
            m_downwardList.erase(m_downwardList.begin());
            m_downwardList.insert(dst);
        }
        return;
    }
    std::cout << "The programm must not enter to this block,";
    std::cout << " one of the previous if conditions must be completed\n";
    assert(1==0);
}

