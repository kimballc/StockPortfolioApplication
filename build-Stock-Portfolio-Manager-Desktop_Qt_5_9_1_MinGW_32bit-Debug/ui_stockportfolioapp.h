/********************************************************************************
** Form generated from reading UI file 'stockportfolioapp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKPORTFOLIOAPP_H
#define UI_STOCKPORTFOLIOAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stockportfolioapp
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QAction *actionClose_Application;
    QAction *actionEdit;
    QAction *actionRemove;
    QAction *actionNew;
    QAction *actionRefresh;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QComboBox *stockListBox;
    QPushButton *editListButton;
    QPushButton *refreshButton;
    QPushButton *newListButton;
    QPushButton *removeListButton;
    QTableView *stockTableView;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QMenu *menuList;
    QMenu *menuData;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *stockportfolioapp)
    {
        if (stockportfolioapp->objectName().isEmpty())
            stockportfolioapp->setObjectName(QStringLiteral("stockportfolioapp"));
        stockportfolioapp->resize(1296, 968);
        actionLogin = new QAction(stockportfolioapp);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogout = new QAction(stockportfolioapp);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionClose_Application = new QAction(stockportfolioapp);
        actionClose_Application->setObjectName(QStringLiteral("actionClose_Application"));
        actionEdit = new QAction(stockportfolioapp);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionRemove = new QAction(stockportfolioapp);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        actionNew = new QAction(stockportfolioapp);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionRefresh = new QAction(stockportfolioapp);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        centralWidget = new QWidget(stockportfolioapp);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stockListBox = new QComboBox(centralWidget);
        stockListBox->setObjectName(QStringLiteral("stockListBox"));

        gridLayout->addWidget(stockListBox, 0, 0, 1, 1);

        editListButton = new QPushButton(centralWidget);
        editListButton->setObjectName(QStringLiteral("editListButton"));

        gridLayout->addWidget(editListButton, 0, 1, 1, 1);

        refreshButton = new QPushButton(centralWidget);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));

        gridLayout->addWidget(refreshButton, 0, 4, 1, 1);

        newListButton = new QPushButton(centralWidget);
        newListButton->setObjectName(QStringLiteral("newListButton"));

        gridLayout->addWidget(newListButton, 0, 3, 1, 1);

        removeListButton = new QPushButton(centralWidget);
        removeListButton->setObjectName(QStringLiteral("removeListButton"));

        gridLayout->addWidget(removeListButton, 0, 2, 1, 1);

        stockTableView = new QTableView(centralWidget);
        stockTableView->setObjectName(QStringLiteral("stockTableView"));
        stockTableView->setAlternatingRowColors(true);
        stockTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        stockTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        stockTableView->setShowGrid(false);

        gridLayout->addWidget(stockTableView, 1, 0, 1, 5);

        stockportfolioapp->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(stockportfolioapp);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1296, 17));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuList = new QMenu(menuBar);
        menuList->setObjectName(QStringLiteral("menuList"));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QStringLiteral("menuData"));
        stockportfolioapp->setMenuBar(menuBar);
        mainToolBar = new QToolBar(stockportfolioapp);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        stockportfolioapp->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(stockportfolioapp);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        stockportfolioapp->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuList->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuOptions->addSeparator();
        menuOptions->addSeparator();
        menuOptions->addAction(actionLogin);
        menuOptions->addSeparator();
        menuOptions->addAction(actionLogout);
        menuOptions->addAction(actionClose_Application);
        menuList->addAction(actionEdit);
        menuList->addAction(actionRemove);
        menuList->addAction(actionNew);
        menuData->addAction(actionRefresh);

        retranslateUi(stockportfolioapp);

        QMetaObject::connectSlotsByName(stockportfolioapp);
    } // setupUi

    void retranslateUi(QMainWindow *stockportfolioapp)
    {
        stockportfolioapp->setWindowTitle(QApplication::translate("stockportfolioapp", "Stock Portfolio Manager", Q_NULLPTR));
        actionLogin->setText(QApplication::translate("stockportfolioapp", "Login", Q_NULLPTR));
        actionLogout->setText(QApplication::translate("stockportfolioapp", "Logout", Q_NULLPTR));
        actionClose_Application->setText(QApplication::translate("stockportfolioapp", "Close Application", Q_NULLPTR));
        actionEdit->setText(QApplication::translate("stockportfolioapp", "Edit", Q_NULLPTR));
        actionRemove->setText(QApplication::translate("stockportfolioapp", "Remove", Q_NULLPTR));
        actionNew->setText(QApplication::translate("stockportfolioapp", "New", Q_NULLPTR));
        actionRefresh->setText(QApplication::translate("stockportfolioapp", "Refresh", Q_NULLPTR));
        editListButton->setText(QApplication::translate("stockportfolioapp", "Edit List", Q_NULLPTR));
        refreshButton->setText(QApplication::translate("stockportfolioapp", "Refresh", Q_NULLPTR));
        newListButton->setText(QApplication::translate("stockportfolioapp", "New List", Q_NULLPTR));
        removeListButton->setText(QApplication::translate("stockportfolioapp", "Remove List", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("stockportfolioapp", "Account", Q_NULLPTR));
        menuList->setTitle(QApplication::translate("stockportfolioapp", "List", Q_NULLPTR));
        menuData->setTitle(QApplication::translate("stockportfolioapp", "Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stockportfolioapp: public Ui_stockportfolioapp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKPORTFOLIOAPP_H
