//
//  @ Project : Elevator System
//  @ File Name : Button.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//

#include "include/core/Sensor.h"
#include <cstdio>

Sensor::Sensor() :
    m_floorNumber(1)
{
}

void Sensor::setSensor(const int& floorNumber)
{
    m_status = true;
    m_floorNumber = floorNumber;
    notify(this);
}

int Sensor::getFloorNumber() const
{
    return m_floorNumber;
}

void Sensor::updateV(Subject *subject)
{
    m_floorNumber = m_floorNumber + subject->getDir();
    setSensor(m_floorNumber);
}
