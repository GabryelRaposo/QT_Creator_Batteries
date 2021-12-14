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
    QSplineSeries *seriesA = new QSplineSeries(); //alocando memoria serie corrente
    seriesA->setName("Battery Current"); // setado o nome da série
    QSplineSeries *seriesB = new QSplineSeries();
    seriesB->setName("Room Temperature"); // setado o nome da série
    QSplineSeries *seriesC = new QSplineSeries();
    seriesC->setName("Battery Voltage"); // setado o nome da série
    QSplineSeries *seriesD = new QSplineSeries();
    seriesD->setName("Battery Temperature"); // setado o nome da série
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
    chart = new QChart(); //Criando um gráfico CHART
    chart1 = new QChart();
    chart2 = new QChart();
    chart3 = new QChart();
    chart->addSeries(seriesA); //Adiconando cada série no gráfico
    chart->legend()->setVisible(true);
    chart->setTitle("Battery Current");
    chart->createDefaultAxes();

    chart1->addSeries(seriesB);
    chart1->legend()->setVisible(true);
    chart1->setTitle("Room Temperature");
    chart1->createDefaultAxes();

    chart2->addSeries(seriesC);
    chart2->legend()->setVisible(true);
    chart2->setTitle("Battery Voltage");
    chart2->createDefaultAxes();

    chart3->addSeries(seriesD);
    chart3->legend()->setVisible(true);
    chart3->setTitle("Battery Temperature");
    chart3->createDefaultAxes();

    //chartView = new QChartView(chart); //Criando o visualizador do gráfico CHART
    //chartView1 = new QChartView(chart1); //Criando o visualizador do gráfico CHART
    //chartView2 = new QChartView(chart2); //Criando o visualizador do gráfico CHART
    //chartView3 = new QChartView(chart3); //Criando o visualizador do gráfico CHART
    //chartView->setRenderHint(QPainter::Antialiasing);
    //chartView1->setRenderHint(QPainter::Antialiasing);
    //chartView2->setRenderHint(QPainter::Antialiasing);
    //chartView3->setRenderHint(QPainter::Antialiasing);
    //"Amaciar as linhas (evitar degraus)
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
    ui->textEdit_2->clear();

    double t_inicial;
    double t_final = 0;
    uint64_t t_inicial_inteiro;
    uint64_t t_final_inteiro;
    QFile inputFile(ui->lineEdit_2->text());
    if(!inputFile.open(QIODevice::ReadOnly)){
        qDebug() << "Arquivo não aberto";
    } else {qDebug() << "Arquivo OK";}
    QString XMAX=ui->lineEdit_3->text();
    t_inicial = XMAX.toDouble();
    QString X=ui->lineEdit_4->text();
    t_final = X.toDouble();
    t_inicial_inteiro = t_inicial;
    if (t_final == (uint64_t)t_final){t_final_inteiro = t_final;}
    else {t_final_inteiro = t_final + 1;}
    QTextStream in(&inputFile);
    QString linha_importante = in.readLine();
    ui->textEdit_2->setText(linha_importante);
    double linha_inicial = 0;
    double linha_final = 0;
    if (t_inicial_inteiro % 2 == 0){
        linha_inicial = (t_inicial_inteiro + 2)/2;
    } else {
        linha_inicial = (t_inicial_inteiro + 1)/2;
    }
    if (t_final_inteiro % 2 == 0){
        linha_final = (t_final_inteiro + 2)/2;
    } else {linha_final = (t_final_inteiro + 3)/2;}

    uint64_t linha_corrente = 1;
    while (linha_corrente != linha_inicial){
        QString linha_lixo = in.readLine();
        linha_corrente += 1;
    }
    while (linha_corrente <= linha_final){
        QString linha_importante = in.readLine();
        ui->textEdit_2->append(linha_importante);
        qDebug() << linha_importante;

        linha_corrente += 1;
    }
inputFile.close();

}


