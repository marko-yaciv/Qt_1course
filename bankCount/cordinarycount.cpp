#include "cordinarycount.h"
CordinaryCount::CordinaryCount(){
    srand(time(NULL));
    int idNum = rand() % (INT32_MAX)+ (INT32_MAX/2);
    countId = "1"  + QString::number(idNum);
}

void CordinaryCount::payBills(double sum){
    double perc = sum * 0.005;
    this->sum = this->sum - sum - perc;
//---------------------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Bills Payment.Sum: " + QString::number(this->getSum())+
            ". Commision: "+QString::number(perc);
    writeHistory(operationInfo,out);
    file.close();
}

void CordinaryCount::grabCash(double sum){
    double perc = sum * 0.01;
    this->sum = this->sum - sum - perc;

//--------------------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Taking cash.Sum: " + QString::number(this->getSum())+
            ". Commision: "+QString::number(perc);
    writeHistory(operationInfo, out);
    file.close();
}
QString CordinaryCount::print(){
   QString str;
   str = "CordinaryCount";
   return str;
}

