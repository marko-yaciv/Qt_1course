#include "Cvipcount.h"
CvipCount::CvipCount(){
    srand(time(NULL));
    int idNum = rand() % (INT32_MAX)+ (INT32_MAX/2);
    countId = "3"  + QString::number(idNum);
    crLimit = 10000;
}

double CvipCount::getCrSum(){
    return crLimit;
}

void CvipCount::payBills(double sum){
    this->sum -= sum;
//----------------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Bills Payment.Sum: " + QString::number(sum);
    writeHistory(operationInfo,out);
    file.close();
}

void CvipCount::grabCash(double sum){
    this->sum -= sum;
//---------------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Taking cash.Sum: " + QString::number(sum);
    writeHistory(operationInfo,out);
    file.close();
}

void CvipCount::payBillByCred(double sum){
    double commission = sum*0.02;
    crLimit -= (sum+commission);
//--------------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Bills Payment(Credit money).Sum: " + QString::number(sum)+
            ". Commision: "+QString::number(commission);
    writeHistory(operationInfo,out);
    file.close();
}
void CvipCount::addPercentToSum(){
    double prc = this->sum* 0.05;
    this->sum += prc;
}
QString CvipCount::print(){
   QString str;
   str = "CvipCount";
   return str;
}
