#include "alegereindicatori.h"
#include "ui_alegereindicatori.h"
#include <QMessageBox>
#include <iostream>
#include<fstream>
using namespace std;
QString indicatori[100];
string indicatori1[100];
QString a;
int i=0;
AlegereIndicatori::AlegereIndicatori(QWidget *parent, int nr_ind,string num) :
    QMainWindow(parent),nr_indicatori(nr_ind),nume(num),
    ui(new Ui::AlegereIndicatori)
{
    //cout<<nr_indicatori;
    a=QString::number(nr_indicatori);
    //ui->label->setText(a);
    ui->setupUi(this);
    ui->label_2->setText(QString::fromStdString("Indicatorul(fara spatii) ")+QString::number(1));
}

AlegereIndicatori::~AlegereIndicatori()
{
    delete ui;
}

//void AlegereIndicatori::on_label_linkActivated(const QString &link)
//{

//}

void AlegereIndicatori::on_pushButton_clicked()
{
    indicatori[i]=ui->textEdit->toPlainText();
    indicatori1[i]=indicatori[i].toLocal8Bit().constData();
    QMessageBox::information(this,"Adaugare indicator","Indicatorul cu numarul "+QString::number(i+1)+" a fost adaugat.");
    ui->label_2->setText(QString::fromStdString("Indicatorul ")+QString::number(i+2));
    ui->textEdit->setText("");
    if(i<nr_indicatori-1)
        i++;
    else{
        QMessageBox::information(this,"Adaugare indicator","Au fost introdusi toti indicatorii");
        hide();
        alegeretaskuri=new AlegereTaskuri(this,indicatori1,nr_indicatori);
        alegeretaskuri->show();}
    ofstream indicatori("Indicatori.txt");
    indicatori<<nr_indicatori<<endl;
    for(int i=0;i<nr_indicatori;i++)
        indicatori<<indicatori1[i]<<endl;
    indicatori.close();
//    ofstream indicatorirezultate("Indicatorirezultate.txt");
//    indicatorirezultate<<nr_indicatori<<endl;
//    for(int i=0;i<nr_indicatori;i++)
//        indicatorirezultate<<0<<endl;
//    indicatorirezultate.close();
}
