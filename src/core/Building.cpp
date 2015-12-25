//
//  @ Project : Elevator System
//  @ File Name : Building.h
//  @ Date : 6/3/2014
//  @ Author : Nare Karapetyan
//
//

#include "include/core/Building.h"

Building::Building(std::vector<Button*> elButtons, std::vector<Button*> flButtons,
                   Sensor *sensor, std::vector<Door*> flDoors, Door* elDoor, Engine *engine)
{
    for(size_t i = 0; i < flButtons.size(); ++i) {
        Floor* fl = new Floor(flButtons.at(i), flDoors.at(i));
        m_floors.push_back(fl);
    }
    m_elevator  = new Elevator(elButtons, sensor, elDoor, engine);
    m_elSystem = new ElevatorSystem(m_elevator, m_floors);

    for(size_t i = 0; i < elButtons.size(); ++i) {
        elButtons.at(i)->attach(m_elSystem);
    }
    for(size_t i = 0; i< flButtons.size(); ++i) {
        flButtons.at(i)->attach(m_elSystem);
    }
    sensor->attach(m_elSystem);

}
