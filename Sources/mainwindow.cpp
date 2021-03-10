#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/poza.png");
    ui->label_pic->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    proiectnou= new ProiectNou(this);
    proiectnou->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    proiectexistent = new ProiectExistent;
    proiectexistent->show();
}

void MainWindow::on_pushButton_3_clicked()
{
     QMessageBox::information(this,"Help","Programul are doua variante de folosire:\nProiect Nou: initializarea indicatorilor, task-urilor si a etapelor pe baza nevoii utilizatorului\nProiect Existent: Deschide informatiile si gradul de implementare a unui proiect aflat deja in sistem.");
}
