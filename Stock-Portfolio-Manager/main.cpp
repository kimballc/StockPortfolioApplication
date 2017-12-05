/*
* main.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "stockportfolioapp.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    stockportfolioapp w;
    w.show();

    return a.exec();
}
