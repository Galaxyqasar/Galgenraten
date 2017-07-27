#include "popupdialog.h"
#include "ui_popupdialog.h"
#include <QFile>
#include <QTextStream>

PopUpDialog::PopUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpDialog)
{
    ui->setupUi(this);
    setlabel();
}

PopUpDialog::~PopUpDialog()
{
    delete ui;
}

void PopUpDialog::setlabel()
{
    QFile  c("tmp.txt");
    QTextStream in(&c);
    c.open(QIODevice::ReadOnly);
    ui->label->setText(in.readAll());
}

void PopUpDialog::on_buttonBox_accepted()
{
    done(1);
}

void PopUpDialog::on_buttonBox_rejected()
{
    done(0);
}
