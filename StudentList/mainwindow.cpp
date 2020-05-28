#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <algorithm>
#include <QTableWidget>
#include <QMessageBox>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QStyle>
QFile file("D:\\Programing\\QtProjects\\StudentList\\list.txt");


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->list->setColumnCount(5);
    QStringList listHeaders = {"First name", "Last name", "Bitdth date", "Marks", "Avg"};
    ui->list->setHorizontalHeaderLabels(listHeaders);
    ui->list->setTabletTracking(1);

    ui->list->setAutoScroll(1);
    ui->list->setColumnWidth(0, 200);
    ui->list->setColumnWidth(1, 200);
    ui->list->setColumnWidth(2, 200);
    ui->list->setColumnWidth(3, 200);
    ui->list->setColumnWidth(4, 50);


    ui->resetB->hide();
    ui->yearToShow->setMaxLength(4);
    ui->monthToShow->setMaxLength(2);

    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    sList = Student::readFromFile(in);
    file.close();
    sortList(sList);
    findMinMaxAvgInList(sList);

    ui->fromMark->setRange(Student::getMinAvg(), Student::getMaxAvg());
    ui->fromMark->setSingleStep(0.1);
    ui->fromMark->setValue(Student::getMinAvg());
    ui->toMark->setRange(Student::getMinAvg(), Student::getMaxAvg());
    ui->toMark->setValue(Student::getMaxAvg());
    ui->toMark->setSingleStep(0.1);

    for (int i = 0;i < sList.size(); ++i) {
        addMemberToTable(sList.at(i), i+1);
    }
}

MainWindow::~MainWindow()
{
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    Student::writeToFile(sList,out);
    file.close();
    delete ui;
}

