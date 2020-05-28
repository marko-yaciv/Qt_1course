#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "array.h"

#include <QTextStream>
#include <QMessageBox>
#include <QException>
#include <QFileDialog>
Array arr;
QFile fr, fw;
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

void MainWindow::openRfile(QFile& f) throw(QString)
{
    if(!f.exists()){
        QString msg = "The file doesn't exists";
        throw (msg);
    }
    if(!f.open(QIODevice::ReadOnly)){
        QString msg = "Canot open the file";
        throw (msg);
    }
}


void MainWindow::on_read_clicked()
{

    QString path = ui->path->text();
    fr.setFileName(path);

    try {
        openRfile(fr);
    } catch (QString ex) {

        QMessageBox::warning(this,"Can't open", ex);
        return;
    }

    QTextStream in(&fr);
    try {
        arr.readFile(in);
    } catch (const QString er) {
        QMessageBox::warning(this, "Error", er);
    }

    ui->array->clear();
    for(int i = 0; i < arr.getSize();++i){
        ui->array->setText(ui->array->text() + QString::number(arr.at(i))+" ");
    }
    fr.close();
}

void MainWindow::on_write_clicked(){
    QString path = ui->path->text();
    fw.setFileName(path);

    //QString fname  = fr.fileName();
    if(fr.fileName() == fw.fileName()){
        QMessageBox::warning(this,"Write error", "You cannot write the array "
                                                "to file which you have read from");
        return;
    }


    try {
        if(!fw.open(QIODevice::WriteOnly))throw std::exception();
        QTextStream out(&fw);
        arr.writeFile(out);
        QMessageBox::information(this,"Success", "The array has been writen to the file");
    } catch (std::exception &ex) {
        QMessageBox::warning(this,"Can't open", ex.what());
        return;
    }


    fw.close();
}

void MainWindow::on_maxB_clicked(){

    ui->maxB->setText("Max: " + QString::number(arr.getmax()));

}

void MainWindow::on_MinB_clicked()
{
    ui->MinB->setText("Min: " + QString::number(arr.getmin()));
}

void MainWindow::on_SumB_clicked()
{
    ui->SumB->setText("Sum: " + QString::number(arr.getsum()));
}

void MainWindow::on_AvgB_clicked()
{
    ui->AvgB->setText("Avg: " + QString::number(arr.getavg()));
}
