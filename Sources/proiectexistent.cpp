#include "proiectexistent.h"
#include "ui_proiectexistent.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;
ProiectExistent::ProiectExistent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProiectExistent)
{

    ui->setupUi(this);
    QDate data=QDate::currentDate();
    ui->dateEdit->setDate(data);
    string nume;
    char name[100];
    ifstream fin("Nume.txt");
      fin.get(name,100,',');
    fin.close();
    for(int i=0;i<strlen(name);i++)
        nume=nume+name[i];
    ui->label_2->setText(QString::fromStdString(nume));
}

ProiectExistent::~ProiectExistent()
{
    delete ui;
}

void ProiectExistent::on_pushButton_clicked()
{
    string data;
    QDate date;

    date=ui->dateEdit->date();

    QString copie=date.toString("dd-MM-yyyy");
    data=copie.toStdString();

    ofstream fout("DataSpeciala.txt");
    fout<<data;
    fout.close();
    hide();
    afisarestatut = new AfisareStatut;
    afisarestatut->show();
}
