#include "afisarestatut.h"
#include "ui_afisarestatut.h"
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "initializare.h"


using namespace std;
//D:/Facultate/Anul 2/Sem 1/ProiectNOU4/
int diferenta;
struct Date {
    int d, m, y;
};


const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31 };

// This function counts number of
// leap years before the given date
int countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be
    // considered for the count of leap years
    // or not
    if (d.m <= 2)
        years--;

    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
    // multiple of 100.
    return years / 4
        - years / 100
        + years / 400;
}


int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'

    // initialize count using years and day
    long int n1 = dt1.y * 365 + dt1.d;

    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n2 - n1);
}

Date return_schimb(char date[])
{
    string zi{date[0],date[1]};
    string luna{date[3],date[4]};
    string an{date[6],date[7],date[8],date[9]};

     string::size_type sz;

    int zi_int = stoi(zi,&sz);
    int luna_int = stoi(luna,&sz);
    int an_int =  stoi(an,&sz);

    Date dt1={ zi_int, luna_int, an_int };
    return dt1;

}
int v[100][100];
QVector<QLineEdit*> lineedits[100];
QVector <QLabel*>labelrezultatetask[100];
QVector<QLabel*>labelrezultateind;
QVector <QLabel*> labeletape;
void ScriereFisier(){
    ofstream fout("D:/Facultate/Anul 2/Sem 1/ProiectNOU9/TextEtape.txt");
    Initializare init;
    for(int i=0;i<init.getNumarInd();i++){
        fout<<init.getInd(i)<<" ";
        fout<<init.getParcursIndicator(i)<<"/100"<<endl;
        for(int j=0;j<init.getNumarTask(i);j++)
        {
            fout<<init.getTask(i,j)<<" ";
            fout<<init.getValoare(i,j)<<endl;
        }
    }
    fout.close();
}
    int nrSpecial=0;
