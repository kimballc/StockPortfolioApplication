/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *loginLabel;
    QGroupBox *loginInfoGroupBox;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameBox;
    QLabel *passwordLabel;
    QLineEdit *passwordBox;
    QDialogButtonBox *loginButtonBox;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(512, 384);
        LoginDialog->setMinimumSize(QSize(512, 384));
        LoginDialog->setMaximumSize(QSize(512, 384));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        loginLabel = new QLabel(LoginDialog);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setMaximumSize(QSize(512, 100));
        QFont font;
        font.setPointSize(16);
        loginLabel->setFont(font);

        verticalLayout->addWidget(loginLabel);

        loginInfoGroupBox = new QGroupBox(LoginDialog);
        loginInfoGroupBox->setObjectName(QStringLiteral("loginInfoGroupBox"));
        formLayout = new QFormLayout(loginInfoGroupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(24);
        usernameLabel = new QLabel(loginInfoGroupBox);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setMinimumSize(QSize(150, 0));
        usernameLabel->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameBox = new QLineEdit(loginInfoGroupBox);
        usernameBox->setObjectName(QStringLiteral("usernameBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameBox);

        passwordLabel = new QLabel(loginInfoGroupBox);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setMinimumSize(QSize(150, 0));
        passwordLabel->setMaximumSize(QSize(150, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordBox = new QLineEdit(loginInfoGroupBox);
        passwordBox->setObjectName(QStringLiteral("passwordBox"));
        passwordBox->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordBox);


        verticalLayout->addWidget(loginInfoGroupBox);

        loginButtonBox = new QDialogButtonBox(LoginDialog);
        loginButtonBox->setObjectName(QStringLiteral("loginButtonBox"));
        loginButtonBox->setOrientation(Qt::Horizontal);
        loginButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(loginButtonBox);


        retranslateUi(LoginDialog);
        QObject::connect(loginButtonBox, SIGNAL(accepted()), LoginDialog, SLOT(accept()));
        QObject::connect(loginButtonBox, SIGNAL(rejected()), LoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Log In", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("LoginDialog", "Login", Q_NULLPTR));
        loginInfoGroupBox->setTitle(QApplication::translate("LoginDialog", "Login info", Q_NULLPTR));
        usernameLabel->setText(QApplication::translate("LoginDialog", "Username:", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("LoginDialog", "Password:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
