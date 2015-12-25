#include "include/gui/incabinecontrollerui.h"
#include "ui_incabinecontrollerui.h"

ButtonUI::ButtonUI(Button *button, QPushButton *pushButton) :
    m_button(button),
    m_pushButton(pushButton)
{
}

void ButtonUI::inCabinButtonPressed()
{
    m_button->pressButton();
}

QPushButton* ButtonUI::getPushButton()
{
    return m_pushButton;
}

InCabineControllerUi::InCabineControllerUi(std::vector<Button *> buttons, Door* door, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InCabineControllerUi),
    m_displayUi(new DisplayUI),
    m_doorUi(new DoorUI),
    m_buttons(buttons),
    m_door(door)
{
    ui->setupUi(this);

    m_door->attach(m_doorUi);
    Display* display = Display::getInstance();
    display->attach(m_displayUi);
    this->setWindowTitle("Elevator Cabine");
    ui->inCabineDisplayHorizontalLayout->addWidget(m_displayUi);
    ui->doorHorizontalLayout->addWidget(m_doorUi);


    QVBoxLayout* vlayout = new QVBoxLayout;
    QHBoxLayout* hlayout = new QHBoxLayout;
    for(size_t i = 0; i < m_buttons.size(); ++i) {
        Button::ButtonType type = m_buttons.at(i)->getType();
        int floorNum = m_buttons.at(i)->getFloorNumber();
        if(type == Button::ButtonType::NUMBUTTON) {
            m_buttonsUi.push_back(new ButtonUI(m_buttons.at(i),
                                               new QPushButton(QString::number(floorNum))));
        } else if(type == Button::ButtonType::CLOSEBUTTON) {
            m_buttonsUi.push_back(new ButtonUI(m_buttons.at(i),new QPushButton("Close")));
        } else if(type == Button::ButtonType::OPENBUTTON) {
            m_buttonsUi.push_back(new ButtonUI(m_buttons.at(i),new QPushButton("Open")));
        }

        vlayout->addWidget(m_buttonsUi.at(i)->getPushButton());

        if(i == m_buttons.size()/2) {
            hlayout->addLayout(vlayout);
            vlayout = new QVBoxLayout;
        }

        connect(m_buttonsUi.at(i)->getPushButton(), SIGNAL(clicked()),
                m_buttonsUi.at(i), SLOT(inCabinButtonPressed()));
    }
    hlayout->addLayout(vlayout);
    ui->buttonSetVerticalLayout->addLayout(hlayout);
}

InCabineControllerUi::~InCabineControllerUi()
{
    delete ui;
}
