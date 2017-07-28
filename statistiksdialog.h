#ifndef STATISTIKSDIALOG_H
#define STATISTIKSDIALOG_H

#include <QDialog>

namespace Ui {
class StatistiksDialog;
}

class StatistiksDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatistiksDialog(QWidget *parent = 0);
    ~StatistiksDialog();

private slots:

private:
    Ui::StatistiksDialog *ui;
    void inittable();
    QList<QString> readstats();
};

#endif // STATISTIKSDIALOG_H
