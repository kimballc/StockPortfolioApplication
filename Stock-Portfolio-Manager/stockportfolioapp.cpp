/*
* stockportfolioapp.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "stockportfolioapp.h"
#include "ui_stockportfolioapp.h"

stockportfolioapp::stockportfolioapp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stockportfolioapp)
{
    ui->setupUi(this);
}

stockportfolioapp::~stockportfolioapp()
{
    delete ui;
}
