/*
 * usermanager.cpp
 * Authors: Christian Kimball, Nicholas Hagan, Zachery Foresythe
 * Fall 2017
 * Course: CS245 - OOP w/ C++
 */

#include "usermanager.h"
#include <QCryptographicHash>
#include <exception>
#include <iostream>
using std::cout;

/*
 * Constructor
 * Opens database connection
 * initializes a User object with user name and hashed password
 */
UserManager::UserManager(const string &name, const string &pass)
{
    //create Database connection object
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={ODBC Driver 13 for SQL Server};Server=tcp:portfolio-svr.database.windows.net,1433;Database=StockPortfolioDB;Uid=cs245;Pwd=Thomas123;Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;");

    user.setUsername(name);
    //hash the User's password
    user.setPassHash(hashPassword(pass));
}

/*
 * Destructor
 * Closes Database connection
 * Removes variables from memory
 */
UserManager::~UserManager()
{
    //Database
    db.close();
    delete db;

    //User
    delete user;
}

/*
 * Hashes the password of the user
 * Uses SHA3 224 Standard
 */
string UserManager::hashPassword(const string &pass)
{
    //Using SHA3 224 Standard
    QString hashPass = QString(QCryptographicHash::hash((pass.toStdString().c_str()),
                                                        QCryptographicHash::Sha3_224).toHex());
    //return the hashed password
    return hashPass.toStdString();
}

/*
 * Registers a new user to the System
 * Adds it's data to the user table in the database
 * Currently not implented
 */
void UserManager::registerUser(User newUser)
{

}

/*
 * Used to log in the user
 * Checks hashed password with what is in the database
 * Returns true if the hashes match
 * Else returns false
 */
bool UserManager::login()
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
        //gets password from User table where the username is that of the user object
        query.prepare("SELECT userID, password FROM User WHERE username = ?");

        //bind the value of username
        query.bindValue(0, user.getUsername());

        //execute SQL query
        if(query.exec())
        {
            // while there are still more records in the result set
            while(query.next())
            {
                //store data in local variables
                int ID = query.value(0).toInt();
                string pass = query.value(1).toString().toStdString();

                //if the hashed password entered by the user matches the one in the Database for the given username
                if(user.getPassHash() == pass)
                {
                    //set the ID of the user and return
                    user.setUserID(ID);
                    return true;
                }
                //if they do not exit
                else
                {
                    return false;
                }
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
