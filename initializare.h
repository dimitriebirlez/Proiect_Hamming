#ifndef INITIALIZARE_H
#define INITIALIZARE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
class Initializare
{
private:
    int NumarTask[100], NumarInd, NumarEtap,NumarParcurs;
    string Taskuri[100][100];
    string Indicatori[100];
    char dataInit[20], dataFin[20];
    char dataEtapa[100][100];
    char dataParcurs[100];
    int Valori[100][100];
    float DHTask[100][100];
    float DHIndicator[100];
public:
    void setTask();
    void setData();
    void setIndicatori();
    void setDataEtape();
    void setDateParcurs();
    void setValori();
    void setDHTask();
    void setDHIndicatori();
    void setPreluareValori(int a[100][100]);
    void ConvertCharToString(char a[],string b);
    char *getDataEtapa(int i);
    char *getDataParcurs();
    char *getDataInitiala();
    char *getDataFinala();
    string getTask(int i, int j);
    string getInd(int i);
    int getNumarInd();
    int getNumarTask(int i);
    int getNumarEtap();
    int getValoare(int i,int j);
    float getDHTask(int i,int j);
    float getDHIndicator(int i);
    float getParcursIndicator(int i);
    Initializare();
};

#endif // INITIALIZARE_H
