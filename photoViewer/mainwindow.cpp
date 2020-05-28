#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
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

QImage image;
void MainWindow::on_actionOpen_triggered()
{
    QString file_name  = QFileDialog::getOpenFileName(this,"Open the file: ");
    QFile file(file_name);


    bool valid = image.load(file_name);
    if(valid){
        image = image.scaledToWidth(ui->label->width(), Qt::SmoothTransformation);
        ui->label->setPixmap(QPixmap::fromImage(image));
    }
    else{
        QMessageBox::warning(this,"..","Picture can't be loaded");
    }
}


void MainWindow::on_label_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu();
    QAction* qa = new QAction("Open New");
    connect(qa, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered()));
    menu->addAction(qa);
    menu->exec(mapToGlobal(pos));
}
