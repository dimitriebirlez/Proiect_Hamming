#ifndef AFISARESTATUTNOU_H
#define AFISARESTATUTNOU_H

#include <QMainWindow>
#include "afisaregrafica.h"

namespace Ui {
class AfisareStatutNou;
}

class AfisareStatutNou : public QMainWindow
{
    Q_OBJECT

public:
    int nrSpecial;
    int diferenta;
    explicit AfisareStatutNou(QWidget *parent = nullptr,int nrspel=0,int dif=0);
    ~AfisareStatutNou();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AfisareStatutNou *ui;
    AfisareGrafica *afisaregrafica;
};

#endif // AFISARESTATUTNOU_H
