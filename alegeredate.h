#ifndef ALEGEREDATE_H
#define ALEGEREDATE_H

#include <QMainWindow>
#include "proiectexistent.h"
namespace Ui {
class AlegereDate;
}

class AlegereDate : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlegereDate(QWidget *parent = nullptr);
    ~AlegereDate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AlegereDate *ui;
    ProiectExistent *proiectexistent;
};

#endif // ALEGEREDATE_H
