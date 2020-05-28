#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "bankcount.h"
#include "cordinarycount.h"
#include "Csocialcount.h"
#include "Cvipcount.h"
CordinaryCount oCount;
CsocialCount sCount;
CvipCount vCount;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->countInfo->hide();

    connect(this,&MainWindow::signalFromRadioBut,this,&MainWindow::slotMsg);
    ui->radioButton->mapToGlobal(QPoint(50,100));
    ui->radioButton_2->mapToGlobal(QPoint(50,100));
    ui->radioButton_3->mapToGlobal(QPoint(50,100));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotRadioBut(){
    emit signalFromRadioBut(1);
}

void MainWindow::slotRadioBut2()
{
    emit signalFromRadioBut(2);
}

void MainWindow::slotRadioBut3()
{
    emit signalFromRadioBut(3);
}
void MainWindow::slotMsg(int butID)
{
    QMessageBox *msg = new QMessageBox;
    msg->setWindowTitle("Info");
    if(butID==1){
        msg->setText("Вам доступні такі можливості\n"
                     "1. оплата комунальних послуг.(комісія 0.5% від суми переказу)\n"
                     "2. Перерахунок на інший рахунок.(комісія 1% від суми переказу)\n"
                     "3. Зняття готівки(комісія 1% від суми зняття)");
    }else if(butID==2){
        msg->setText("Вам доступні такі можливості\n"
                     "1. оплата комунальних послуг.(без комісії)\n"
                     "2. Перерахунок на інший рахунок.(комісія 1% від суми переказу)\n"
                     "3. Зняття готівки. (без комісії)\n"
                     "4. Щомісячно нараховується 7% річних від суми на картці");
    }else if(butID==3){
        msg->setText("Вам доступні такі можливості\n"
                     "1. оплата комунальних послуг.(без комісії)\n"
                     "2. Перерахунок на інший рахунок.(без комісії)\n"
                     "3. Зняття готівки. (без комісії)\n"
                     "4. Щомісячно нараховується 10% річних від суми на картці(якщо більше 500грн)\n"
                     "5. Кредитний ліміт(10 000 грн). 1% в місяць від використаної суми");
    }
    butID = 0;
    msg->open();
}

//void MainWindow::createSpecType(bankCount *pAccount)
//{
//    pAccount->setName(ui->lNameIn->text(),ui->fNameIn->text());
//    pAccount->setAge(ui->ageIn->text().toInt());
//    showCabinet(pAccount);
//}

void MainWindow::on_radioButton_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu();
    QAction *ac = new QAction("What is this");


    connect(ac, SIGNAL(triggered()),this,SLOT(slotRadioBut()));

    menu->mapToGlobal(QPoint(50,100));
    menu->addAction(ac);
    menu->exec(mapToGlobal(pos));
}

void MainWindow::on_radioButton_2_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu();
    QAction *ac = new QAction("What is this");

    connect(ac, SIGNAL(triggered()),this,SLOT(slotRadioBut2()));

    menu->mapToGlobal(QPoint(50,100));
    menu->addAction(ac);
    menu->exec(mapToGlobal(pos));
}

void MainWindow::on_radioButton_3_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu();
    QAction *ac = new QAction("What is this");

    connect(ac, SIGNAL(triggered()),this,SLOT(slotRadioBut3()));

    menu->mapToGlobal(QPoint(50,100));
    menu->addAction(ac);
    menu->exec(mapToGlobal(pos));
}

void MainWindow::on_createCount_clicked(){
    bool cType[3];//arr to check which count has been choosen
    cType[0] = ui->radioButton->isChecked();
    cType[1] = ui->radioButton_2->isChecked();
    cType[2] = ui->radioButton_3->isChecked();
    if(cType[0]){
        //CordinaryCount oCount;
        oCount.setName(ui->fNameIn->text(),ui->lNameIn->text());
        oCount.setAge(ui->ageIn->text().toInt());
        oCount.setChoosed();
        sCount.setUnChoosed();
        vCount.setUnChoosed();
        showCabinet(&oCount);
    }else if(cType[1]){
        sCount.setName(ui->fNameIn->text(),ui->lNameIn->text());
        sCount.setAge(ui->ageIn->text().toInt());
        sCount.setChoosed();
        oCount.setUnChoosed();
        vCount.setUnChoosed();

        showCabinet(&sCount);
    }else if(cType[2]){
        vCount.setName(ui->fNameIn->text(),ui->lNameIn->text());
        vCount.setAge(ui->ageIn->text().toInt());
        vCount.setChoosed();
        oCount.setUnChoosed();
        sCount.setUnChoosed();


        showCabinet(&vCount);
    }else{
        QMessageBox::warning(this,"Fail","You sould choose type of account");
        return;
    }
    ui->createForm_2->hide();
    ui->countInfo->show();
}

void MainWindow::showCabinet(bankCount *owner){
    ui->ownerName->setText(owner->getFname()+" "+owner->getLname());
    ui->transSpinBox->setRange(0,owner->getSum());
    ui->countMoney->setText(QString::number(owner->getSum())+" uan");
    ui->getCashIn->clear();
    ui->replenishIn->clear();
    ui->payIn->clear();
    ui->countID->setText("count №: " + owner->getCountID());
    if(owner->getCountID().front() == '1'||owner->getCountID().front() == '2'){
         ui->CredMoney->setText("Credit Money: UNAVALIBLE");
    }else{
        ui->CredMoney->setText("Credit Money: "+QString::number(vCount.getCrSum()));
    }
    ui->transCount->clear();
    ui->transSpinBox->clear();
}

