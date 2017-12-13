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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_EditListDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QPushButton *addStockButton;
    QGroupBox *infoGroupBox;
    QListView *stockListView;
    QPushButton *removeStockButton;

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
        font.setPointSize(16);
        titleLabel->setFont(font);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(277, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 2);

        buttonBox = new QDialogButtonBox(EditListDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 3);

        addStockButton = new QPushButton(EditListDialog);
        addStockButton->setObjectName(QStringLiteral("addStockButton"));

        gridLayout->addWidget(addStockButton, 3, 0, 1, 1);

        infoGroupBox = new QGroupBox(EditListDialog);
        infoGroupBox->setObjectName(QStringLiteral("infoGroupBox"));

        gridLayout->addWidget(infoGroupBox, 1, 1, 4, 2);

        stockListView = new QListView(EditListDialog);
        stockListView->setObjectName(QStringLiteral("stockListView"));

        gridLayout->addWidget(stockListView, 1, 0, 1, 1);

        removeStockButton = new QPushButton(EditListDialog);
        removeStockButton->setObjectName(QStringLiteral("removeStockButton"));

        gridLayout->addWidget(removeStockButton, 4, 0, 1, 1);


        retranslateUi(EditListDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditListDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditListDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditListDialog);
    } // setupUi

    void retranslateUi(QDialog *EditListDialog)
    {
        EditListDialog->setWindowTitle(QApplication::translate("EditListDialog", "Edit List", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("EditListDialog", "Edit List", Q_NULLPTR));
        addStockButton->setText(QApplication::translate("EditListDialog", "Add Stock...", Q_NULLPTR));
        infoGroupBox->setTitle(QApplication::translate("EditListDialog", "GroupBox", Q_NULLPTR));
        removeStockButton->setText(QApplication::translate("EditListDialog", "Remove Stock...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditListDialog: public Ui_EditListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLISTDIALOG_H
