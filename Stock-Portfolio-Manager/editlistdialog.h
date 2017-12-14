#ifndef EDITLISTDIALOG_H
#define EDITLISTDIALOG_H

#include <QDialog>
#include "stocklistmodel.h"

namespace Ui {
class EditListDialog;
}

class EditListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditListDialog(vector<Stock> &, QWidget *parent = 0);
    ~EditListDialog();

private:
    Ui::EditListDialog *ui;
    StockListModel *listModel;
    //void showStock(const QModelIndex &);
};

#endif // EDITLISTDIALOG_H
