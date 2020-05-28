#ifndef BANKCOUNT_H
#define BANKCOUNT_H
#include <QString>
#include <time.h>
#include <QDataStream>
#include <QFile>
#include <fstream>
#include <QMessageBox>
class bankCount{
public:
    bankCount();
    void replenishCount(double sum);
    virtual void payBills(double sum) = 0;
    virtual void grabCash(double sum) = 0;

    bool transferMoney(bankCount&, double sum);

    void setName(QString Fname,QString Lname);
    void setAge(int age);

    QString getFname();
    QString getLname();
    int getAge();
    QString getCountID();
    double getSum();

    static QString print();


    void setChoosed();
    void setUnChoosed();
    bool isChoosed();
private:
    bool chosed;
protected:
    QString ownerFname;
    QString ownerLname;
    int ownerAge;
    QString countId;
    double sum;
    void writeHistory(QString,std::ostream&);
};



#endif // BANKCOUNT_H
