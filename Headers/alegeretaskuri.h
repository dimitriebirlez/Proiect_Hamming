#ifndef ALEGERETASKURI_H
#define ALEGERETASKURI_H
#include <iostream>
#include <QMainWindow>
#include "alegeredate.h"
using namespace std;
namespace Ui {
class AlegereTaskuri;
}

class AlegereTaskuri : public QMainWindow
{
    Q_OBJECT

public:
    string *indicatori;
    int nr_indicatori;
    explicit AlegereTaskuri(QWidget *parent = nullptr,string *ind=0,int nr_indicatori=0);
    ~AlegereTaskuri();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AlegereTaskuri *ui;
    AlegereDate *alegeredate;
};

#endif // ALEGERETASKURI_H
