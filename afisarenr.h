#ifndef AFISARENR_H
#define AFISARENR_H

#include <QDialog>

namespace Ui {
class AfisareNr;
}

class AfisareNr : public QDialog
{
    Q_OBJECT

public:
    explicit AfisareNr(QWidget *parent = nullptr);
    ~AfisareNr();

private:
    Ui::AfisareNr *ui;
};

#endif // AFISARENR_H
