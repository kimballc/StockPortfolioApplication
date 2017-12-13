/********************************************************************************
** Form generated from reading UI file 'newstocklistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSTOCKLISTDIALOG_H
#define UI_NEWSTOCKLISTDIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewStockListDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *newStockListLabel;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLineEdit *stockListNameBox;
    QLineEdit *tickersAddBox;
    QLabel *tickerAddLabel;
    QLabel *stockListNameLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewStockListDialog)
    {
        if (NewStockListDialog->objectName().isEmpty())
            NewStockListDialog->setObjectName(QStringLiteral("NewStockListDialog"));
        NewStockListDialog->resize(512, 384);
        NewStockListDialog->setMinimumSize(QSize(512, 384));
        NewStockListDialog->setMaximumSize(QSize(512, 384));
        verticalLayout_2 = new QVBoxLayout(NewStockListDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        newStockListLabel = new QLabel(NewStockListDialog);
        newStockListLabel->setObjectName(QStringLiteral("newStockListLabel"));
        newStockListLabel->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(24);
        newStockListLabel->setFont(font);

        verticalLayout_2->addWidget(newStockListLabel);

        groupBox = new QGroupBox(NewStockListDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 250));
        QFont font1;
        font1.setPointSize(12);
        groupBox->setFont(font1);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        stockListNameBox = new QLineEdit(groupBox);
        stockListNameBox->setObjectName(QStringLiteral("stockListNameBox"));
        stockListNameBox->setMinimumSize(QSize(0, 30));
        stockListNameBox->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(4, QFormLayout::FieldRole, stockListNameBox);

        tickersAddBox = new QLineEdit(groupBox);
        tickersAddBox->setObjectName(QStringLiteral("tickersAddBox"));
        tickersAddBox->setMinimumSize(QSize(0, 30));
        tickersAddBox->setMaximumSize(QSize(16777215, 30));

        formLayout->setWidget(7, QFormLayout::FieldRole, tickersAddBox);

        tickerAddLabel = new QLabel(groupBox);
        tickerAddLabel->setObjectName(QStringLiteral("tickerAddLabel"));
        QFont font2;
        font2.setPointSize(10);
        tickerAddLabel->setFont(font2);

        formLayout->setWidget(7, QFormLayout::LabelRole, tickerAddLabel);

        stockListNameLabel = new QLabel(groupBox);
        stockListNameLabel->setObjectName(QStringLiteral("stockListNameLabel"));
        stockListNameLabel->setFont(font2);

        formLayout->setWidget(4, QFormLayout::LabelRole, stockListNameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(2, QFormLayout::SpanningRole, horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(3, QFormLayout::SpanningRole, horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(5, QFormLayout::SpanningRole, horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(6, QFormLayout::SpanningRole, horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(9, QFormLayout::SpanningRole, horizontalSpacer_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(8, QFormLayout::SpanningRole, horizontalSpacer_6);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(NewStockListDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(NewStockListDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewStockListDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewStockListDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewStockListDialog);
    } // setupUi

    void retranslateUi(QDialog *NewStockListDialog)
    {
        NewStockListDialog->setWindowTitle(QApplication::translate("NewStockListDialog", "New Stock List", Q_NULLPTR));
        newStockListLabel->setText(QApplication::translate("NewStockListDialog", "New Stock List", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("NewStockListDialog", "Stock List Details", Q_NULLPTR));
        tickerAddLabel->setText(QApplication::translate("NewStockListDialog", "Tickers to add:", Q_NULLPTR));
        stockListNameLabel->setText(QApplication::translate("NewStockListDialog", "Stock List Name:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewStockListDialog: public Ui_NewStockListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSTOCKLISTDIALOG_H
