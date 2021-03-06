//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Engine.h
//  @ Date : 6/3/2014
//  @ Author : 
//
//


#if !defined(_ENGINE_H)
#define _ENGINE_H

#include "Subject.h"


class Engine : public Subject {
public:
    Engine(int clock = 2);
    void turnOff();
    void move(int direction);
    int getClock() const;
    int getDirection() const;
    bool isOn() const;
private:
    int m_clock; // in seconds
    int m_direction;

    bool m_status;
};

#endif  //_ENGINE_H
