//
//  @ Project : Elevator System
//  @ File Name : Button.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//

#include "include/core/Display.h"


Display* Display::m_display = NULL;

Display::Display()
    : m_floorNumber(0),
      m_direction("-")
{
}

Display* Display::getInstance()
{
    if(m_display == NULL) {
        m_display = new Display();
    }
    return m_display;
}

void Display::setDisplay(int floorNumber, const std::string& direction)
{
    m_floorNumber = floorNumber;
    m_direction = direction;
    notify(this);
}

int Display::getFloorNumber() const
{
    return m_floorNumber;
}

std::string Display::getDirection() const
{
    return m_direction;
}

