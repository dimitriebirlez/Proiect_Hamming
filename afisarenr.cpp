#include "afisarenr.h"
#include "ui_afisarenr.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include "mainwindow.h"
#include <QTextStream>
#include <QMainWindow>
#include <QStandardItemModel>
AfisareNr::AfisareNr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfisareNr)
{
    ui->setupUi(this);
    ui->label_2->setText(QString::number(3));
}

AfisareNr::~AfisareNr()
{
    delete ui;
}
