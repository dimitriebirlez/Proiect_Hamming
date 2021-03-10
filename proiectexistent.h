#ifndef PROIECTEXISTENT_H
#define PROIECTEXISTENT_H

#include <QMainWindow>
#include <afisarestatut.h>
#include<iostream>
#include<string>
namespace Ui {
class ProiectExistent;
}

class ProiectExistent : public QMainWindow
{
    Q_OBJECT

public:

    explicit ProiectExistent(QWidget *parent = nullptr);
    ~ProiectExistent();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProiectExistent *ui;
    AfisareStatut *afisarestatut;
};

#endif // PROIECTEXISTENT_H
