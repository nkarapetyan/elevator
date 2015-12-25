#include "include/gui/mainwindow.h"
#include "ui_mainwindow.h"

#include "include/gui/elevatorsimulationuicell.h"
#include "include/gui/incabinecontrollerui.h"
#include "include/gui/elevatortimer.h"

#include <QScrollArea>

#include <vector>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Elevator System");



    /*test/
     * QPushButton* button = new QPushButton;
    ElevatorTimer* timer = new ElevatorTimer;
     * ui->verticalLayout->addWidget(button);
    connect(button, SIGNAL(clicked()), timer, SLOT(notifySensor()));
    */


    std::vector<Button*> elButtons;
    std::vector<Button*> flButtons;
    std::vector<Door*> flDoors;
    Door* elDoor = new Door;
    for(int i = 1; i <= 3; ++i) {
        elButtons.push_back(new Button(i, Button::ButtonType::NUMBUTTON));
        flButtons.push_back(new Button(i, Button::ButtonType::NUMBUTTON));
        flDoors.push_back(new Door);
    }
    elButtons.push_back(new Button(0,Button::ButtonType::OPENBUTTON));
    elButtons.push_back(new Button(0,Button::ButtonType::CLOSEBUTTON));

    Sensor* sensor = new Sensor;

    /************Must be conneted with their observers******************/
    ElevatorTimer* timer = new ElevatorTimer;
    //Display* display = Display::getInstance();
    Engine* engine = new Engine;

    timer->attach(sensor);
    engine->attach(timer);

    /*******************************************************************/

    m_building = new Building(elButtons, flButtons, sensor, flDoors, elDoor, engine);


    std::vector<ElevatorSimulationUICell*> elUI;
    InCabineControllerUi* inCabUI = new InCabineControllerUi(elButtons,elDoor);
    inCabUI->show();
    for(size_t i = 0; i <flButtons.size() ; ++i) {
        elUI.push_back(new ElevatorSimulationUICell(flButtons.at(i), flDoors.at(i)));
        ui->verticalLayout->addWidget(elUI.back());
    }
    for(size_t i = flButtons.size(); i >=1 ; ) {
        ui->verticalLayout->addWidget(elUI.at(--i));
    }

    QWidget* contentWidget = new QWidget();
    contentWidget->setLayout(ui->verticalLayout);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(contentWidget);

    setCentralWidget(scrollArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}
