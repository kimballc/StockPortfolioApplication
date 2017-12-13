#ifndef EDITLISTDIALOG_H
#define EDITLISTDIALOG_H

#include <QDialog>

namespace Ui {
class EditListDialog;
}

class EditListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditListDialog(QWidget *parent = 0);
    ~EditListDialog();

private:
    Ui::EditListDialog *ui;
};

#endif // EDITLISTDIALOG_H
