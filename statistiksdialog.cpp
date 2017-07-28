#include "statistiksdialog.h"
#include "ui_statistiksdialog.h"
#include <string.h>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

StatistiksDialog::StatistiksDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatistiksDialog)
{
    ui->setupUi(this);
    inittable();
}

StatistiksDialog::~StatistiksDialog()
{
    delete ui;
}

void StatistiksDialog::inittable()
{
    QList<QString> headers, stats;
    headers << "Score"<<"gewonnen/verloren"<<"falsche/richtige Buchstaben";
    stats = readstats();
    QString tmp;
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
//    ui->tableWidget->setColumnWidth(0, ui->tableWidget->horizontalHeader()->length()/2);
//    ui->tableWidget->setColumnWidth(1, ui->tableWidget->horizontalHeader()->length()/2);
//    ui->tableWidget->setColumnWidth(2, ui->tableWidget->horizontalHeader()->length()/2);
    ui->tableWidget->horizontalHeader()->sortIndicatorOrder();
    for(int i=0;i<stats.size();i++)
    {
        tmp = stats.at(i);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString(strtok(tmp.toLatin1().data(), "-:-"))));
        strtok(NULL, ":");
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(strtok(NULL, "-:-"))));
        strtok(NULL, ":");
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString(strtok(NULL, ";"))));
    }
}

QList<QString> StatistiksDialog::readstats()
{
    QFile file("stats.txt");
    QTextStream in(&file);
    QString text;
    if(file.open(QIODevice::ReadOnly))
        text = in.readAll();
    QList<QString> list;
    list = text.split(";", QString::KeepEmptyParts);
    for(int i = 0;list.size()>i;i++)
        list.replace(i, list.at(i)+";");
    return list;
}







