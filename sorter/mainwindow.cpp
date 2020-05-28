#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include "comparator.h"
#include "intarr.h"
#include "doublearr.h"
#include <QMessageBox>

QList <Comparator*> list;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    for (auto i : list) {
        delete i;
    }
}
void MainWindow::on_intRadBut_clicked()
{
    IntArr *tmp = new IntArr;
    list.append(tmp);
    ui->lineEdit->clear();
}

void MainWindow::on_dblRadBut_clicked()
{
    DoubleArr *tmp = new DoubleArr;
    list.append(tmp);
    ui->lineEdit->clear();
}

void MainWindow::on_sortBut_clicked()
{
    ui->label_2->clear();
    ui->sorted->clear();
    QStringList nums = ui->lineEdit->text().split(' ',QString::SkipEmptyParts);

    int sz = nums.size();
    bool check;

    IntArr *iArr;
    DoubleArr* dArr;

    if(ui->intRadBut->isChecked())
    {
        check = true;
        iArr = dynamic_cast<IntArr*>(list.last());

        iArr->IntArr::setSize(sz);//visible access to members of class
    }
    else if (ui->dblRadBut->isChecked())
    {
        check = false;
        dArr = dynamic_cast<DoubleArr*>(list.last());
        dArr->DoubleArr::setSize(sz);//visible access to members of class
    }
    else
    {
        QMessageBox::warning(this, "Try again", "You should choose the type of elements in array");
        return;
    }
    ui->lineEdit->clear();
        if(check){
            for (int i = 0; i < sz;++i) {
                 iArr->fillArr(i,nums.at(i).toInt());
                 ui->label_2->setText(ui->label_2->text() + QString::number((*iArr)[i]) + ", ");
            }

            iArr->sort();

            for (int i = 0; i < sz;++i) {
                ui->sorted->setText(ui->sorted->text() + QString::number((*iArr)[i]) + ", ");
            }
        }else{
            for (int i = 0; i < sz;++i) {

                dynamic_cast<DoubleArr*>(list.last())->fillArr(i,nums.at(i).toDouble());//access to functions from the list

                ui->label_2->setText(ui->label_2->text() + QString::number((*dArr)[i]) + ", ");
            }

            dynamic_cast<DoubleArr*>(list.last())->sort();//virtual inherit

            for (int i = 0; i < sz;++i) {
                ui->sorted->setText(ui->sorted->text() + QString::number((*dArr)[i]) + ", ");
            }
        }

}
