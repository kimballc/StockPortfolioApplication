/*
 * usermanager.h
 * Authors: Christian Kimball, Nicholas Hagan, Zachery Foresythe
 * Fall 2017
 * Course: CS245 - OOP w/ C++
 */

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "user.h"
#include <map>
using std::map;
#include <string>
using std::string;
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariant>
#include <vector>

class UserManager
{
public:
    //Constructors
    UserManager(const string &, const string &);        //Two parameter constructor
    ~UserManager();                                     //Destructor

    //Getter
    User getUser(){return User;}                        //returns the user object that is being managed

    //Helper Functions
    void registerUser(User);                            //register a user to the system
    bool login();                                       //log the user into the system
private:
    User user;                                          //map to store users
    QSqlDatabase db;                                    // variable for the database
    string hashPassword(const string &);                //hash the password of the user
};

#endif // USERMANAGER_H
