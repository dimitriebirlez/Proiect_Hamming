#include "alegeretaskuri.h"
#include "ui_alegeretaskuri.h"
#include <QMessageBox>
#include <iostream>
#include<fstream>
using namespace std;
QString taskuri[100][100];
string taskuri1[100][100];
int aux=0;
int j=0;
int ind_task=0;
int x=0;
int nr_taskuri[100];
using namespace std;

AlegereTaskuri::AlegereTaskuri(QWidget *parent, string *ind,int nr_ind) :
    QMainWindow(parent),indicatori(ind),nr_indicatori(nr_ind),
    ui(new Ui::AlegereTaskuri)
{

    ui->setupUi(this);
    ui->label_2->setText(QString::fromStdString("Indicatorul ")+
                       QString::number(1)+QString::fromStdString(" Taskul ")
                        +QString::number(1));
}


AlegereTaskuri::~AlegereTaskuri()
{
    delete ui;
}

void AlegereTaskuri::on_pushButton_clicked()
{


     nr_taskuri[aux]=ui->spinBox->value();
     taskuri[ind_task][j]=ui->textEdit->toPlainText();
     taskuri1[ind_task][j]=taskuri[ind_task][j].toLocal8Bit().constData();
     QMessageBox::information(this,"Adaugare indicator","Indicatorul cu numarul "+QString::number(aux+1)+" a fost adaugat.");
     ui->textEdit->setText("");
     ui->label->setText(QString::fromStdString("Indicatorul ")+
                        QString::number(aux+1));
     ui->label_2->setText(QString::fromStdString("Indicatorul ")+
                        QString::number(aux+1)+QString::fromStdString(" Taskul ")
                         +QString::number(j+2));
     if(j<nr_taskuri[aux]-1&&ind_task<nr_indicatori)
         j++;
     else if(j>=nr_taskuri[aux]-1&&ind_task<nr_indicatori-1){
         QMessageBox::information(this,"Adaugare indicator","Au fost introdusi toate taskurile pentru indicatorul "+QString::number(ind_task+1));
         ui->spinBox->setValue(0);
         aux++;
         j=0;
         ind_task++;
         ui->label_2->setText(QString::fromStdString("Indicatorul ")+
                            QString::number(ind_task+1)+QString::fromStdString(" Taskul ")
                             +QString::number(1));

           }
     else if(ind_task>=nr_indicatori-1){
          QMessageBox::information(this,"","Au fost introdusi toate taskurile pentru toti indicatorii");
          ofstream task("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/Task.txt");
          ofstream valori("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/Valori.txt");
          int a,b;
          task<<nr_indicatori<<" ";
          for(a=0;a<nr_indicatori;a++)
          task<<nr_taskuri[a]<<" ";
          task<<endl;
          for(a=0;a<nr_indicatori;a++)
          {
              for(b=0;b<nr_taskuri[a];b++)
                  {
                  //cout<<taskuri1[a][b]<<" ";
                  task<<taskuri1[a][b]<<","<<endl;
                  valori<<0<<" ";
                  }
               valori<<endl;
          }
               cout<<endl;

          valori.close();
          for(a=0;a<nr_indicatori;a++)
              cout<<nr_taskuri[a]<<endl;
          task.close();
//          ofstream taskrezultate("D:/Facultate/Anul 2/Sem 1/ProiectNOU9/Valori.txt");
//          //int c,d;
//          taskrezultate<<nr_indicatori<<endl;
//          for(a=0;a<nr_indicatori;a++)
//          //taskrezultate<<nr_taskuri[a]<<" ";
//          taskrezultate<<endl;
//          for(a=0;a<nr_indicatori;a++)
//              {for(b=0;b<nr_taskuri[a];b++)
//                  {
//                  //cout<<taskuri1[a][b]<<" ";
//                  taskrezultate<<0<<",";
//                  }
//               taskrezultate<<"."<<endl;
//              }
//               cout<<endl;


          for(a=0;a<nr_indicatori;a++)
              cout<<0<<endl;
          //taskrezultate.close();
     }
    //cout<<nr_taskuri<<endl;




}

void AlegereTaskuri::on_pushButton_2_clicked()
{
      hide();
      alegeredate=new AlegereDate();
      alegeredate->show();
}
