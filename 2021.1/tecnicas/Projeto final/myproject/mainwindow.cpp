#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QWidget>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double value;
    QChart *chart, *chart1, *chart2, *chart3;
    //QChartView *chartView, *chartView1, *chartView2, *chartView3;
    QSplineSeries *seriesA = new QSplineSeries(); // Alocando memória para a série SEN
    seriesA->setName("Corrente"); // setado o nome da série
    QSplineSeries *seriesB = new QSplineSeries(); // Alocando memória para a série COSSENO
    seriesB->setName("Temperatura Ambiente"); // setado o nome da série
    QSplineSeries *seriesC = new QSplineSeries(); // Alocando memória para a série COSSENO
    seriesB->setName("Tensão Bateria"); // setado o nome da série
    QSplineSeries *seriesD = new QSplineSeries(); // Alocando memória para a série COSSENO
    seriesB->setName("Temperatura Bateria"); // setado o nome da série
    QFile inputFile(ui->lineEdit_2->text());
    QString XMAX=ui->lineEdit->text();
    value = XMAX.toDouble();
    if(!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) qDebug() << "Arquivo não aberto"; else qDebug() << "Arquivo OK";
    QTextStream in(&inputFile);
    QString line = in.readLine(); // Ler primeira linha e descarta
    float x, y, z,j; char lixo; int k;
    for (k=0;k<value;k++) {
    in >> x;
    in >> lixo; // ler 1a ','
    in >> y;
    in >> lixo; // ler 2a ','
    in >> z;
    in >> lixo; // ler 3a ','
    in >> j;
    *seriesA << QPointF(k, x);
    *seriesB << QPointF(k, y);
    *seriesC << QPointF(k, z);
    *seriesD << QPointF(k, j);
    }
    inputFile.close();
    seriesA->setName("Corrente");
    seriesB->setName("Temperatura Ambiente");
    seriesC->setName("Tensão");
    seriesD->setName("Temperatura Bateria");
    chart = new QChart(); //Criando um gráfico CHART
    chart1 = new QChart();
    chart2 = new QChart();
    chart3 = new QChart();
    chart->addSeries(seriesA); //Adiconando cada série no gráfico
    chart->legend()->setVisible(true);
    chart->setTitle("Grafico Corrente");
    chart->createDefaultAxes();

    chart1->addSeries(seriesB);
    chart1->legend()->setVisible(true);
    chart1->setTitle("Grafico Temperatura Ambiente");
    chart1->createDefaultAxes();

    chart2->addSeries(seriesC);
    chart2->legend()->setVisible(true);
    chart2->setTitle("Grafico Tensão");
    chart2->createDefaultAxes();

    chart3->addSeries(seriesD);
    chart3->legend()->setVisible(true);
    chart3->setTitle("Grafico Temperatura Bateria");
    chart3->createDefaultAxes();

    //chartView = new QChartView(chart); //Criando o visualizador do gráfico CHART
    //chartView1 = new QChartView(chart1); //Criando o visualizador do gráfico CHART
    //chartView2 = new QChartView(chart2); //Criando o visualizador do gráfico CHART
    //chartView3 = new QChartView(chart3); //Criando o visualizador do gráfico CHART
    //chartView->setRenderHint(QPainter::Antialiasing); //"Amaciar as linhas (evitar degraus)
    ui->graphicsView->setChart(chart);
    ui->graphicsView_2->setChart(chart1);
    ui->graphicsView_3->setChart(chart2);
    ui->graphicsView_4->setChart(chart3);
}


void MainWindow::on_pushButton_2_clicked()
{
    double value; int x;
QFile inputFile(ui->lineEdit_2->text());
if(!inputFile.open(QIODevice::ReadOnly))
qDebug() << "Arquivo não aberto";
else
qDebug() << "Arquivo OK";
QString XMAX=ui->lineEdit->text();
value = XMAX.toDouble();
QTextStream in(&inputFile);
QString line = in.readLine();
ui->textEdit->setText(line);
for (x=0;x<value;x++) {
    QString line = in.readLine();
    ui->textEdit->append(line);
    qDebug() << line;

}

inputFile.close();
qDebug() << value;

}



void MainWindow::on_pushButton_3_clicked()
{
    double initial, final; int x;
QFile inputFile(ui->lineEdit_2->text());
if(!inputFile.open(QIODevice::ReadOnly))
qDebug() << "Arquivo não aberto";
else
qDebug() << "Arquivo OK";
QString XMAX=ui->lineEdit_3->text();
initial = XMAX.toDouble();
QString X=ui->lineEdit_4->text();
final = X.toDouble();
QTextStream in(&inputFile);
QString line = in.readLine();
ui->textEdit_2->setText(line);
for (x=initial/2;x<final/2;x++) {
    QString line = in.readLine();
    ui->textEdit_2->append(line);
    qDebug() << line;

}

inputFile.close();

}