void MainWindow::on_replenishBut_clicked()
{
    double sum = ui->replenishIn->text().toDouble();
    if(oCount.isChoosed()){
        oCount.replenishCount(sum);
        showCabinet(&oCount);
    }else if(sCount.isChoosed()){
        sCount.replenishCount(sum);
        showCabinet(&sCount);
    }else if(vCount.isChoosed()){
        vCount.replenishCount(sum);
        showCabinet(&vCount);
    }

}

void MainWindow::on_action_triggered(){
    ui->countInfo->hide();
    ui->createForm_2->show();
}

void MainWindow::on_getCashBtn_clicked(){
    double sum = ui->getCashIn->text().toDouble();
    if(oCount.isChoosed()){
        if(oCount.getSum()<sum){
            QMessageBox::warning(this,"Warning","Lack of Money!");
        }else{
            oCount.grabCash(sum);
        }
        showCabinet(&oCount);
    }else if(sCount.isChoosed()){
        if(sCount.getSum()<sum){
            QMessageBox::warning(this,"Warning","Lack of Money!");
        }else{
            sCount.grabCash(sum);
        }
    showCabinet(&sCount);
    }else if(vCount.isChoosed()){
        if(vCount.getSum()<sum){
            QMessageBox::warning(this,"Warning","Lack of Money!");
        }else{
            vCount.grabCash(sum);
        }
        showCabinet(&vCount);
    }
}

void MainWindow::on_payByOwnBtn_clicked()
{
    double sum  = ui->payIn->text().toDouble();
    if(oCount.isChoosed()){
        if(oCount.getSum()<sum){
            QMessageBox::warning(this,"Warning","Lack of Money!");
        }else{
            oCount.payBills(sum);
        }
        showCabinet(&oCount);
    }else if(sCount.isChoosed()){
        if(sCount.getSum()<sum){
            QMessageBox::warning(this,"Warning","Lack of Money!");
        }else{
            sCount.payBills(sum);
        }
        showCabinet(&sCount);
    }else if(vCount.isChoosed()){
        if(vCount.getSum()<sum){
            QMessageBox::warning(this,"Warning","Lack of Money!");
        }else{
            vCount.payBills(sum);
        }
        showCabinet(&vCount);
    }
}

void MainWindow::on_payByCredBtn_clicked(){
    double sum  = ui->payIn->text().toDouble();
    if(oCount.isChoosed()){
        QMessageBox::warning(this,"Warning","This feature is unavalible");
    }else if(sCount.isChoosed()){
        QMessageBox::warning(this,"Warning","This feature is unavalible");
    }else if(vCount.isChoosed()){
        if(vCount.getCrSum()<sum){
            QMessageBox::warning(this,"Warning","Lack of credit Money!");
        }else{
            vCount.payBillByCred(sum);
            showCabinet(&vCount);
        }
    }
}


void MainWindow::on_transByOwnBtn_clicked(){
    QChar secCount = ui->transCount->text().front();

    double sum = ui->transSpinBox->value();
    bool success = false;
    if(oCount.isChoosed()){
        if (secCount == '2'){
            success = oCount.transferMoney(sCount,sum);
        }else if(secCount == '3' ){
            success = oCount.transferMoney(vCount,sum);
        }else if(secCount == '1' ){
            success = oCount.transferMoney(oCount,sum);
        }
        showCabinet(&oCount);
    }else if(sCount.isChoosed()){
        if (secCount == '2' ){
            success = sCount.transferMoney(sCount,sum);
        }else if(secCount == '3' ){
            success = sCount.transferMoney(vCount,sum);
        }else if(secCount == '1' ){
            success = sCount.transferMoney(oCount,sum);
        }
        showCabinet(&sCount);
    }else if(vCount.isChoosed()){
        if (secCount == '2'){
            success = vCount.transferMoney(sCount,sum);
        }else if(secCount == '3'){
            success = vCount.transferMoney(vCount,sum);
        }else if(secCount == '1'){
            success = vCount.transferMoney(oCount,sum);
        }
        showCabinet(&vCount);
    }

    if(success == true)
        QMessageBox::information(this,"Success","Successful transfering");
    else
        QMessageBox::warning(this,"Fail","Failed transfering");
}


void MainWindow::on_actionVIP_count_triggered(){
    vCount.setChoosed();
    sCount.setUnChoosed();
    oCount.setUnChoosed();
    showCabinet(&vCount);
}

void MainWindow::on_actionSocial_count_triggered(){
    sCount.setChoosed();
    vCount.setUnChoosed();
    oCount.setUnChoosed();
    showCabinet(&sCount);
}

void MainWindow::on_actionOrdinary_count_triggered(){
    oCount.setChoosed();
    sCount.setUnChoosed();
    vCount.setUnChoosed();
    showCabinet(&oCount);
}

void MainWindow::on_actionShow_counts_triggered()
{
    QString str = bankCount::print()+ "\n" + CordinaryCount::print()+ "\n" +
                  CsocialCount::print()+ "\n" + CvipCount::print();
    QMessageBox::information(this, "Name Classes", str);
}
