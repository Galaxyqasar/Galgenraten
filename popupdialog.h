#ifndef POPUPDIALOG_H
#define POPUPDIALOG_H

#include <QDialog>

namespace Ui {
class PopUpDialog;
}

class PopUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpDialog(QWidget *parent = 0);
    ~PopUpDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PopUpDialog *ui;
    void setlabel();
};

#endif // POPUPDIALOG_H
