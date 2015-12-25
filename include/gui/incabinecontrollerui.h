#ifndef INCABINECONTROLLERUI_H
#define INCABINECONTROLLERUI_H

#include <QWidget>
#include <QPushButton>

#include "include/gui/displayui.h"
#include "include/gui/doorui.h"

#include "include/core/Button.h"

namespace Ui {
class InCabineControllerUi;
}

class ButtonUI : public QObject
{
    Q_OBJECT
public:
    ButtonUI(Button* button, QPushButton* pushButton);
public slots:
    void inCabinButtonPressed();
    QPushButton* getPushButton();
private:
    Button* m_button;
    QPushButton* m_pushButton;
};

class InCabineControllerUi : public QWidget
{
    Q_OBJECT

public:
    explicit InCabineControllerUi(std::vector<Button *> buttons,  Door* door, QWidget *parent = 0);
    ~InCabineControllerUi();

     void updateDisplay(int floorNumber, const std::string& dir);
private:
    Ui::InCabineControllerUi *ui;

    DisplayUI* m_displayUi;
    DoorUI* m_doorUi;

    std::vector<ButtonUI*> m_buttonsUi;
    std::vector<Button*> m_buttons;
    Door* m_door;
};

#endif // INCABINECONTROLLERUI_H
