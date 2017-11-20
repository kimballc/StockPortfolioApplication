/*
* dbmanager.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "dbmanager.h"
#include <iostream>
using std::cout; using std::endl;

DbManager::DbManager()
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
void DbManager::_loadStocks()
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
                int shar         = query.value(7).toInt();

                // stores data into a Stock object
                Stock myStock;

                myStock.setTicker(tick);
                myStock.setCompanyName(name);
                myStock.setCurrentPrice(price);
                myStock.setPercentChange(change);
                myStock.setVolume(volume);
                myStock.setAnnualDividend(dividend);
                myStock.setShares(shar);

                list.addToMap(myStock);
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
  * updates stock information
  */
bool DbManager::updateStock(string tick, double price, double change,
                            int volume, double dividend,
                            int shares)
{
    // takes the stock object found, edits information
    Stock *newStock = list.findStock(tick);
    newStock->setCurrentPrice(price);
    newStock->setPercentChange(change);
    newStock->setVolume(volume);
    newStock->setAnnualDividend(dividend);
    newStock->setShares(shares);

    // open the connection
    bool ok = db.open();

    // if we connect successfully...
    if(ok)
    {
        // build the SQL string
        QString sql;
        sql += "UPDATE stock ";
        sql += "SET currentPrice = ?, percentChange = ?, volume = ?, annualDividend = ?, shares = ? ";
        sql += "WHERE ticker = ?";

        // prepare the query
        QSqlQuery query;
        query.setForwardOnly(true);
        query.prepare(sql);

        // bind your values to the prepared statement
        query.bindValue(0, price);
        query.bindValue(1, change);
        query.bindValue(2, volume);
        query.bindValue(3, dividend);
        query.bindValue(4, shares);

        // execute the UPDATE
        if(query.exec())
        {
            return true;
        }

    }
    else
    {
        return false;
    }

    return false;
}

/*
 * Destructor
 */
DbManager::~DbManager()
{
    db.close();
}
