#include "statistiksdialog.h"
#include "ui_statistiksdialog.h"

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

void StatistiksDialog::on_pushButton_clicked()
{
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->sortByColumn(0,Qt::AscendingOrder);
    ui->tableWidget->setSortingEnabled(false);
}

void StatistiksDialog::inittable()
{
    QList<QString> headers;
    headers << "Score"<<"gewonnen/verloren"<<"falsche/richtige Buchstaben";
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
//    ui->tableWidget->setColumnWidth(0, ui->tableWidget->horizontalHeader()->length()/2);
//    ui->tableWidget->setColumnWidth(1, ui->tableWidget->horizontalHeader()->length()/2);
//    ui->tableWidget->setColumnWidth(2, ui->tableWidget->horizontalHeader()->length()/2);
    ui->tableWidget->horizontalHeader()->sortIndicatorOrder();
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("-1"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("-3"));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("-2"));
}
