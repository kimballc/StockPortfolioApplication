/********************************************************************************
** Form generated from reading UI file 'editlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLISTDIALOG_H
#define UI_EDITLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditListDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *titleLabel;
    QDialogButtonBox *buttonBox;
    QListView *stockListView;
    QPushButton *removeStockButton;
    QPushButton *addStockButton;
    QLabel *stockListNameLabel;

    void setupUi(QDialog *EditListDialog)
    {
        if (EditListDialog->objectName().isEmpty())
            EditListDialog->setObjectName(QStringLiteral("EditListDialog"));
        EditListDialog->resize(512, 384);
        EditListDialog->setMinimumSize(QSize(512, 384));
        EditListDialog->setMaximumSize(QSize(512, 384));
        gridLayout = new QGridLayout(EditListDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        titleLabel = new QLabel(EditListDialog);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(22);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(EditListDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 2);

        stockListView = new QListView(EditListDialog);
        stockListView->setObjectName(QStringLiteral("stockListView"));

        gridLayout->addWidget(stockListView, 2, 0, 1, 1);

        removeStockButton = new QPushButton(EditListDialog);
        removeStockButton->setObjectName(QStringLiteral("removeStockButton"));

        gridLayout->addWidget(removeStockButton, 4, 0, 1, 1);

        addStockButton = new QPushButton(EditListDialog);
        addStockButton->setObjectName(QStringLiteral("addStockButton"));

        gridLayout->addWidget(addStockButton, 3, 0, 1, 1);

        stockListNameLabel = new QLabel(EditListDialog);
        stockListNameLabel->setObjectName(QStringLiteral("stockListNameLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(16);
        stockListNameLabel->setFont(font1);
        stockListNameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(stockListNameLabel, 1, 0, 1, 1);


        retranslateUi(EditListDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditListDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditListDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditListDialog);
    } // setupUi

    void retranslateUi(QDialog *EditListDialog)
    {
        EditListDialog->setWindowTitle(QApplication::translate("EditListDialog", "Edit List", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("EditListDialog", "Edit Stock List", Q_NULLPTR));
        removeStockButton->setText(QApplication::translate("EditListDialog", "Remove Stock...", Q_NULLPTR));
        addStockButton->setText(QApplication::translate("EditListDialog", "Add Stock...", Q_NULLPTR));
        stockListNameLabel->setText(QApplication::translate("EditListDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditListDialog: public Ui_EditListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLISTDIALOG_H
