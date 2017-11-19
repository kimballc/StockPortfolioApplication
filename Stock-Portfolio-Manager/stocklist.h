/*
* stocklist.h
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#ifndef STOCKLIST_H
#define STOCKLIST_H

#include "stock.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariant>
#include <string>
using std::string;
#include <map>
using std::map;

typedef map<string, Stock> StockMap;

class StockList
{

private:

    string stockListName;   // stores a name of the stock list
    StockMap stocks;        // stores a map of Stock objects
    QSqlDatabase db;        // variable for the database

    void _loadStocks();     // loads the stocks from the database

public:

    StockList(const string &);              // one parameter constructor

    void addToMap(Stock);                   // adds a stock to the map
    void removeFromMap(Stock);              // removes a stock from the map
    Stock *findStock(const string &);       // finds and returns the stock

    string getStockListName();              // returns the stocklist name
    StockMap &getStocks();                  // returns the whole stock map

    void setStockListName(const string &);  // can set the stock list name

    void updateStock(Stock);                // updates stock in db and local copy

    ~StockList();                           // destructor
};

#endif // STOCKLIST_H
