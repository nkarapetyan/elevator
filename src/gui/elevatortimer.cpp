#include "include/gui/elevatortimer.h"
#include <cassert>

#include <iostream>

ElevatorTimer::ElevatorTimer() :
    m_timer(new QTimer)
{
    m_dir = 0;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(notifySensor()));
}

void ElevatorTimer::updateV(Subject *subject)
{
    assert( (dynamic_cast<Engine*>(subject) != 0) && "The incorrect object was passed to Timer");
    Engine* engine = dynamic_cast<Engine*>(subject);
    if(!engine->isOn()) {
        m_timer->stop();
        return;
    }
    m_dir = engine->getDirection();
    m_timer->start(engine->getClock() * 1000);
}

void ElevatorTimer::notifySensor()
{
    m_timer->stop();
    notify(this);
    std::cout << "hehhehehehheheheh\n";
}

