/*
 * logindialog.cpp
 * Authors: Christian Kimball, Nicholas Hagan, Zachery Foresythe
 * Fall 2017
 * Course: CS245 - OOP w/ C++
 */

#include "logindialog.h"
#include "ui_logindialog.h"
#include "stockportfolioapp.h"
#include "ui_stockportfolioapp.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    manager = new UserManager(this->getUsername(), this->getPassword());
}

LoginDialog::~LoginDialog()
{
    delete ui;
    delete manager;
}

string LoginDialog::getUsername()
{
    return ui->usernameBox->text().toStdString();
}

string LoginDialog::getPassword()
{
    return ui->passwordBox->text().toStdString();
}

void LoginDialog::done(int result)
{
    if(QDialog::Accepted == result)
    {
        QString username = ui->usernameBox->text();
        QString password = ui->passwordBox->text();
        //if the entered username and password are not empty
        if(!username.isEmpty() && !password.isEmpty())
        {
            //check for successfully matching login info
            if(manager.login())
            {
                QDialog::done(result);
            }
            //login info does not match
            else
            {
                //display warning
                QMessageBox::warning(
                            this,
                            tr("Alert"),
                            tr("Invalid Login"));
                ui->passwordBox->clear();
            }
        }
        //some field is left blank
        else
        {
            QMessageBox::warning(
                        this,
                        tr("Alert"),
                        tr("Fields cannot be blank"));
            ui->passwordBox->clear();
        }
    }
    //cancel, close or esc was pressed
    else
    {
        QDialog::done(result);
    }
}
