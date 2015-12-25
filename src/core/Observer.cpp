//
//  @ Project : Elevator System
//  @ File Name : Elevator.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//


#include "include/core/Observer.h"

Observer::Observer()
{
}

/*void Observer::subscribe(Subject* subject)
{
    subject->attach(this);
}*/


void Observer::update(Subject *subject)
{
    this->updateV(subject);
}
