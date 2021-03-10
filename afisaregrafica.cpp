#include "afisaregrafica.h"
#include "ui_afisaregrafica.h"
#include <QApplication>

// The main window to which you add toolbars,
// menubars, widgets and status bar
#include <QtWidgets/QMainWindow>

// Widget used to display charts
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE

#include <iostream>
using namespace std;
AfisareGrafica::AfisareGrafica(QWidget *parent,float *ind,float indmed,int nr_ind,string *nume_ind,int nrSp,int nrEtp) :
    QMainWindow(parent),indicatori(ind),indicatormedie(indmed),nr_indicatori(nr_ind),nume_indicatori(nume_ind),nrSpc(nrSp),nrEtape(nrEtp),
    ui(new Ui::AfisareGrafica)
{
    int i;
    float calcul;
    calcul=(100/nrEtp)*nrSpc;
    QBarSeries *series = new QBarSeries();
    QBarSet *set[100];
    for(i=0;i<nr_indicatori;i++){
        set[i]=new QBarSet(QString::fromStdString(nume_indicatori[i]));
    }
    set[i+1]=new QBarSet("Indicator Medie");
    set[i+2]=new QBarSet("Indicator Ideal");
    set[i+3]=new QBarSet("Indicator recomandat");
    for(i=0;i<nr_indicatori;i++){
        series->append(set[i]);
    }
    series->append(set[i+1]);
    series->append(set[i+2]);
    series->append(set[i+3]);

//    QBarSeries *series = new QBarSeries();
//    series->append(set0);
//    series->append(set1);
//    series->append(set2);
//    series->append(set3);
//    series->append(set4);
//    series->append(set5);
    QChart *chart = new QChart();
    //cout<<distanta[0];
    //*set0 << distanta[0]<<distanta[1]<<distanta[2]<<distanta[3]<<distantamedie;
//    *set0<<distanta[0];
//    *set1 << distanta[1];
//    *set2 << distanta[2];
//    *set3 << distanta[3];
//    *set4<<distanta[4];
//    *set5 <<0<<distantamedie;
    cout<<endl;
    cout<<indicatori[0];
    for(i=0;i<nr_indicatori;i++){
        *set[i]<<indicatori[i];
    }
    *set[i+1]<<0<<indicatormedie;
    *set[i+2]<<0<<0<<100;
    *set[i+3]<<0<<calcul;
//    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
//    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
//    *set3 << 248 << 244 << 265 << 281 << 278 << 313;

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Mediile pentru fiecare categorie si totala a distantelor, Valorile mai mici sunt mai bune");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    //categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";
    //categories<<"Compatibility"<<"Speed"<<"Design"<<"Security"<<"Accesibility";
    //categories<<"for each category"<<"overall";
    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    //axis->append(categories);
    //axis->append("Data read from excel file");
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart
    // chart->setAxisY(axis, series);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));


    qApp->setPalette(pal);
    setCentralWidget(chartView);
    resize(500,400);

   // ui->setupUi(this);
    //ui->setupUi(this);
}

AfisareGrafica::~AfisareGrafica()
{
    delete ui;
}
