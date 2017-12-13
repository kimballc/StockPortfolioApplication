#include "editlistdialog.h"
#include "ui_editlistdialog.h"

EditListDialog::EditListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditListDialog)
{
    ui->setupUi(this);
}

EditListDialog::~EditListDialog()
{
    delete ui;
}
