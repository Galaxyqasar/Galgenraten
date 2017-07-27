#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Submit_clicked();

    void on_Input_returnPressed();

    void on_actionStatistiken_triggered();

    void on_actionInfo_triggered();

    void on_actionCredits_triggered();

    void on_actionNeues_Spiel_triggered();

    void on_actionBeenden_triggered();

private:
    Ui::MainWindow *ui;
    QString loadfile(QString filename);
    QList<QString> split(QString sourcetext);
    QString select(QList<QString>);
    void loosed();
    void won();
    void maingame();
    void restart();
    void resetdata();
    QList<QString> readstats();
    QList<QString> addtolist(QList<QString> list, QString string);
    void writestats(QList<QString> stats);
};

#endif // MAINWINDOW_H
