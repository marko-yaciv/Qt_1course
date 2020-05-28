#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QAbstractItemView>
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(fillGrid()));
    connect(ui->StartButton, SIGNAL(pressed()), this, SLOT(tryAgain()));
    connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(cellClicked(int, int)));
    tryAgain();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tryAgain() {
    failed = false;
    atempts = 3;
    level = 1;
    ticks = 0;
    ui->attempts->setText("Attempts: " + QString::number(atempts));
}

void MainWindow::cellClicked(int i, int j) {
    if(atempts <= 0 || failed) {
        return;
    }
    ui->tableWidget->clearSelection();
    if(i == winI && j == winJ) {
        level++;
        ticks = 0;
    } else {
        atempts--;
        ui->attempts->setText("Attempts: " + QString::number(atempts));
        if(atempts <= 0) {
            lose();
        } else {
            ticks = 0;
        }
    }
}

void MainWindow::lose() {
    ui->time->setText("You lost!");
    timer->stop();
    failed = true;
}

void MainWindow::fillGrid() {
    float maxTicks = (20 * 20) / (float)level;
    int progress = (int) (100 * (1 - (float)ticks / maxTicks));
    if(!failed) {
        ui->progressBar->setValue(progress);
    }

    if(ticks % (int)(20 / (float)level) == 0) {
        winI = qrand() % 5;
        winJ = qrand() % 5;
        MakeLevelShape(ui->tableWidget->rowCount(), ui->tableWidget->columnCount());
        QTableWidgetItem *num1 = new QTableWidgetItem("1");

        QFont *font = new QFont;
        font->setPixelSize(30);
        num1->setBackground(QColor(141,50, 64));
        num1->setTextAlignment(5);
        num1->setTextColor(Qt::white);
        num1->setFont(*font);
        ui->tableWidget->setItem(winI, winJ, num1);
    }
    if(ticks >= maxTicks && !failed) {
        lose();
    } else {
        ticks++;
    }

}

void MainWindow::on_actionEasy_triggered(){
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(3);
    MakeLevelShape(3,3);
}

void MainWindow::on_actionMedium_triggered(){
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(4);
    MakeLevelShape(4,4);
}

void MainWindow::on_actionHard_triggered(){
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);
    MakeLevelShape(5,5);
}
void MainWindow::MakeLevelShape(int rows, int cols){
    QFont *font = new QFont;
    font->setPixelSize(30);
    for(int i = 0; i < rows; i++) {
        ui->tableWidget->setColumnWidth(i, 160);
        ui->tableWidget->setRowHeight(i, 105);
        for(int j = 0; j < cols; j++) {
            QTableWidgetItem *item = new QTableWidgetItem("0");
            item->setTextAlignment(5);
            item->setBackground(QColor(106,117,136));
            item->setTextColor(Qt::white);
            item->setFont(*font);
            ui->tableWidget->setItem(i, j, item);
        }
    }
}
void MainWindow::on_StartButton_clicked()
{
     fillGrid();
     timer->start(50);
}

void MainWindow::on_actionHow_to_play_triggered()
{
    QString helpMessage = "You can change a difficulty level onr the menu <Game>"
                           "The red cell is running on all Table and you have to"
                            "catch it before the tiem will elapse"
                            "Also you have 3 attempts to click on wrong cell,"
                            "Then you will be failed";
    QMessageBox::information(this,"Help",helpMessage);
}
