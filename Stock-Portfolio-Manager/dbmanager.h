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
#include <vector>
using std::vector;

class DbManager
{
private:
    StockList stocks;         // stock list object
    vector<Stock> stockVector; // vector of stocks
    QSqlDatabase db;        // variable for the database
    void _loadStocks();     // loads the stocks from the database

public:
    DbManager();                                                // constructor
    bool updateStock(string, double, double, int, double, int); // updates stock in db and local copy
    vector<Stock> &getStocks();                                      // returns stock map
    ~DbManager();                                               // Destructor
};

#endif // DBMANAGER_H
