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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stockportfolioapp
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *stockportfolioapp)
    {
        if (stockportfolioapp->objectName().isEmpty())
            stockportfolioapp->setObjectName(QStringLiteral("stockportfolioapp"));
        stockportfolioapp->resize(400, 300);
        menuBar = new QMenuBar(stockportfolioapp);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        stockportfolioapp->setMenuBar(menuBar);
        mainToolBar = new QToolBar(stockportfolioapp);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        stockportfolioapp->addToolBar(mainToolBar);
        centralWidget = new QWidget(stockportfolioapp);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stockportfolioapp->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(stockportfolioapp);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        stockportfolioapp->setStatusBar(statusBar);

        retranslateUi(stockportfolioapp);

        QMetaObject::connectSlotsByName(stockportfolioapp);
    } // setupUi

    void retranslateUi(QMainWindow *stockportfolioapp)
    {
        stockportfolioapp->setWindowTitle(QApplication::translate("stockportfolioapp", "stockportfolioapp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stockportfolioapp: public Ui_stockportfolioapp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKPORTFOLIOAPP_H
