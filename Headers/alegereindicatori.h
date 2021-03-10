#ifndef ALEGEREINDICATORI_H
#define ALEGEREINDICATORI_H

#include <QMainWindow>
#include "alegeretaskuri.h"
namespace Ui {
class AlegereIndicatori;
}

class AlegereIndicatori : public QMainWindow
{
    Q_OBJECT

public:
    int nr_indicatori;
    string nume;
    explicit AlegereIndicatori(QWidget *parent = nullptr,int nr_ind=0,string nume="");
    ~AlegereIndicatori();

private slots:
   // void on_label_linkActivated(const QString &link);

    void on_pushButton_clicked();

private:
    Ui::AlegereIndicatori *ui;
    AlegereTaskuri *alegeretaskuri;
};

#endif // ALEGEREINDICATORI_H
