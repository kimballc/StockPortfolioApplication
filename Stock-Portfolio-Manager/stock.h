/*
* stock.h
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#ifndef STOCK_H
#define STOCK_H

#include <string>
using std::string;

/*
 * Represents a stock object. Stores information describing
 * an instance of a stock.
 */
class Stock
{
private:
    // Each of these will describe a stock object.
    string ticker;
    string companyName;
    double currentPrice;
    double percentChange;
    int    volume;

public:
    // Default Constructor
    Stock();
    // Two Parameter Constructor
    Stock(const string &, const string &);
    // Five Parameter Constructor
    Stock(const string &, const string &, double, double, int);

    // Getters
    string getTicker()        { return ticker; }
    string getCompanyName()   { return companyName; }
    double getCurrentPrice()  { return currentPrice; }
    double getPercentChange() { return percentChange; }
    int    getVolume()        { return volume; }

    // Setters
    void setTicker(const string &);
    void setCompanyName(const string &);
    void setCurrentPrice(double);
    void setPercentChange(double);
    void setVolume(int);

    // Destructor
    ~Stock();
};

#endif // STOCK_H
