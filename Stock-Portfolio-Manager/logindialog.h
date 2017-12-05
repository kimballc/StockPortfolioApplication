/*
 * logindialog.h
 * Authors: Christian Kimball, Nicholas Hagan, Zachery Foresythe
 * Fall 2017
 * Course: CS245 - OOP w/ C++
 */

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <string>
using std::string;
#include "usermanager.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    string getUsername();
    string getPassword();

private:
    Ui::LoginDialog *ui;
    UserManager manager;
    void virtual done(int);
};

#endif // LOGINDIALOG_H
