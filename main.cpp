#include<iostream>
#include<fstream>
#include<string.h>
#include "mainwindow.h"
#include "afisarenr.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
using namespace std;

class Citire{
    private:
    int suma[100];
    int NumarEvaluari[100];
    int ideal;
    public:
    Citire();
    float DistantaHamming(int numar,int index);
    void DeterminareDistantaHamming();
};
Citire::Citire(){

    this->ideal=5;

    ifstream tabelin("C:/Users/user/Desktop/An II ACS/POO/Proiect4/Tabel.txt");
    int numar;
    int i;
    i=0;
    this->NumarEvaluari[i]=0;
    while(!tabelin.eof()){

        tabelin>>numar;

        if(numar==0)
            {
              //  tabelin>>numar;
                i++;
                cout<<endl;
            }
            else
        cout<<numar<<"\t";
        suma[i]+=numar;
        this->NumarEvaluari[i]++;
    }
    tabelin.close();
}
float Citire::DistantaHamming(int numar,int index){
    return float((this->NumarEvaluari[index]*this->ideal-suma[index])/suma[index]);
}

int main(int argc, char *argv[]){
    Citire citire;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

