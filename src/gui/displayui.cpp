#include "include/gui/displayui.h"
#include "ui_displayui.h"

#include <cassert>

DisplayUI::DisplayUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayUI)
{
    ui->setupUi(this);
    ui->displayDirectionLabel->setText("--");//setPixmap(QPixmap("../icons/idle.jpg"));
    ui->displayNumber->display(1);
}

void DisplayUI::updateV(Subject* subject)
{
    Display* display = dynamic_cast<Display*>(subject);
    assert(display!=NULL);
    updateDisplay(display);
}

void DisplayUI::updateDisplay(Display* display)
{
    int floorNumber = display->getFloorNumber();
    std::string dir = display->getDirection();
    QString txt = "--";
    //QPixmap pix = QPixmap("../icons/idle.jpg");
    if(dir == "UP") {
        txt = "/\\";
    } else if(dir == "DOWN") {
        //pix = QPixmap("../icons/down.jpg");
        txt = "\\/";
    }
    ui->displayDirectionLabel->setText(txt);
            //setPixmap(pix);
    ui->displayNumber->display(floorNumber);
}

DisplayUI::~DisplayUI()
{
    delete ui;
}
