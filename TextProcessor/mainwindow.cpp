#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QLabel>
#include <QLineEdit>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->findButton,SIGNAL(clicked()),ui->textEdit, SLOT(on_findButton_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name  = QFileDialog::getOpenFileName(this,"Open the file: ","",tr("Text File (*.txt);;All Files(*)"));
    QFile file(file_name);
    file_path = file_name;
    if(file_path.isEmpty()) return;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File hasn't been opened");
           return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
   QFile file(file_path);
   if(file_path.isEmpty()) {
       on_actionSave_as_triggered();
       return;
   }
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File hasn't been opened");
           return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name  = QFileDialog::getSaveFileName(this,"Open the file: ","",tr("Text File (*.txt);;All Files(*)"));
    QFile file(file_name);
    file_path = file_name;
    if(file_path.isEmpty()) return;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File hasn't been opened");
           return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}



void MainWindow::on_actionAbout_text_editor_triggered()
{
    QString about_editor = "Created: 16.02.2020";
    about_editor += "By Marko Yatsiv";
    about_editor += "This is the first editor and "
                    "I know that it is not perfect";

    QMessageBox::about(this,"About us",about_editor);
}

void MainWindow::on_actionFont_triggered()
{
    bool isSet;
    QFont font  = QFontDialog::getFont(&isSet,QFont("Calibri", 12),this);
    if(isSet){
        ui->textEdit->setFont(font);
    }else{
        QMessageBox::warning(this,"..","Font hasn't been changed!");
    }
}

void MainWindow::on_findButton_clicked()
{
        //ui->textEdit->find(ui->findLine->text(), QTextDocument::FindCaseSensitively);
        ui->textEdit->find(ui->findLine->text(), QTextDocument::FindBackward);
}

void MainWindow::on_pushButton_clicked()
{
    QString text  = ui->textEdit_2->toPlainText();

    if(ui->textEdit->find(ui->findLine->text(), QTextDocument::FindBackward)) {

    ui->textEdit->cut();
    ui->textEdit_2->selectAll();
    ui->textEdit_2->copy();
    ui->textEdit->paste();
}
}
