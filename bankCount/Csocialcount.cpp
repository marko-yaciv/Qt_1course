#include "Csocialcount.h"
CsocialCount::CsocialCount(){
    srand(time(NULL));
    int idNum = rand() % (INT32_MAX)+ (INT32_MAX/2);
    countId = "2"  + QString::number(idNum);
}

void CsocialCount::payBills(double sum){
    this->sum -= sum;

//-----------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Bills Payment.Sum: " + QString::number(this->getSum());
    writeHistory(operationInfo,out);
    file.close();
}

void CsocialCount::grabCash(double sum){
    this->sum -= sum;
//----------------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Taking Cash.Sum: " + QString::number(this->getSum());
    writeHistory(operationInfo,out);
    file.close();
}
void CsocialCount::addPercentToSum(){
    double prc = this->sum* 0.025;
    this->sum += prc;
}

QString CsocialCount::print(){
   QString str;
   str = "CsocialCount";
   return str;
}
