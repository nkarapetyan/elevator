//
//  @ Project : Elevator System
//  @ File Name : Subject.cpp
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//


#include "include/core/Subject.h"
#include <cstdio>

void Subject::attach(Observer* observer)
{
    m_observers.push_back(observer);
}

void Subject::notify(Subject* subject)
{
    for(size_t i = 0; i < m_observers.size(); ++i){
        m_observers.at(i)->update(subject);
    }
}

int Subject::getDir() const
{
    return m_dir;
}
