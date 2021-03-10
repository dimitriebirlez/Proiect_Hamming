#include "afisarestatutnou.h"
#include "ui_afisarestatutnou.h"
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include<string>
#include "initializare.h"

using namespace std;
int v2[100][100];
QVector <QLabel*>labelrezultatetask1[100];
QVector<QLabel*>labelrezultateind1;
int v1[100][100];
float valDHind[100];
AfisareStatutNou::AfisareStatutNou(QWidget *parent,int nrspel,int dif) :
    QMainWindow(parent),nrSpecial(nrspel),diferenta(dif),
    ui(new Ui::AfisareStatutNou)
{
    ui->setupUi(this);
    Initializare init;
    QVector<QLabel*> labelsindicatori;
    QVector<QLabel*> labels[100];
    QVector<QVBoxLayout*> layouts;
    QVector <QLabel*> labeletape;
    QVector<QVBoxLayout*> layoutsEtape;

    //QVector<QLabel*>labelsdate;
   // QVector<


    //label->setText("This is how i add a label");

    //label->setMinimumWidth(100);// You can set other properties similarly
    int i,j;
//    for(i=0;i<init.getNumarInd();i++){
//        layouts.append(new QHBoxLayout);
//        labelsindicatori.append(new QLabel);
//        labelsindicatori[i]->setText(QString::fromStdString(init.getInd(i)));
//        for(j=0;j<init.getNumarTask(i);j++){
//            labels.append(new QLabel);
//            labels[j]->setText(QString::fromStdString(init.getTask(i,j)));
//        }
//    }

for(i=0;i<init.getNumarInd();i++)
{
    cout<<init.getInd(i)<<" ";
    labelrezultateind1.append(new QLabel);
    labelrezultateind1[i]->setText(QString::number(0)+QString::fromStdString("/100"));

    for(j=0;j<init.getNumarTask(i);j++){
       labelrezultatetask1[i].append(new QLabel);
       labelrezultatetask1[i][j]->setText(QString::number(0)+QString::fromStdString("/100"));
       //d++;
       //cout<<init.getTask(i,j)<<" ";}
            }
}
//int v2[100][100];
for(i=0;i<100;i++)
    for(j=0;j<100;j++)
        v2[i][j]=0;
init.setPreluareValori(v2);
    for(i=0;i<init.getNumarInd();i++)
    {
        cout<<init.getInd(i)<<" ";
        valDHind[i]=init.getDHIndicator(i);
        labelsindicatori.append(new QLabel);
        labelsindicatori[i]->setText(QString::fromStdString(init.getInd(i)));

        for(j=0;j<init.getNumarTask(i);j++)
        {
            labels[i].append(new QLabel);
            labels[i][j]->setText(QString::fromStdString(init.getTask(i,j)));
        //d++;
        //cout<<init.getTask(i,j)<<" ";}
        }
    }

    for(i=0;i<init.getNumarInd();i++)
    {
        layouts.append(new QVBoxLayout);
        //layouts[i]->addLayout(new QHBoxLayout);
        layouts[i]->addWidget(labelsindicatori[i]);
        layouts[i]->addWidget(labelrezultateind1[i]);
        layouts[i]->addSpacing(100);
        for(j=0;j<init.getNumarTask(i);j++)
        {
             //layouts[i]->addSpacing(100);
            layouts[i]->addWidget(labels[i][j]);
            //layouts[i]->addWidget(lineedits[i][j]);
            layouts[i]->addWidget(labelrezultatetask1[i][j]);
            layouts[i]->addSpacing(100);

        }
        layouts[i]->addStretch(100);
    }
//    QString dateSpeciala;
//    string dataSpeciala222;
//    ifstream fin("D:/Facultate/Anul 2/Sem 1/ProiectNOU9/DataSpeciala.txt");
//       fin>>dataSpeciala222;
//    fin.close();
//    dateSpeciala=QString::fromStdString(dataSpeciala222);
//    char *DataCopie;
//    DataCopie=&dataSpeciala222[0];
//    //cout<<dataSpeciala222<<"\n\n";
//    //cout<<"\n\n"<<DataCopie;
//    int nrSpecial=0;
//    for(i=0;i<init.getNumarEtap();i++)
//    {
//        //cout<<endl<<getDifference(return_schimb(init.getDataEtapa(i)),return_schimb(DataCopie))<<endl;
//        if(0>getDifference(return_schimb(init.getDataEtapa(i)),return_schimb(DataCopie)))
//        {
//            nrSpecial=i+1;
//            break;
//        }
//   }

    float calcul=0;
    calcul=(100/init.getNumarEtap())*nrSpecial;
    labeletape.append(new QLabel);
    labeletape[0]->setText("Gradele de implementare ale task-urilor si indicatorilor in urma adaugarii valorilor de astazi ");
    labeletape.append(new QLabel);
    labeletape[1]->setText("Conform numarului etapei, indicatoarele ar trebui sa aiba valori mai mari de "+QString::number(calcul));
    labeletape.append(new QLabel);
    labeletape[2]->setText("x/100 - procentajul realizat din acel "
"task/indicator\nDH:y - Distanta Hamming dintre indicator/task actual si valoarea ideala");
    float medie;
    for(i=0;i<init.getNumarInd();i++){
        //valIndparc[i]=init.getParcursIndicator(i);
        //nume_ind[i]=init.getInd(i);
        medie=medie+init.getParcursIndicator(i);
    }
medie=medie/init.getNumarInd();
    labeletape.append(new QLabel);
    labeletape[3]->setText("Etapa curenta: "+QString::number(nrSpecial));
    labeletape.append(new QLabel);
    labeletape[4]->setText("Numar zile pana la final: "+QString::number(diferenta));
   labeletape.append(new QLabel);
   int nr=0;
   int suma=0;
   for(i=0;i<init.getNumarInd();i++)
   {
       for(j=0;j<init.getNumarTask(i);j++)
       {
           suma+=init.getValoare(i,j);
       }
   nr+=init.getNumarTask(i);
   }
   float DH;
   DH=float(100*nr-suma)/float(100*nr);
    if(medie!=100)
    labeletape[5]->setText("Proiect (x/100): "+QString::number(medie)+"/100 DH:"+
                           QString::number(DH));
    else
        labeletape[5]->setText("Proiect (x/100): "+QString::number(medie)+"/100 DH:"+QString::number(DH)+
" Felicitari toti indicatorii "
"au fost indepliniti!!!!");


    for(i=0;i<6;i++){
        layoutsEtape.append(new QVBoxLayout);
        layoutsEtape[i]->addWidget(labeletape[i]);
    }
//    layoutsEtape[2]->addSpacing(150);
    for(i=0;i<6;i++){
        ui->verticalLayout->addLayout(layoutsEtape[i]);

    }

    for(i=0;i<init.getNumarInd();i++){
        //ui->verticalLayout->addLayout(layouts[i]);
        ui->horizontalLayout->addLayout(layouts[i]);
            }
 //Scriere informatii in labels
    init.setPreluareValori(v1);
    for(i=0;i<init.getNumarInd();i++)
    {   labelrezultateind1[i]->setText(QString::number(init.getParcursIndicator(i))+
                     QString::fromStdString("/100  DH:")+QString::number(init.getDHIndicator(i)));
        for(j=0;j<init.getNumarTask(i);j++)
            labelrezultatetask1[i][j]->setText(QString::number(init.getValoare(i,j))+
                        QString::fromStdString("/100  DH:")+QString::number(init.getDHTask(i,j)));
    }

}

AfisareStatutNou::~AfisareStatutNou()
{
    delete ui;
}

void AfisareStatutNou::on_pushButton_clicked()
{
    Initializare init3;
    float valIndparc[100];
    string nume_ind[100];
    float medie=0;
    int i;
    for(i=0;i<init3.getNumarInd();i++){
        valIndparc[i]=init3.getParcursIndicator(i);
        nume_ind[i]=init3.getInd(i);
        medie=medie+init3.getParcursIndicator(i);
    }

    medie=medie/init3.getNumarInd();
    cout<<endl;
    cout<<medie<<endl;
    cout<<valDHind[0]<<endl;

    afisaregrafica=new AfisareGrafica(this,valIndparc,medie,init3.getNumarInd(),nume_ind,nrSpecial,init3.getNumarEtap());
    afisaregrafica->show();
}
