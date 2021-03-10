#include "initializare.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
Initializare::Initializare()
{
    setTask();
    setIndicatori();
    setData();
    setDataEtape();
    setValori();
    setDateParcurs();
}
string Initializare::getTask(int i, int j)
{
    return Taskuri[i][j];
}
string Initializare::getInd(int i){
    return Indicatori[i];
}
int Initializare::getNumarInd()
{
    return NumarInd;
}
int Initializare::getNumarTask(int i)
{
    return NumarTask[i];
}
int Initializare::getNumarEtap(){
    return NumarEtap;
}
int Initializare::getValoare(int i,int j){
    return Valori[i][j];
}
float Initializare::getDHTask(int i,int j){
    float a=DHTask[i][j];
    a*=100;
    a=int(a);
    a/=100;
    return a;
}
float Initializare::getDHIndicator(int i)
{
    float a=DHIndicator[i];
    a*=100;
    a=int(a);
    a/=100;
    return a;
}
char * Initializare::getDataEtapa(int i){
    return dataEtapa[i];
}
char * Initializare::getDataParcurs(){
    return dataParcurs;
}
char *Initializare::getDataInitiala(){
    return dataInit;
}
char *Initializare::getDataFinala(){
    return dataFin;
}
void Initializare::setDateParcurs(){
    ifstream datain("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/DataParcurs.txt");
    datain>>dataParcurs;


    datain.close();
}
void Initializare::setData(){
    ifstream dataIn("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/DataProiectNou.txt");
    dataIn>>dataInit;
    dataIn>>dataFin;
    dataIn.close();
}
void Initializare::setIndicatori(){
    ifstream indicat("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/Indicatori.txt");
    indicat>>NumarInd;
    for(int i=0;i<NumarInd;i++)
        indicat>>Indicatori[i];
    indicat.close();
}
void Initializare::setTask()
{
    char text[100][100];
    int nr=0;
    ifstream taskin("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/Task.txt");
    taskin >> NumarInd;
    for (int i = 0; i < NumarInd; i++)
        {
            taskin >> NumarTask[i];
            nr+=NumarTask[i];
        }
    for (int i = 0; i < nr; i++)
            taskin.getline(text[i],50,',');

    taskin.close();
    for (int i = 0; i < nr; i++)
        {
            strlen(text[i]);
            while(text[i][0]==' '||text[i][0]=='\n')
                {
                    for(int j=0;j<strlen(text[i]);j++)
                        text[i][j]=text[i][j+1];
                }
           // cout<<text[i]<<endl;
        }
    stringstream copie;
    int index=0;
    for (int i = 0; i < NumarInd; i++)
        for (int j = 0; j <NumarTask[i]; j++)
                {
                    for(int k=0;k<strlen(text[index]);k++)
                        Taskuri[i][j]=Taskuri[i][j]+text[index][k];
                    index++;
                    //cout<<Taskuri[i][j]<<endl;
                }
}
void Initializare::setDataEtape(){
    ifstream datain("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/Date.txt");
    datain>>NumarEtap;
    for(int i=0;i<NumarEtap;i++)
            datain>>dataEtapa[i];
    datain.close();
}
void Initializare::setValori(){
    ifstream fin("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/Valori.txt");
    for(int i=0;i<NumarInd;i++)
        for(int j=0;j<NumarTask[i];j++)
            fin>>Valori[i][j];
    fin.close();
}
void Initializare::setPreluareValori(int a[100][100]){
    for(int i=0;i<NumarInd;i++)
        for(int j=0;j<NumarTask[i];j++)
            {
            Valori[i][j]=Valori[i][j]+a[i][j];
            if(Valori[i][j]>100)
                Valori[i][j]=100;
            }
    ofstream fout("C:/Users/user/Desktop/An II ACS/ProiectVar5/ProiectNOU9/Valori.txt");
    for(int i=0;i<NumarInd;i++){
        for(int j=0;j<NumarTask[i];j++)
            fout<<Valori[i][j]<<" ";
        fout<<endl;
        }
    fout.close();
    setDHTask();
    setDHIndicatori();
}
void Initializare::setDHTask(){
    for(int i=0;i<NumarInd;i++)
        for(int j=0;j<NumarTask[i];j++)
            DHTask[i][j]=float(100-Valori[i][j])/float(100);

}
void Initializare::setDHIndicatori(){
    int suma=0;
    for(int i=0;i<NumarInd;i++)
        {
            suma=0;
            for(int j=0;j<NumarTask[i];j++)
                suma+=Valori[i][j];
            DHIndicator[i]=float(100*NumarTask[i]-suma)/float(100*NumarTask[i]);
        }
}
void Initializare::ConvertCharToString(char *a, string b){
    for(int i=0;i<int(strlen(a));i++)
        b=b+a[i];
}
float Initializare::getParcursIndicator(int i){
    int suma=0;
    float var;
    for(int j=0;j<NumarTask[i];j++)
        suma=suma+Valori[i][j];

    var=float(suma)/float(NumarTask[i]);
    var*=100;
    var=int(var);
    var/=100;
    return var;
}
