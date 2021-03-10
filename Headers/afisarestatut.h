#ifndef AFISARESTATUT_H
#define AFISARESTATUT_H

#include <QMainWindow>
#include"afisarestatutnou.h"
namespace Ui {
class AfisareStatut;
}

class AfisareStatut : public QMainWindow
{
    Q_OBJECT

public:
    explicit AfisareStatut(QWidget *parent = nullptr);
    ~AfisareStatut();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AfisareStatut *ui;
    AfisareStatutNou *afisarestatutnou;
};

#endif // AFISARESTATUT_H
