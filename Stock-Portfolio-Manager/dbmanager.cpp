/*
* dbmanager.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "dbmanager.h"
#include <sstream>
using std::istringstream;
#include <iostream>
using std::cout; using std::endl;


/*
 * Constructor
 */
DbManager::DbManager() : url("http://www.nasdaq.com/quotedll/quote.dll?page=dynamic&mode=data&&symbol=WEX&symbol=IDXX&random=0.1696504272217375")
{
    // creates a dabase connection object
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={ODBC Driver 13 for SQL Server};Server=tcp:portfolio-svr.database.windows.net,1433;Database=StockPortfolioDB;Uid=cs245;Pwd=Thomas123;Encrypt=yes;MultipleActiveResultSets=True;TrustServerCertificate=no;Connection Timeout=30;");

    // creates a second dabase connection object
    //db2 = QSqlDatabase::addDatabase("QODBC");
    //db2.setDatabaseName("Driver={ODBC Driver 13 for SQL Server};Server=tcp:portfolio-svr.database.windows.net,1433;Database=StockPortfolioDB;Uid=cs245;Pwd=Thomas123;Encrypt=yes;MultipleActiveResultSets=True;TrustServerCertificate=no;Connection Timeout=30;");

    // loads stocks from database
    this->_loadStockLists(userID);
}

/*
 * loads the data
 */
void DbManager::loadData(unsigned uID)
{
    _loadStockLists(uID);
    //_loadStocks();
}

/*
 * Sets user id
 */
void DbManager::setUserID(unsigned uID)
{
    userID = uID;
}

/*
 *  chops up a string by | character, stores it to vector
 */
vector<string> DbManager::splitString(const string &text, char sep)
{
    // creates field string, and fields vector data memebers
    string field;
    vector<string> fields;

    // creates an istringstream object that uses text paramter as a parameter
    istringstream inputStr(text);

    // while it can still get a line, adds field to fields vector
    while (getline(inputStr, field, sep))
    {
        fields.push_back(field);
    }

    // returns field vector
    return fields;
}

/*
 * parses Nasdaq code
 */
void DbManager::nasdaq()
{
    // Creates a network manager object, form the request
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(QString::fromStdString(url))));

    // send the request; wait for a response
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    // store the entire response in a QString
    string html = reply->readAll().toStdString();

    nasdaqVector = splitString(html, '|');
}

/*
 * adds a stock list to a map and DB
 */
void DbManager::addList(const string &name, vector<string>stockTicks)
{
    unsigned uID = userID;

    // opens database connection
    bool ok = db.open();

    // if the database connection is successful...
    if(ok)
    {
        QString qName = QString::fromStdString(name);

        // creates a query that can only be read forward
        QSqlQuery query;
        query.setForwardOnly(true);

        QString sql;
        sql += "INSERT INTO StockList (UserID, StockListName)";
        sql += "VALUES (?, ?)";

        // create prepared statement
        // gets stocks from Stock table, orders by ticker
        query.prepare(sql);

        query.bindValue(0, uID);
        query.bindValue(1, qName);

        // if SQL query is okay...
        if (query.exec())
        {
            QSqlQuery query2;
            query2.setForwardOnly(true);

            QString sql2;
            sql2 += "SELECT MAX[StockListID] FROM StockList";

            if (query2.exec())
            {
                unsigned maxID = query2.value(0).toInt();

                StockList newSL;
                newSL.setStockListName(name);
                for (auto &s : stockTicks)
                {
                    Stock newStock;

                    QString tick = QString::fromStdString(s);

                    QSqlQuery query3;
                    query3.setForwardOnly(true);

                    QString sql3;
                    sql3 += "INSERT INTO StockList_Item (StockID, StockListID) ";
                    sql3 += "VALUES (?, ?);";

                    query3.prepare(sql3);

                    query3.bindValue(0, tick);
                    query3.bindValue(1, maxID);

                    query3.exec();

                    newStock.setTicker(s);


                    newSL.addToMap(newStock);
                }
                stockLists.insert(make_pair(newSL.getStockListName(), newSL));
            }
        }

    }
         db.close();
}

/*
 * returns a vector of stock lists
 */
StockListMap &DbManager::getStockLists()
{
    return stockLists;
}

/*
 * Loads stocks from the database
 */
StockList DbManager::_loadStocks(unsigned stockListID)
{
    StockList sl;

    // opens database connection
    bool ok = db.open();

    // if the database connection is successful...
    if(ok)
    {
        // creates a query that can only be read forward
        QSqlQuery query;
        query.setForwardOnly(true);

        QString sql;
        sql += "SELECT ticker, companyName, currentPrice, percentChange, volume, annualDividend, shares ";
        sql += "FROM Stock ";
        sql += "INNER JOIN StockList_Item ON Stock.stockID = StockList_Item.stockID ";
        sql += "WHERE stockListID = ? ";
        sql += "ORDER BY ticker;";

        // create prepared statement
        // gets stocks from Stock table, orders by ticker
        query.prepare(sql);

        query.bindValue(0, stockListID);

        // if SQL query is okay...
        if (query.exec())
        {
            // while there are still more records in the result set
            while (query.next())
            {
                // gets data and stores it to local variables
                string tick      = query.value(0).toString().toStdString();
                string name      = query.value(1).toString().toStdString();
                double price     = query.value(2).toDouble();
                double change    = query.value(3).toDouble();
                int volume       = query.value(4).toInt();
                double dividend  = query.value(5).toDouble();
                int shar         = query.value(6).toInt();

                // stores data into a Stock object
                Stock myStock;

                myStock.setTicker(tick);
                myStock.setCompanyName(name);
                myStock.setCurrentPrice(price);
                myStock.setPercentChange(change);
                myStock.setVolume(volume);
                myStock.setAnnualDividend(dividend);
                myStock.setShares(shar);

                sl.addToMap(myStock);
            }
        }
    }
    // if connection is not successful...
    else
    {
        // informs user there were connection issues
        cout << "There were issues connecting..." << endl;
    }
    db.close();
    return sl;
}

/*
 * Loads stock lists from db and puts them in map
 */
void DbManager::_loadStockLists(unsigned uID)
{
    unsigned userID = uID;

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
        query.prepare("SELECT * FROM StockList WHERE UserID = ? ORDER BY stockListName;");

        query.bindValue(0, userID);

        // if SQL query is okay...
        if (query.exec())
        {
            // while there are still more records in the result set
            while (query.next())
            {
                // gets data and stores it to local variables
                unsigned stockListID = query.value(0).toInt();
                string stockListName = query.value(1).toString().toStdString();

                // stores data into a Stock object
                StockList sl;
                sl.setStockListName(stockListName);
                stockLists.insert(make_pair(sl.getStockListName(), sl));
            }
        }

    }
    // if connection is not successful...
    else
    {
        // informs user there were connection issues
        cout << "There were issues connecting..." << endl;
    }

    db.close();
}

 /*
  * updates stock information
  */
bool DbManager::updateStock(const string &tick, double price, double change,
                            int volume, double dividend,
                            int shares)
{
    // takes the stock object found, edits information
    Stock *newStock = stocks.findStock(tick);
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
 * Returns stock vector
 */
vector<Stock> &DbManager::getStocks()
{
    StockMap &stockMap = stocks.getStocks();

    for (auto &s : stockMap)
    {
        stockVector.push_back(s.second);
    }
    return stockVector;
}

/*
 * Destructor
 */
DbManager::~DbManager()
{
}
