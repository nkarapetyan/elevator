//
//  @ Project : Elevator System
//  @ File Name : Button.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//

#include "include/core/Button.h"
#include <cassert>
#include <iostream>

Button::Button(int floorNumber, ButtonType type)
    : m_floorNumber(floorNumber),
      m_type(type)
{
}

void Button::pressButton()
{
    activateButton();
    notify(this);
}

Button::ButtonType Button::getType() const
{
    return m_type;
}

void Button::activateButton()
{
    m_bulb = true;
    // turn on the bulb on the gui
    // by changing the icon
}

int Button::getFloorNumber() const
{
    return m_floorNumber;
}
