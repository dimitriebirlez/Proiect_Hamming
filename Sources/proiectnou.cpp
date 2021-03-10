#include "proiectnou.h"
#include "ui_proiectnou.h"
#include "fstream"
#include <iostream>
#include<QDate>
#include<fstream>
using namespace std;
QString text;
//QString date;
ProiectNou::ProiectNou(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProiectNou)
{

    ui->setupUi(this);
//    QDate data=QDate::currentDate();
//    ui->dateEdit->setDate(data);
//    ui->label_data->setText(data.toString("dd-MM-yyyy"));

}

ProiectNou::~ProiectNou()
{
    delete ui;
}

void ProiectNou::on_pushButton_clicked()
{
    ofstream datainit("DataProiectNou.txt");
    string nume;
    QString qtnume,qtdata;
    qtnume = ui->lineEdit_nume->text();
    int nr_indicatori=ui->spinBox_indicatori->value();
    nume =qtnume.toStdString();
    cout<<nume;
    ofstream fout("Nume.txt");
       fout<<nume<<",";
    fout.close();
    //data initiala
    QDate datain=QDate::currentDate();
    qtdata=datain.toString("dd-MM-yyyy");
    datainit<<qtdata.toStdString()<<endl;

    //data finala
//     QString datafin=ui->dateEdit->text();
//    datainit<<datafin.toStdString()<<endl;
//    datainit.close();

    hide();
    alegereindicatori = new AlegereIndicatori(this,nr_indicatori,nume);
    alegereindicatori->show();
}

//void ProiectNou::on_textEdit_copyAvailable(bool b)
//{

//}
