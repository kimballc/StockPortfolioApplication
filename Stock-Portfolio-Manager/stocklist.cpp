/*
* stocklist.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "stocklist.h"
#include <iostream>
using std::cout; using std::endl;

/*
 * Constructor
 */
StockList::StockList(const string &name) :
           stockListName(name)
{
    // creates a dabase connection object
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={ODBC Driver 13 for SQL Server};Server=tcp:portfolio-svr.database.windows.net,1433;Database=StockPortfolioDB;Uid=cs245;Pwd=Thomas123;Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;");

    // loads stocks from database
    this->_loadStocks();
}

/*
 * Loads stocks from the database
 */
void StockList::_loadStocks()
{
    // opens database connection
    bool ok = db.open();

    // if the database connection is successful...
    if(ok)
    {
        // creates a query that can only be read forward
        QSqlQuery query;
        query.setForwardOnly(true);

        // create prepared statement
        // gets stocks from Stock table, orders by ticker
        query.prepare("SELECT * FROM Stock ORDER BY ticker;");

        // if SQL query is okay...
        if (query.exec())
        {
            // while there are still more records in the result set
            while (query.next())
            {
                // gets data and stores it to local variables
                string tick      = query.value(1).toString().toStdString();
                string name      = query.value(2).toString().toStdString();
                double price     = query.value(3).toDouble();
                double change    = query.value(4).toDouble();
                int volume       = query.value(5).toInt();
                double dividend  = query.value(6).toDouble();

                // stores data into a Stock object
                Stock myStock;

                myStock.setTicker(tick);
                myStock.setCompanyName(name);
                myStock.setCurrentPrice(price);
                myStock.setPercentChange(change);
                myStock.setVolume(volume);
                myStock.setAnnualDividend(dividend);

                stocks.insert(make_pair(myStock.getTicker(), myStock));
            }
        }

    }
    // if connection is not successful...
    else
    {
        // informs user there were connection issues
        cout << "There were issues connecting..." << endl;
    }
}

/*
 * Adds new stock to the map
 */
void StockList::addToMap(Stock stock)
{
    stocks.insert(make_pair(stock.getTicker(), stock));
}

/*
 * Removes stock from the map
 */
void StockList::removeFromMap(Stock stock)
{
    stocks.erase(stock.getTicker());
}

/*
 * Find and returns a stock
 */
Stock *StockList::findStock(const string &tick)
{
    // loops through stocks
    for (auto &s : stocks)
    {
        Stock stock = s.second;

        // if found, returns stock reference
        if (stock.getTicker() == tick)
        {
            return &stock;
        }
    }
    // if not found...
    return nullptr;
}

/*
 * Returns the stock list name
 */
string StockList::getStockListName()
{
    return stockListName;
}

/*
 * Returns the stock map
 */
StockMap &StockList::getStocks()
{
    return stocks;
}

/*
 * Sets stock list name
 */
void StockList::setStockListName(const string &name)
{
    stockListName = name;
}

/*
 * Destructor
 */
StockList::~StockList()
{
    db.close();
}
