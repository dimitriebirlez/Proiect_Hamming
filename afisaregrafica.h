#ifndef AFISAREGRAFICA_H
#define AFISAREGRAFICA_H

#include <QMainWindow>
#include <iostream>
using namespace std;
namespace Ui {
class AfisareGrafica;
}

class AfisareGrafica : public QMainWindow
{
    Q_OBJECT

public:
    float *indicatori;
    float indicatormedie;
    int nr_indicatori;
    string *nume_indicatori;
    int nrSpc;
    int nrEtape;
    explicit AfisareGrafica(QWidget *parent = nullptr, float *ind=0,float indmed=0,int nr_ind=0,string *nume_ind=0,int nrSp=0,int nrEtp=0);
    ~AfisareGrafica();

private:
    Ui::AfisareGrafica *ui;
};

#endif // AFISAREGRAFICA_H