AfisareStatut::AfisareStatut(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AfisareStatut)
{

    ui->setupUi(this);
    Initializare init;
    QVector<QLabel*> labelsindicatori;
    QVector<QLabel*> labels[100];
    QVector<QVBoxLayout*> layouts;
    QVector<QVBoxLayout*> layoutsEtape;

int i,j;
for(i=0;i<init.getNumarInd();i++)
{
    cout<<init.getInd(i)<<" ";
    labelrezultateind.append(new QLabel);
    labelrezultateind[i]->setText(QString::number(0)+QString::fromStdString("/100"));

    for(j=0;j<init.getNumarTask(i);j++)
    {
       labelrezultatetask[i].append(new QLabel);
       labelrezultatetask[i][j]->setText(QString::number(0)+QString::fromStdString("/100"));
       //d++;
       //cout<<init.getTask(i,j)<<" ";}
    }
}

    for(i=0;i<init.getNumarInd();i++)
    {
        cout<<init.getInd(i)<<" ";
        labelsindicatori.append(new QLabel);
        labelsindicatori[i]->setText(QString::fromStdString(init.getInd(i)));

        for(j=0;j<init.getNumarTask(i);j++)
        {
            labels[i].append(new QLabel);
            lineedits[i].append(new QLineEdit);
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
        layouts[i]->addWidget(labelrezultateind[i]);
        layouts[i]->addSpacing(100);
        for(j=0;j<init.getNumarTask(i);j++)
        {
             //layouts[i]->addSpacing(100);
            layouts[i]->addWidget(labels[i][j]);
            layouts[i]->addWidget(lineedits[i][j]);
            layouts[i]->addWidget(labelrezultatetask[i][j]);
            layouts[i]->addSpacing(100);

        }
        layouts[i]->addStretch(100);
    }
    QString dateSpeciala;
    string dataSpeciala222;
    ifstream fin("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/DataSpeciala.txt");
       fin>>dataSpeciala222;
    fin.close();
    dateSpeciala=QString::fromStdString(dataSpeciala222);
    char *DataCopie;
    DataCopie=&dataSpeciala222[0];
    //cout<<dataSpeciala222<<"\n\n";
    //cout<<"\n\n"<<DataCopie;

    for(i=0;i<init.getNumarEtap();i++)
    {
        //cout<<endl<<getDifference(return_schimb(init.getDataEtapa(i)),return_schimb(DataCopie))<<endl;
        if(0>getDifference(return_schimb(init.getDataEtapa(i)),return_schimb(DataCopie)))
        {
            nrSpecial=i+1;
            break;
        }
   }



    labeletape.append(new QLabel);
    labeletape[0]->setText("Conform datei va aflati in etapa: "+QString::number(nrSpecial));
    labeletape.append(new QLabel);
    labeletape[1]->setText("Rezultatele de pana acum in etapele anterioare se afla sub fiecare task/indicator. Fiecare indicator este modificat de taskurile aferente.");
    labeletape.append(new QLabel);
    labeletape[2]->setText("x/100 - procentajul realizat din acel task/indicator\nDH:y - Distanta Hamming dintre indicator/task actual si valoarea ideala");
    labeletape.append(new QLabel);
    labeletape[3]->setText("Introduceti pentru fiecare task evolutia (numarul procentajului) fiecarui task fata de etapa anterioara\n");
    labeletape.append(new QLabel);
    labeletape[4]->setText("\n--------------------------------------------------------------------------------------------------------------\n\n ");
    for(i=0;i<5;i++){
        layoutsEtape.append(new QVBoxLayout);
        layoutsEtape[i]->addWidget(labeletape[i]);
    }
    //layoutsEtape[3]->addSpacing(30);
    for(i=0;i<5;i++){
        ui->verticalLayout->addLayout(layoutsEtape[i]);

    }


    for(i=0;i<init.getNumarInd();i++){
        //ui->verticalLayout->addWidget();
        ui->horizontalLayout->addLayout(layouts[i]);
            }
 //Scriere informatii in labels
    init.setPreluareValori(v);
    for(i=0;i<init.getNumarInd();i++)
    {   labelrezultateind[i]->setText(QString::number(init.getParcursIndicator(i))+
                     QString::fromStdString("/100  DH:")+QString::number(init.getDHIndicator(i)));
        for(j=0;j<init.getNumarTask(i);j++)
            labelrezultatetask[i][j]->setText(QString::number(init.getValoare(i,j))+
                        QString::fromStdString("/100  DH:")+QString::number(init.getDHTask(i,j)));
    }
 //DAtedadasdadasdasdasdasd

    diferenta=getDifference(return_schimb(DataCopie),return_schimb(init.getDataEtapa(init.getNumarEtap()-1)));




    QVector<QLabel*> dataInitiala;
    string datain,datafin;
//    init.ConvertCharToString(init.getDataInitiala(),datain);
//    init.ConvertCharToString(init.getDataFinala(),datafin);
//    ifstream fin("D:/Facultate/Anul 2/Sem 1/ProiectNOU4/DataProiectNou.txt");
//    fin>>datain>>datafin;
//    fin.close();
//    dataInitiala.append(new QLabel);
//    dataInitiala[0]->setText(QString::fromStdString(datain));
//    dataInitiala[1]->setText(QString::fromStdString(datafin));

    ScriereFisier();
   // ui->horizontalLayout->addLayout(layoutsEtape[0]);



}

AfisareStatut::~AfisareStatut()
{
    delete ui;
}

void AfisareStatut::on_pushButton_clicked()
{
    Initializare init2;
    int i,j;

    //Primul
    for(i=0;i<init2.getNumarInd();i++){
        for(j=0;j<init2.getNumarTask(i);j++)
            v[i][j]=lineedits[i][j]->text().toInt();
    }

    init2.setPreluareValori(v);
    for(i=0;i<init2.getNumarInd();i++)
    {   labelrezultateind[i]->setText(QString::number(init2.getParcursIndicator(i))+
                     QString::fromStdString("/100  DH:")+QString::number(init2.getDHIndicator(i)));
        for(j=0;j<init2.getNumarTask(i);j++)
            labelrezultatetask[i][j]->setText(QString::number(init2.getValoare(i,j))+
                        QString::fromStdString("/100  DH:")+QString::number(init2.getDHTask(i,j)));
    }

   // cout<<endl<<init2.getParcursIndicator(0);
    //Al doilea



        hide();
        afisarestatutnou=new AfisareStatutNou(this,nrSpecial,diferenta);
        afisarestatutnou->show();
}
