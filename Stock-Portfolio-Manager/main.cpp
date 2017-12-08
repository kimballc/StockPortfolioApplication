/*
* main.cpp
* Author: Nicholas Hagan, Christian Kimball, Zachery Forsythe
* Fall 2017
* Course: CS245: OOP w/ C++
*/

#include "stockportfolioapp.h"
#include "usermanager.h"
#include "logindialog.h"
#include <QApplication>

/*
 * Opens the dialog for adding a new stock list
 */
unsigned openLoginDialog()
{
    // create new dialog window object
    LoginDialog loginD;

    // sets modal to true, disabled while open
    loginD.setModal(true);

    // if window successfully launches...
    if (loginD.exec() == QDialog::Accepted)
    {
        string username = loginD.getUsername();
        string password = loginD.getPassword();

        UserManager um;
        um.initUser(username, password);
        um.login(username, password);

        return um.getUser().getUserID();
    }
    return 0;
}

int main(int argc, char *argv[])
{
    unsigned uID;
    QApplication a(argc, argv);

    uID = openLoginDialog();
    stockportfolioapp w(NULL ,uID);

    w.show();


    return a.exec();
}
