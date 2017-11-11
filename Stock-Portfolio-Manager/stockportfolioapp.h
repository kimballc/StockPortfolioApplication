/*
* stockportfolioapp.h
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#ifndef STOCKPORTFOLIOAPP_H
#define STOCKPORTFOLIOAPP_H

#include <QMainWindow>

namespace Ui {
class stockportfolioapp;
}

class stockportfolioapp : public QMainWindow
{
    Q_OBJECT

public:
    explicit stockportfolioapp(QWidget *parent = 0);
    ~stockportfolioapp();

private:
    Ui::stockportfolioapp *ui;
};

#endif // STOCKPORTFOLIOAPP_H
