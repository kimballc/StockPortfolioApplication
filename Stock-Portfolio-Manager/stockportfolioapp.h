/*
* stockportfolioapp.h
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#ifndef STOCKPORTFOLIOAPP_H
#define STOCKPORTFOLIOAPP_H

#include <QMainWindow>
#include "stocktablemodel.h"
#include <QTimer>
#include <string>

namespace Ui {
class stockportfolioapp;
}

class stockportfolioapp : public QMainWindow
{
    Q_OBJECT

public:
    explicit stockportfolioapp(QWidget *parent = 0);
    ~stockportfolioapp();

private slots:
    void on_setTimer();

    void on_actionNew_triggered();

    void on_actionLogin_triggered();

    void on_newListButton_clicked();

private:
    Ui::stockportfolioapp *ui;
    StockTableModel *model;
    DbManager dbm;                   // creates DbManager object
    QTimer *messageTimer;            // message timer variable
    void addStockListsToComboBox();  // adds the stocklists to the drop-down
    void setMessageTimer();          // sets message timer
    void openNewStockListDialog();   // opens the dialog for adding a new stock list
    bool openLoginDialog();          // opens the login dialog box

};

#endif // STOCKPORTFOLIOAPP_H