void MainWindow::on_pushButton_4_clicked()
{
    double t_inicial;
    double t_final = 0;
    uint64_t t_inicial_inteiro;
    uint64_t t_final_inteiro;
    double value;
    QChart *chart, *chart1, *chart2, *chart3;
    //QChartView *chartView, *chartView1, *chartView2, *chartView3;
    QSplineSeries *seriesA = new QSplineSeries(); // Alocando memória para a série SEN
    seriesA->setName("Battery Current"); // setado o nome da série
    QSplineSeries *seriesB = new QSplineSeries(); // Alocando memória para a série COSSENO
    seriesB->setName("Room Temperature"); // setado o nome da série
    QSplineSeries *seriesC = new QSplineSeries(); // Alocando memória para a série COSSENO
    seriesC->setName("Battery Voltage"); // setado o nome da série
    QSplineSeries *seriesD = new QSplineSeries(); // Alocando memória para a série COSSENO
    seriesD->setName("Battery Temperature"); // setado o nome da série
    QFile inputFile(ui->lineEdit_2->text());
    if(!inputFile.open(QIODevice::ReadOnly)){
        qDebug() << "Arquivo não aberto";
    } else {qDebug() << "Arquivo OK";}
    QString XMAX=ui->lineEdit_3->text();
    t_inicial = XMAX.toDouble();
    QString X=ui->lineEdit_4->text();
    t_final = X.toDouble();
    t_inicial_inteiro = t_inicial;
    if (t_final == (uint64_t)t_final){t_final_inteiro = t_final;}
    else {t_final_inteiro = t_final + 1;}
    QTextStream in(&inputFile);
    QString linha_lixo = in.readLine();
    double linha_inicial = 0;
    double linha_final = 0;
    if (t_inicial_inteiro % 2 == 0){
        linha_inicial = (t_inicial_inteiro + 2)/2;
    } else {
        linha_inicial = (t_inicial_inteiro + 1)/2;
    }
    if (t_final_inteiro % 2 == 0){
        linha_final = (t_final_inteiro + 2)/2;
    } else {linha_final = (t_final_inteiro + 3)/2;}
    uint64_t linha_corrente = 1;
    while (linha_corrente != linha_inicial){
        QString linha_lixo = in.readLine();
        linha_corrente += 1;
    }
    float x, y, z,j; char lixo;
    float min_x = 10000, min_y = 10000, min_z = 10000, min_j = 10000;
    float max_x = 0, max_y = 0, max_z = 0, max_j = 0;
    float media_x = 0, media_y = 0, media_z = 0, media_j = 0;
    int n_iteracoes = 0;
        int k = linha_corrente;
        while (linha_corrente <= linha_final){
            in >> x;
            in >> lixo; // ler 1a ','
            in >> y;
            in >> lixo; // ler 2a ','
            in >> z;
            in >> lixo; // ler 3a ','
            in >> j;
            media_x += x;
            media_y += y;
            media_z += z;
            media_j += j;
            if (x < min_x) {min_x = x;}
            if (y < min_y) {min_y = y;}
            if (z < min_z) {min_z = z;}
            if (j < min_j) {min_j = j;}
            if (x > max_x) {max_x = x;}
            if (y > max_y) {max_y = y;}
            if (z > max_z) {max_z = z;}
            if (j > max_j) {max_j = j;}
            *seriesA << QPointF((linha_corrente-k)*2 + t_inicial_inteiro, x);
            *seriesB << QPointF((linha_corrente-k)*2 + t_inicial_inteiro, y);
            *seriesC << QPointF((linha_corrente-k)*2 + t_inicial_inteiro, z);
            *seriesD << QPointF((linha_corrente-k)*2 + t_inicial_inteiro, j);
            linha_corrente += 1;
            n_iteracoes += 1;
        }
        media_x = media_x/n_iteracoes;
        qDebug() << media_x;
        media_y = media_y/n_iteracoes;
        qDebug() << media_y;
        media_z = media_z/n_iteracoes;
        qDebug() << media_z;
        media_j = media_j/n_iteracoes;
        qDebug() << media_j;

        //Setando as médias
        QString text_media = QString("Average: %1 ").arg(QString::number(media_x));
        QString text_mediay = QString("Average: %1").arg(QString::number(media_y));
        QString text_mediaz = QString("Average: %1").arg(QString::number(media_z));
        QString text_mediaj = QString("Average: %1").arg(QString::number(media_j));

        ui->label_6->setText(text_media);
        ui->label_17->setText(text_mediay);
        ui->label_11->setText(text_mediaz);
        ui->label_14->setText(text_mediaj);
        //Setando os máx
        QString text_max = QString("Max: %1").arg(QString::number(max_x));
        QString text_maxy = QString("Max: %1").arg(QString::number(max_y));
        QString text_maxz = QString("Max: %1").arg(QString::number(max_z));
        QString text_maxj = QString("Max: %1").arg(QString::number(max_j));

        ui->label_7->setText(text_max);
        ui->label_9->setText(text_maxy);
        ui->label_12->setText(text_maxz);
        ui->label_15->setText(text_maxj);

        //Setando os min
        QString text_minx = QString("Min: %1").arg(QString::number(min_x));
        QString text_miny = QString("Min: %1").arg(QString::number(min_y));
        QString text_minz = QString("Min: %1").arg(QString::number(min_z));
        QString text_minj = QString("Min: %1").arg(QString::number(min_j));

        ui->label_4->setText(text_minx);
        ui->label_10->setText(text_miny);
        ui->label_13->setText(text_minz);
        ui->label_16->setText(text_minj);

inputFile.close();
chart = new QChart(); //Criando um gráfico CHART
chart1 = new QChart();
chart2 = new QChart();
chart3 = new QChart();
chart->addSeries(seriesA); //Adiconando cada série no gráfico
chart->legend()->setVisible(true);
chart->setTitle("Battery Current");
chart->createDefaultAxes();

chart1->addSeries(seriesB);
chart1->legend()->setVisible(true);
chart1->setTitle("Room Temperature");
chart1->createDefaultAxes();

chart2->addSeries(seriesC);
chart2->legend()->setVisible(true);
chart2->setTitle("Battery Voltage");
chart2->createDefaultAxes();

chart3->addSeries(seriesD);
chart3->legend()->setVisible(true);
chart3->setTitle("Battery Temperature");
chart3->createDefaultAxes();

ui->graphicsView->setChart(chart);
ui->graphicsView_2->setChart(chart1);
ui->graphicsView_3->setChart(chart2);
ui->graphicsView_4->setChart(chart3);
}
