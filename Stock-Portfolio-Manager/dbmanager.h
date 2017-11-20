/*
* dbmanager.h
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "stock.h"
#include "stocklist.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariant>

class DbManager
{
private:
    StockList list(const string &name);         // stock list object
    QSqlDatabase db;        // variable for the database
    void _loadStocks();     // loads the stocks from the database

public:
    DbManager();                                                // constructor
    bool updateStock(string, double, double, int, double, int); // updates stock in db and local copy
    ~DbManager();                                               // Destructor
};

#endif // DBMANAGER_H
