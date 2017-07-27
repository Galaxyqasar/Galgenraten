#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "popupdialog.h"
#include "statistiksdialog.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <QString>
#include <QList>
#include <QStringList>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QFontDatabase>

QString input, word, guessed, wrong;
QList<QString> wordlist, stats;
int i, length, wrongcount = 0, rigthcount = 0, score = 0;
bool restartb;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    ui->setupUi(this);
    ui->Gallow->setFont(fixedFont);
    ui->Gallow->setText("          /\\ \n"\
                        "         /  \\ \n"\
                        "        /    \\ \n"\
                        "       /      \\ \n"\
                        "      /        \\ \n"\
                        "     /   /---\\  \\ \n"\
                        "    /   <  0  >  \\ \n"\
                        "   /     \\---/    \\ \n"\
                        "  /                \\ \n"\
                        " /                  \\ \n"\
                        "/____________________\\ ");
    word = select(split(loadfile("woerter.csv")));
    ui->test->setText(word);
    length = word.length();
    for(i=0;i<length-2;i++)
        guessed.append("-");
    ui->Guessed->setText(guessed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Submit_clicked()
{
    maingame();
}

void MainWindow::on_Input_returnPressed()
{
    maingame();
}

QList<QString> MainWindow::readstats()
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

QList<QString> MainWindow::addtolist(QList<QString> list, QString string)
{
    list.append(string+"\n");
    return list;
}

void MainWindow::writestats(QList<QString> stats)
{
    QString tmp;
    for(int i = 0;stats.size()>i;i++)
        tmp.append(stats.at(i));
    QFile f("stats.txt");
    f.open(QIODevice::WriteOnly);
    f.write(tmp.toLatin1().data());
    f.close();
}

QString MainWindow::loadfile(QString filename)
{
    QFile file(filename);
    QTextStream in(&file);
    QString text;
    if(file.open(QIODevice::ReadOnly))
    {
        text = in.readAll();
        return text;
    }
    else
        printf("no file");
    return text;
}

QList<QString> MainWindow::split(QString sourcetext)
{
    QList<QString> list;
    list = sourcetext.split(";", QString::KeepEmptyParts, Qt::CaseSensitive);
    return list;
}

QString MainWindow::select(QList<QString> list)
{
    srand((unsigned)time(NULL));
    int line = (rand()%934+1);
    QString text;
    text = list.at(line);
    return text;
}

void MainWindow::loosed()
{
    score = score-3;
    QString stat, tmp, tmp2;
    tmp = QString::number(rigthcount);
    if(tmp.size()<2)
        tmp.append(" ");
    tmp2 = QString::number(score);
    if(tmp2.size()<2)
        tmp2.append(" ");
    if(tmp2.size()<3)
        tmp2.append(" ");
    stat = "verloren-:-richtige Buchstaben:"+tmp+"-:-Score:"+tmp2+";";
    writestats(addtolist(readstats(), stat));
    ui->Gallow->setText("          /\\ \n"\
                        "         /  \\ \n"\
                        "        /    \\ \n"\
                        "       /      \\ \n"\
                        "      /        \\ \n"\
                        "     /   /---\\  \\ \n"\
                        "    /   <  0  >  \\ \n"\
                        "   /     \\---/    \\ \n"\
                        "  /    _________    \\ \n"\
                        " /    /         \\   \\ \n"\
                        "/____________________\\ ");
    QFile f("tmp.txt");
    f.open(QIODevice::WriteOnly);
    f.write(tr("Sie haben verloren.\nWollen sie erneut spielen?").toLatin1().data());
    f.close();
    PopUpDialog a;
    restartb = a.exec();
    if(restartb)
        restart();
    else
        qApp->quit();
}

void MainWindow::won()
{
    score = score+3;
    QString stat, tmp, tmp2;
    tmp = QString::number(wrongcount);
    if(tmp.size()<2)
        tmp.append(" ");
    tmp2 = QString::number(score);
    if(tmp2.size()<2)
        tmp2.append(" ");
    tmp2.append(" ");
    stat = "gewonnen-:-falsche Buchstaben :"+tmp+"-:-Score:"+tmp2+";";
    writestats(addtolist(readstats(), stat));
    ui->Gallow->setText("          /\\ \n"\
                        "         /  \\ \n"\
                        "        /    \\ \n"\
                        "       /      \\ \n"\
                        "      /        \\ \n"\
                        "     /   /---\\  \\ \n"\
                        "    /   <  0  >  \\ \n"\
                        "   /     \\---/    \\ \n"\
                        "  /                \\ \n"\
                        " /    \\_________/   \\ \n"\
                        "/____________________\\ ");
    QFile f("tmp.txt");
    f.open(QIODevice::WriteOnly);
    f.write(tr("Sie haben gewonnen.\nWollen sie erneut spielen?").toLatin1().data());
    f.close();
    PopUpDialog a;
    restartb = a.exec();
    if(restartb)
        restart();
    else
        qApp->quit();
}

void MainWindow::maingame()
{
    input = ui->Input->text().toUpper();
    ui->Input->setText("");
    if(word.contains(input, Qt::CaseInsensitive))
    {
        for(i = 0;i<length;i++)
        {
            if(word.at(i) == input)
                guessed.replace(i-2, 1, word.at(i));
        }
        ui->Guessed->setText(guessed);
        rigthcount = rigthcount+1;
        score = score+1;
    }
    else
    {
        ui->Wrong->setText(ui->Wrong->text().append(input+"  "));
        wrongcount = wrongcount+1;
        score = score-1;
    }
    QFont font = ui->Gallow->font();
    switch(wrongcount)
    {
        case 1:
        {
            ui->Gallow->setText(" ┌─────────────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 2:
        {
            ui->Gallow->setText("          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 3:
        {
            ui->Gallow->setText("          ┌──────────\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 4:
        {
            ui->Gallow->setText("          ┌───┬──────\n"\
                   "          │ ┌─┘\n"\
                   "          ├─┘\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 5:
        {
            ui->Gallow->setText("          ┌───┬─────┬─\n"\
                   "          │ ┌─┘     │\n"\
                   "          ├─┘       │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 6:
        {
            ui->Gallow->setText("          ┌───┬─────┬─\n"\
                   "          │ ┌─┘     │\n"\
                   "          ├─┘      ┌┴─┐\n"\
                   "          │        │  │\n"\
                   "          │        └──┘\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 7:
        {
            ui->Gallow->setText("          ┌───┬─────┬─\n"\
                   "          │ ┌─┘     │\n"\
                   "          ├─┘      ┌┴─┐\n"\
                   "          │        │  │\n"\
                   "          │        └┬─┘\n"\
                   "          │         │\n"\
                   "          │         │\n"\
                   "          │\n"\
                   "          │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 8:
        {
            ui->Gallow->setText("          ┌───┬─────┬─\n"\
                   "          │ ┌─┘     │\n"\
                   "          ├─┘      ┌┴─┐\n"\
                   "          │        │  │\n"\
                   "          │        └┬─┘\n"\
                   "          │         │\n"\
                   "          │         │\n"\
                   "          │        ┌┴┐\n"\
                   "          │        │ │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 9:
        {
            ui->Gallow->setText("          ┌───┬─────┬─\n"\
                   "          │ ┌─┘     │\n"\
                   "          ├─┘      ┌┴─┐\n"\
                   "          │        │  │\n"\
                   "          │        └┬─┘\n"\
                   "          │        ┌┼┐\n"\
                   "          │        │││\n"\
                   "          │        ┌┴┐\n"\
                   "          │        │ │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            break;
        }
        case 10:
        {
            ui->Gallow->setText("          ┌───┬─────┬─\n"\
                   "          │ ┌─┘     │\n"\
                   "          ├─┘      ┌┴─┐\n"\
                   "          │        │xx│\n"\
                   "          │        └┬─┘\n"\
                   "          │        ┌┼┐\n"\
                   "          │        │││\n"\
                   "          │        ┌┴┐\n"\
                   "          │        │ │\n"\
                   "          │\n"\
                   " ┌────────┴────────┐\n"\
                   "─┘                 └─\n\n");
            loosed();
            break;
        }
    }
    font.setBold(true);
    ui->Gallow->setFont(font);
    if(guessed.contains(word) || word.contains(guessed))
        won();
}

void MainWindow::restart()
{
    resetdata();
    ui->Gallow->setText("          /\\ \n"\
                        "         /  \\ \n"\
                        "        /    \\ \n"\
                        "       /      \\ \n"\
                        "      /        \\ \n"\
                        "     /   /---\\  \\ \n"\
                        "    /   <  0  >  \\ \n"\
                        "   /     \\---/    \\ \n"\
                        "  /                \\ \n"\
                        " /                  \\ \n"\
                        "/____________________\\ ");
    word = select(split(loadfile("woerter.csv")));
    ui->test->setText(word);
    length = word.length();
    for(i=0;i<length-2;i++)
        guessed.append("-");
    ui->Guessed->setText(guessed);

}

void MainWindow::resetdata()
{
    ui->Wrong->setText("Falsche Buchstaben:\n");
    input.clear();
    word.clear();
    guessed.clear();
    wrong.clear();
    wordlist.clear();
    i = 0;
    length = 0;
    wrongcount = 0;
    rigthcount = 0;
    score = 0;
}

void MainWindow::on_actionStatistiken_triggered()
{
    StatistiksDialog a;
    a.exec();
}

void MainWindow::on_actionInfo_triggered()
{
    QFile f("tmp.txt");
    f.open(QIODevice::WriteOnly);
    f.write(tr("Info").toLatin1().data());
    f.close();
    PopUpDialog a;
    a.exec();
}

void MainWindow::on_actionCredits_triggered()
{
    QFile f("tmp.txt");
    f.open(QIODevice::WriteOnly);
    f.write(tr("Credits").toLatin1().data());
    f.close();
    PopUpDialog a;
    a.exec();
}

void MainWindow::on_actionNeues_Spiel_triggered()
{
    restart();
}

void MainWindow::on_actionBeenden_triggered()
{
    qApp->quit();
}

