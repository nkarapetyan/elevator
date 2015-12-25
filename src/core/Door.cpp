//
//  @ Project : Elevator System
//  @ File Name : Door.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//


#include "include/core/Door.h"
#include <QGraphicsLineItem>

#include <unistd.h>

Door::Door()
    : m_status(ISCLOSE),
      m_timeOut(10) //in seconds
{
}

void Door::open()
{
    m_status = Door::ISOPEN;
    notify(this);
}

void Door::close()
{
    m_status = Door::ISCLOSE;
    notify(this);
}

Door::Status Door::getStatus() const
{
    return m_status;
}
