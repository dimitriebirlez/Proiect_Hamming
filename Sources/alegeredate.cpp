#include "alegeredate.h"
#include "ui_alegeredate.h"
#include <iostream>
#include <QMessageBox>
#include<fstream>
#include"initializare.h"
using namespace std;
int z=0;
QString date[100];
string date1[100];
AlegereDate::AlegereDate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlegereDate)
{
    ui->setupUi(this);
    QDate data=QDate::currentDate();
    ui->dateEdit->setDate(data);
    //ui->label->setText("Introduceti data finala pentru etapa 1");
}

AlegereDate::~AlegereDate()
{
    delete ui;
}

void AlegereDate::on_pushButton_clicked()
{
    int nr_etape;
    nr_etape=ui->spinBox->value();
    date[z]=ui->dateEdit->text();
    date1[z]=date[z].toLocal8Bit().constData();
    QMessageBox::information(this,"Adaugare data","Data cu numarul "+QString::number(z+1)+" a fost adaugata. Selectati in casuta data urmatoare");
    //ui->label->setText("Introduceti data finala pentru etapa "+QString::number(z+1));
    //ui->dateEdit->);
    if(z<nr_etape-1)
        z++;
    else{
        QMessageBox::information(this,"Adaugare data","Au fost introdusa data finala: "+date[z]);
       /* alegeretaskuri=new AlegereTaskuri(this,indicatori1,nr_indicatori);
        alegeretaskuri->show();*/}
    ofstream datefisier("Date.txt");
    datefisier<<nr_etape<<endl;
    for(int i=0;i<nr_etape;i++)
        datefisier<<date1[i]<<endl;
    datefisier.close();
}

void AlegereDate::on_pushButton_2_clicked()
{
    string data;
    QDate date;
    date=ui->dateEdit->date();
    QString copie=date.toString();
    data=copie.toStdString();
    ofstream fout("DataParcurs.txt");
    fout<<data<<endl;
    fout.close();
    hide();
    proiectexistent = new ProiectExistent;
    proiectexistent->show();
}
