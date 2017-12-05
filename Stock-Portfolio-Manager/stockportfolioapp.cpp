/*
* stockportfolioapp.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "ui_stockportfolioapp.h"
#include "stockportfolioapp.h"
#include "newstocklistdialog.h"
#include "dbmanager.h"
#include <iterator>
using std::iterator;

/*
 * Adds stock lists to combo boxes
 */
void stockportfolioapp::addStockListsToComboBox()
{
    QStringList stockListNames;

    vector<StockList> stockVec = dbm.getStockLists();

    for (auto &s : stockVec)
    {
        stockListNames << QString::fromStdString(s.getStockListName());
    }

    ui->stockListBox->clear();
    ui->stockListBox->addItems(stockListNames);
}

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

    // adds stock lists to the combobox
    this->addStockListsToComboBox();

    // sets message timer
    this->setMessageTimer();
}

/*
 * Destructor
 */
stockportfolioapp::~stockportfolioapp()
{
    delete model;
    delete messageTimer;
    delete ui;
}

/*
 * When newListButton is clicked...
 */
void stockportfolioapp::on_newListButton_clicked()
{
    this->openNewStockListDialog();
}

/*
 * Sets the message timer
 */
void stockportfolioapp::setMessageTimer()
{
    messageTimer = new QTimer(this);
    messageTimer->setInterval(3000);    // 3 seconds
    connect(messageTimer, SIGNAL(timeout()), this, SLOT(on_setTimer()));
    messageTimer->start();
}

/*
 * Every three seconds update stocks
 */
void stockportfolioapp::on_setTimer()
{

}

/*
 * Opens the dialog for adding a new stock list
 */
void stockportfolioapp::openNewStockListDialog()
{
    // create new dialog window object
    NewStockListDialog nsld(this);

    // sets modal to true, disabled while open
    nsld.setModal(true);

    // if window successfully launches...
    if (nsld.exec() == QDialog::Accepted)
    {
        // gets stock list info
        string name = nsld.getStockListName();
        vector<string> ticks = nsld.getTickersToAdd();

        // adds stock list info
        dbm.addList(name, ticks);

        // adds to combo box
        this->addStockListsToComboBox();

        // creates index
        int index = ui->stockListBox->findText(QString::fromStdString(name));

        // if text was found...
        if (index != -1)
        {
            // set index
            ui->stockListBox->setCurrentIndex(index);
        }
    }
}

