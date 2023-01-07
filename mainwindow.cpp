#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFileDialog"

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


void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/~", tr("*.obj"));
    ui->label->setText(fileName);
    QByteArray tmp = fileName.toLocal8Bit();
    const char *str = tmp.data();
    //parse(str);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText(QString::number(value) + "°");
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_2->setText(QString::number(value) + "°");
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    ui->label_3->setText(QString::number(value) + "°");
}

