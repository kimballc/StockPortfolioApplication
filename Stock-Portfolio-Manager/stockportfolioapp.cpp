/*
* stockportfolioapp.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "ui_stockportfolioapp.h"
#include "stockportfolioapp.h"

/*
 * Constructor
 */
stockportfolioapp::stockportfolioapp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stockportfolioapp)
{
    ui->setupUi(this);

    // create new stock model and abbly it to the table view
    model = new StockTableModel(this);
    ui->stockTableView->setModel(model);

    // set table view to allow the columns to expand
    ui->stockTableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // stretch the columns headers to fit the width of the table view
    ui->stockTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // resize the columns
    ui->stockTableView->resizeColumnsToContents();
}

/*
 * Destructor
 */
stockportfolioapp::~stockportfolioapp()
{
    delete model;
    delete ui;
}
