#include "bankcount.h"


bankCount::bankCount()
{
}

void bankCount::replenishCount(double sum){
    this->sum += sum;
//-----------------------------  
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo = this->getFname()+" "+this->getLname()+
            " Replenishment.Sum: " + QString::number(this->getSum());
    writeHistory(operationInfo,out);
    file.close();
}

void bankCount::setName(QString Fname, QString Lname){
    this->ownerFname = Fname;
    this->ownerLname = Lname;
}

void bankCount::setAge(int age){
    this->ownerAge = age;
}

QString bankCount::getFname(){
    return this->ownerFname;
}

QString bankCount::getLname(){
    return this->ownerLname;
}

int bankCount::getAge(){
    return this->ownerAge;
}

QString bankCount::getCountID(){
    return this->countId;
}

double bankCount::getSum(){
    return this->sum;
}

void bankCount::setChoosed(){
    chosed = 1;
}

void bankCount::setUnChoosed(){
    chosed = 0;
}

bool bankCount::isChoosed(){
    return chosed;
}

void bankCount::writeHistory(QString msg, std::ostream&stream){
    stream<<msg.toStdString()<<"\n";
}

bool bankCount::transferMoney(bankCount& receiveCount, double sum){
    receiveCount.sum += sum;
    this->sum -= sum;
//--------------------------------------------------
    std::filebuf file;
    file.open("acountsTransfer.txt", std::ios::app);
    std::ostream out(&file);
    QString operationInfo ="Sender "+this->getFname()+" "+this->getLname()+
            " Transfering.Sum: " + QString::number(sum)+
            ". Receiver "+receiveCount.getFname()+" "+receiveCount.getLname();
    writeHistory(operationInfo,out);
    file.close();
    return true;

}

QString bankCount::print(){
   QString str;
   str = "abstract bankCount";
   return str;
}
