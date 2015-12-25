#ifndef ELEVATORTIMER_H
#define ELEVATORTIMER_H

#include <QObject>
#include <QTimer>
#include "include/core/Observer.h"
#include "include/core/Engine.h"

class ElevatorTimer : public QObject, public Observer, public Subject
{
    Q_OBJECT
public:
    ElevatorTimer();

    void updateV(Subject *subject);

public slots:
    void notifySensor();
    //void notifyDoor();

private:
    QTimer* m_timer;
};

#endif // ELEVATORTIMER_H
