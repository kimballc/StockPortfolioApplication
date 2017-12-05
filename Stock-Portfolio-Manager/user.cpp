/*
 * user.cpp
 * Authors: Christian Kimball, Nicholas Hagan, Zachery Forsythe
 * Fall 2017
 * Course: CS245 - OOP w/ C++
 */

#include "user.h"
#include <exception>
#include <utility>

/*
 * Two Paramere Constructor
 * Initializes username and password hash
 */
User::User(const std::string &name, const std::string &pass)
{
    this->setUsername(name);
    this->setPassHash(pass);
}

/*
 * Three Parameter Constructor
 * Initializes all data members
 */
User::User(int id, const string &name, const string &pass) :
    userID(id)
{
    this->setUsername(name);
    this->setPassHash(pass);
}

/*
 * Destructor
 * Removes all data members from memory
 */
User::~User()
{
    //Data Members
    delete userID;
    delete username;
    delete passHash;
    delete stockLists;
}

/*
 * Sets the ID of the user
 */
void User::setUserID(int id)
{
    userID = id;
}

/*
 * Sets the username of the User
 * Checks to make sure username meets all requirements
 */
void User::setUsername(const string &name)
{
    //requirements flag variables
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    //usernames must be b/w 6-16 characters long
    if((name.length() < 6) || (name.length() > 16))
    {
        throw std::length_error("Username must be between 6-16 characters long");
    }

    //loop through the username to check for requirments
    for(char c : name)
    {
        //check for uppercase
        if(isupper(c))
        {
            hasUpper = true;
        }

        //check for lowercase
        if(islower(c))
        {
            hasLower = true;
        }

        //check for digit
        if(isdigit(c))
        {
            hasDigit = true;
        }

        //check for special characters
        if(!isalnum(c))
        {
            hasSpecial = true;
        }
    }

    //usernames must contain at least 1 uppercase character
    if(hasUpper == false)
    {
        throw std::invalid_argument("Username must contain at least 1 uppercase letter");
    }

    //usernames must contain at least 1 lowercase character
    if(hasLower == false)
    {
        throw std::invalid_argument("Username must contain at least 1 lower case letter");
    }

    //usernames must contain at least 1 digit
    if(hasDigit == false)
    {
        throw std::invalid_argument("Username must contain at least 1 digit");
    }

    //usernames may not contain special characters
    if(hasSpecial == true)
    {
        throw std::invalid_argument("Username may not contain any special characters");
    }

    username = name;
}

/*
 * Sets the hashed password of the User
 * Checks to see if the hashed password is empty
 */
void User::setPassHash(string pass)
{
    if(pass.empty())
    {
        throw std::invalid_argument("Hashed Password may not be blank");
    }
    else
    {
        passHash = pass;
    }
}

/*
 * Searches for a given stock list by its name
 */
StockList* User::findStockList(const string &stockListName)
{
    //search the map for the given StockList's name
    auto it = stockLists.find(stockListName);

    //check to see if the StockList wasn't found
    if(it == stockLists.end())
    {
        //if it wasn't return a null pointer
        return nullptr;
    }

    //if it was return a pointer to it
    StockList *sl = &it->second;
    return sl;
}

/*
 * Adds a StockList to the map
 * Checks to see if the StockList already exists in the map
 */
void User::addStockList(StockList sl)
{
    //check if the StockList to be added already exists
    //call findStockList() to do this
    if(findStockList(sl.getStockListName()) == nullptr)
    {
        //if it does not exist add it
        stockLists.insert(std::make_pair(sl.getStockListName(), sl));
    }
    else
    {
        //already exists, throw exception
        throw std::invalid_argument("StockList already exists");
    }
}

/*
 * Remove a stock list from the map
 * Checks to see if the Stock list exists in the map
 */
void User::removeStockList(const string &stockListName)
{
    //check to see if the StockList exists in the map
    //call findStockList() to do this
    if(findStockList(stockListName) == nullptr)
    {
        //if it does not exist in the map, throw exception
        throw std::out_of_range("StockList does not exist, could not be removed");
    }
    else
    {
        //if it does exist in the map, remove it
        stockLists.erase(stockListName);
    }
}
