//
//  @ Project : Elevator System
//  @ File Name : Elevator.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//


#include "include/core/Engine.h"

Engine::Engine(int clock) :
    m_clock(clock),
    m_status(false)
{
}

int Engine::getClock() const
{
    return m_clock;
}

void Engine::turnOff()
{
    m_status = false;
    notify(this);
}

void Engine::move(int direction)
{
    m_status = true;
    m_direction = direction;
    notify(this);
}

int Engine::getDirection() const
{
    return m_direction;
}

bool Engine::isOn() const
{
    return m_status;
}

