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
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->columnWidth(0)*1);
    ui->tableWidget->setColumnWidth(1, ui->tableWidget->columnWidth(1)*2);
    ui->tableWidget->setColumnWidth(2, ui->tableWidget->columnWidth(2)*2);
    ui->tableWidget->horizontalHeader()->sortIndicatorOrder();
    for(int i=stats.size();i>=0;i=i-2)
        stats.removeAt(i-1);
    ui->tableWidget->setRowCount(stats.size());
    for(int i=0;i<stats.size();i++)
    {
        tmp = stats.at(i);
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString(strtok(tmp.toLatin1().data(), "-:-"))));
        strtok(NULL, ":");
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString(strtok(NULL, "-:-"))));
        strtok(NULL, ":");
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(strtok(NULL, ";"))));
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







