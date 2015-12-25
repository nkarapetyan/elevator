#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <QWidget>

namespace Ui {
class DisplayUI;
}

#include "include/core/Observer.h"
#include "include/core/Display.h"

class DisplayUI : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit DisplayUI(QWidget *parent = 0);
    ~DisplayUI();

    void updateV(Subject* subject);
    void updateDisplay(Display *display);
    static DisplayUI* getInsctance();

private:
    Ui::DisplayUI *ui;
};

#endif // DISPLAYUI_H
