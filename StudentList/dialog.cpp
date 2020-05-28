#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->mathMark->setRange(0,99);
    ui->scienceMark->setRange(0,99);
    ui->historyMark->setRange(0,99);
    ui->oterTongueMark->setRange(0,99);
    ui->programingMark->setRange(0,99);


}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::on_addMember_clicked(){

    newMember.setFname(ui->fName->text());
    newMember.setLname(ui->lName->text());
    newMember.setDate(ui->dateEdit->date());

    QSpinBox* marks[5];
    marks[0] = ui->scienceMark;
    marks[1] = ui->historyMark;
    marks[2] = ui->mathMark;
    marks[3] = ui->programingMark;
    marks[4] = ui->oterTongueMark;

    int * iMarks = new int[5];
    for (int i = 0; i < 5; ++i){
            iMarks[i] = marks[i]->value();
    }
    newMember.setMarks(iMarks);
//    int s = sList.size();
//    sList.push_back(newMember);
//    s = sList.size();
    slotAdded();

    ui->fName->clear();
    ui->lName->clear();
    this->hide();
}

void Dialog::slotAdded()
{
    emit signalAdded(1);
}
