#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

int MainWindow::CntOfArrays = 0;
int MainWindow::CntOfElements = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->compareWidget->hide();
    ui->compareBut->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//---------------------------------------

void MainWindow::on_sortUp_clicked(){
    ui->out->clear();
    vArr[CntOfArrays].sortUp();//сортуємо масив векторів у порядку зростання(за довжиною вектора)
    vArr[CntOfArrays].print(ui->out);


}

void MainWindow::on_sortDown_clicked(){
    ui->out->clear();
    vArr[CntOfArrays].sortDown(); //сортуємо масив векторів у порядку спадання(за довжиною вектора)
    vArr[CntOfArrays].print(ui->out);

}


void MainWindow::on_start_clicked()
{
    if(CntOfArrays >= 10){
        QMessageBox::warning(this, "Maximum size", "You have created Maximum count of arrays");
        return;
    }
    CntOfElements++;
    MyVector vect(ui->startX->value(), ui->startY->value(),
                  ui-> endX-> value(), ui-> endY-> value());

    vArr[CntOfArrays].setSize(CntOfElements);// перевиділяємо розмір масиву векторів

    vArr[CntOfArrays].at(CntOfElements-1) = vect;//додаємо новий вектор

    vArr[CntOfArrays].print(ui->out);//виводимо вектор на label

    MyVector b = vArr[CntOfArrays].bigest();// пошук найбільшого вектора (За довжиною)
    ui->bigestVal->setText("( ("+QString::number(b.getSX()) + "; " +
                           QString::number(b.getSY()) + "), (" +
                           QString::number(b.getEX()) + "; " +
                           QString::number(b.getEY()) + "))");
    ui->sumVal->setText(QString::number(vArr[CntOfArrays].findSum()));// вивід суми довжин усіх векторів у масиві

}
void MainWindow::on_enterAr_clicked()
{
    ui->comboBox->addItem(ui->out->text());
    ui->comboBox_2->addItem(ui->out->text());

    ui->out->clear();
    ui->sumVal->clear();
    ui->bigestVal->clear();
    CntOfArrays++;
    if(CntOfArrays >= 2){
        ui->compareBut->show();
        ui->compareWidget->show();
        ui->cmpRes->setText("and");
    }
    CntOfElements = 0;
}

void MainWindow::on_compareBut_clicked()
{
    //порівняння масивів векторів.  Боільший той, у якому більше векторів.

    int index1 = ui->comboBox->currentIndex();
    int index2 = ui->comboBox_2->currentIndex();
    if(vArr[index1].getSize() > vArr[index2].getSize())
        ui->cmpRes->setText(">");

    else if(vArr[index1].getSize() < vArr[index2].getSize())
        ui->cmpRes->setText("<");
    else
         ui->cmpRes->setText("=");
}

