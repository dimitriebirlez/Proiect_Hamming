#ifndef PROIECTNOU_H
#define PROIECTNOU_H

#include <QMainWindow>
#include "alegereindicatori.h"
namespace Ui {
class ProiectNou;
}

class ProiectNou : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProiectNou(QWidget *parent = nullptr);
    ~ProiectNou();

private slots:
  //  void on_textEdit_copyAvailable(bool b);

    void on_pushButton_clicked();

private:
    Ui::ProiectNou *ui;
    AlegereIndicatori *alegereindicatori;
};

#endif // PROIECTNOU_H
