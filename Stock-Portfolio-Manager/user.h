/*
 * user.h
 * Authors: Christian Kimball, Nicholas Hagan, Zachery Forsythe
 * Fall 2017
 * Course: CS245 - OOP w/ C++
 */

#ifndef USER_H
#define USER_H

#include <string>
using std::string;
#include <map>
using std::map;
#include "stocklist.h"

typedef map<string, StockList> StockListMap;            //map of StockList alias, name is the key, StockList object itself is the value

class User
{
public:
    User(const string &, const string &);               //Two parameter constructor

    //Getters
    string getUsername(){return username;}              //returns the username
    string getPassHash(){return passHash;}              //returns the hashed password
    StockListMap getStockLists(){return stockLists;}    //returns the all of the stock lists the user owns

    //Setters
    void setUsername(const string &);                   //set the username of the user
    void setPassHash(const string &);                   //set the hashed password of the user
    //void setStockLists();

    //Helper Functions
    StockList* findStockList(const string &);           //find a StockList by its name
    void addStockList(StockList);                       //add a StockList to the StockListMap
    void removeStockList(const string &);               //remove a StockList from the StockListMap by StockList name

private:
    //data members
    string username;                                    //username of the user
    string passHash;                                    //hashed password of the user
    StockListMap stockLists;                            //map of all the StockLists that belong to the user
};

#endif // USER_H
