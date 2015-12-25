//
//  @ Project : Elevator System
//  @ File Name : Floor.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//


#include "include/core/Floor.h"

Floor::Floor(Button* fButton, Door* door) :
    m_button(fButton),
    m_door(door)
{
    m_display = Display::getInstance();
}

void Floor::openDoors()
{
    m_door->open();
}

void Floor::closeDoors()
{
    m_door->close();
}

/*
void Floor::attachToButton(ElevatorSystem* elSystem)
{
    m_button->attach(elSystem);
}*/
