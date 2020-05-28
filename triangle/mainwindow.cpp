#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "triangle.h"
Triangle NewTriangle;
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

void MainWindow::on_calcArea_clicked()
{
    ui->sOut->setText("S = "+QString::number(NewTriangle.getS()));
}
void MainWindow::on_calcP_clicked()
{
    ui->pOut->setText("P = "+QString::number(NewTriangle.getP()));
}

void MainWindow::on_calcH_clicked()
{
    ui->ha->setText("Ha = "+QString::number(NewTriangle.getHa()));
    ui->hb->setText("Hb = "+QString::number(NewTriangle.getHb()));
    ui->hc->setText("Hc = "+QString::number(NewTriangle.getHc()));
}

void MainWindow::on_calcCorners_clicked()
{
     ui->corA->setText("A = "+QString::number(NewTriangle.getCorA()));
     ui->corB->setText("B = "+QString::number(NewTriangle.getCorB()));
     ui->corC->setText("C = "+QString::number(NewTriangle.getCorC()));
}


void MainWindow::on_enterSites_clicked()
{
   //extern Triangle NewTriangle;
   NewTriangle = NewTriangle<<ui;//reading from ui
    NewTriangle = NewTriangle();//casting double to float
    if(NewTriangle.isExist()){
        if(NewTriangle.isRectang())
            ui->triangle->setText("Triangle is Recktangle");
        else
            ui->triangle->setText("Triangle isn't Recktangle");
        NewTriangle.setP();
        NewTriangle.setS();
        NewTriangle.setH();
        NewTriangle.setCorners();
        ui>>NewTriangle;
    }else{
        ui->triangle->setText("Triangle doesn't exist!");
        ui->aOut->setNum(0);
        ui->bOut->setNum(0);
        ui->cOut->setNum(0);
    }
}



void MainWindow::on_scaleButIn_clicked()
{
    NewTriangle.setScale(ui);
    double scaleK = NewTriangle.getScale();
    NewTriangle*=scaleK;
    ui>>NewTriangle;
    NewTriangle.setP();
    NewTriangle.setS();
    NewTriangle.setH();
    NewTriangle.setCorners();
}

void MainWindow::on_scaleButOn_clicked()
{
    NewTriangle.setScale(ui);
    double scaleK = NewTriangle.getScale();
    NewTriangle+=scaleK;
    ui>>NewTriangle;
    NewTriangle.setP();
    NewTriangle.setS();
    NewTriangle.setH();
    NewTriangle.setCorners();
}


