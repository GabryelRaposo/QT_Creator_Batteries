#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QWidget>
#include <QLabel>


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

}


void MainWindow::on_pushButton_2_clicked()
{
QFile inputFile(ui->lineEdit_2->text());
if(!inputFile.open(QIODevice::ReadOnly))
qDebug() << "Arquivo não aberto";
else
qDebug() << "Arquivo OK";
QTextStream in(&inputFile);
QString line = in.readAll();
inputFile.close();
ui->textEdit->setPlainText(line);
}


