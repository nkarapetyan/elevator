//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Floor.h
//  @ Date : 6/3/2014
//  @ Author :
//
//


#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer
{
public:
    Observer();
public:
    //void subscribe(Subject* subject);
    void update(Subject* subject);
private:
    virtual void updateV(Subject* subject) = 0;
};

#endif // OBSERVER_H