void MainWindow::addMemberToTable(Student m, int row)
{
    ui->list->setRowCount(row);
    QTableWidgetItem *fname = new QTableWidgetItem(m.getFname());
    fname->setTextAlignment(4);
    QTableWidgetItem *lname = new QTableWidgetItem(m.getLname());
    lname->setTextAlignment(4);
    QTableWidgetItem *date = new QTableWidgetItem(m.getDate().toString());
    date->setTextAlignment(4);
    QString smarks;
    int cnt = Student::getCntOfMarks();
    for (int i = 0;i<cnt;++i) {
        smarks.append(QString::number(m.getMarks()[i]) + " ");
    }
    QTableWidgetItem *marks = new QTableWidgetItem(smarks);
    marks->setTextAlignment(4);
    QTableWidgetItem *avg = new QTableWidgetItem(QString::number(m.getAvg()));
    avg->setTextAlignment(4);

    ui->list->setItem(row-1,0,fname);
    ui->list->setItem(row-1,1,lname);
    ui->list->setItem(row-1,2,date);
    ui->list->setItem(row-1,3,marks);
    ui->list->setItem(row-1,4,avg);
}
void MainWindow::getListFromTable(QList<Student> * list){
    int col = ui->list->columnCount();
    QTableWidgetItem *tableMember[col];

    int* m = new int[Student::getCntOfMarks()];
    for (int i = 0; i < ui->list->rowCount(); ++i) {
        for (int j = 0; j < col; ++j) {
            tableMember[j] = ui->list->item(i,j);
        }
        Student listMember;
        listMember.setFname(tableMember[0]->text());
        listMember.setLname(tableMember[1]->text());
        listMember.setDate(QDate::fromString(tableMember[2]->text()));
        QStringList sm = tableMember[3]->text().split(' ');

        for (int i = 0; i < Student::getCntOfMarks();++i) {
            m[i] = sm.at(i).toInt();
        }
        listMember.setMarks(m);


        (*list).append(listMember);
    }
    delete [] m;
}
void MainWindow::findMinMaxAvgInList(QList<Student> & sList){
    int lSize = sList.size();
    Student::setMinAvg(sList.first().getAvg());
    Student::setMaxAvg(sList.first().getAvg());
    for (int i = 1;i < lSize; ++i) {
        if(sList.at(i).getAvg() < Student::getMinAvg()){
            Student::setMinAvg(sList.at(i).getAvg());
        }
        if(sList.at(i).getAvg() > Student::getMaxAvg()){
            Student::setMaxAvg(sList.at(i).getAvg());
        }
    }

}
void MainWindow::sortList(QList<Student> & list){

    std::sort(list.begin(),list.end());

}
void MainWindow::on_filterDateB_clicked(){
    int lSize = sList.size();
    QList<Student> sortedByDate;

    int y = ui->yearToShow->text().toInt();
    int m = ui->monthToShow->text().toInt();

    if(y==0){
        if(m < 1||m > 12){
           QMessageBox::warning(this, "Invalid input", "The month sould be in range 1 - 12");
           return;
        }else{
            //filtruem list by MONTH
            bool isFound = false;
            for (int i = 0;i < lSize;++i) {
                if(sList.at(i).getDate().month() == m)
                {
                    isFound = true;
                   sortedByDate.append(sList.at(i));
                }
                if(!isFound){
                    QMessageBox::warning(this, "Not found", "There are no students born in this month");
                    return;
                }
            }
        }
    }else if(m==0){
        if(y > 2020 || y < 1900){
            QMessageBox::warning(this, "Invalid input", "The year sould be in range 1900 - 2020");
            return;
        }else{
            //filtruem list by YEAR
            bool isFound = false;
            for (int i = 0;i < lSize;++i) {
                if(sList.at(i).getDate().year() == y)
                {
                    isFound = true;
                   sortedByDate.append(sList.at(i));
                }
            }
            if(!isFound){
                QMessageBox::warning(this, "Not found", "There are no students born in this year");
                return;
            }
        }
    }else if(y==0 && m==0){
        QMessageBox::warning(this, "Invalid input", "Enter the year or month to filter list");
        return;
    }else{
        if(y > 2020 || y < 1900){
            QMessageBox::warning(this, "Invalid input", "The year sould be in range 1900 - 2020");
            return;
        }else if(m <= 0||m > 12){
            QMessageBox::warning(this, "Invalid input", "The month sould be in range 1 - 12");
            return;
        }else{
            //filtruem list by YEAR and MONTH
            bool isFound = false;
            for (int i = 0;i < lSize;++i) {
                if(sList.at(i).getDate().year() == y &&
                   sList.at(i).getDate().month() == m)
                {
                   isFound = true;
                   sortedByDate.append(sList.at(i));
                }
            }
            if(!isFound){
                QMessageBox::warning(this, "Not found", "There are no students born in that date");
                return;
            }
        }
    }

    ui->yearToShow->clear();
    ui->monthToShow->clear();
    ui->resetB->show();
    int fLSize = sortedByDate.size();
    for (int i = 0; i < fLSize; ++i) {
        addMemberToTable(sortedByDate.at(i), i+1);
    }
}
void MainWindow::on_filterMarksB_clicked(){
    QList <Student> sortedByAvg;
    double lEnd = ui->fromMark->value();
    double rEnd = ui->toMark->value();

    int lSize = sList.size();
    for (int i = 0;i < lSize; ++i) {
        if(sList.at(i).getAvg() >= lEnd &&
           sList.at(i).getAvg() <= rEnd)
        {
            sortedByAvg.append(sList.at(i));
        }
    }
    int slSize = sortedByAvg.size();
    for (int i = 0;i < slSize; ++i) {
        addMemberToTable(sortedByAvg.at(i), i+1);
    }
    ui->resetB->show();
}
void MainWindow::on_resetB_clicked()
{
    int lSize = sList.size();
    for (int i = 0; i < lSize; ++i) {
        addMemberToTable(sList.at(i), i+1);
    }
    ui->resetB->hide();
}
void MainWindow::on_delMember_clicked()
{
    QString fname = ui->fNameToDel->text();
    QString lname = ui->lNameTodel->text();
    int lSize = sList.size();
    bool isMembFound = false;
    std::vector<int>indexToDel;

    for (int i = 0; i < lSize;++i) {
        if(sList.at(i).getFname() == fname &&
           sList.at(i).getLname() == lname)
        {
                indexToDel.push_back(i);
                isMembFound = true;
        }
    }
    if(isMembFound){
        for (unsigned int(i) = 0; i < indexToDel.size();++i) {
            sList.removeAt(indexToDel.at(i));
        }

        lSize = sList.size();

        for (int i = 0; i<lSize;++i) {
            addMemberToTable(sList.at(i),i+1);
        }

    }else{
        QMessageBox::warning(this, "Not found", "The member you entered not found");
        return;
    }
    ui->fNameToDel->clear();
    ui->lNameTodel->clear();
}




void MainWindow::on_actionAdd_New_Member_triggered()
{
    add = new Dialog(this);
    add->setWindowTitle("Add Member");
    add->show();
    int s = sList.size();
    std::cout << s << "\n";
    connect(add, &Dialog::signalAdded, this, &MainWindow::memberAded );

}

void MainWindow::memberAded(int isAded)
{
    sList.append(add->newMember);
    int s = sList.size();
    std::cout<<s<<"\n";
    if(isAded == 1){
        sortList(sList);

        findMinMaxAvgInList(sList);

        for (int i = 0; i < sList.size();++i) {
           addMemberToTable(sList.at(i), i+1);
        }
        ui->resetB->hide();
    }

}
