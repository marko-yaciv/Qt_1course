#ifndef CVIPCOUNT_H
#define CVIPCOUNT_H
#include "bankcount.h"

class CvipCount : public bankCount
{
public:
    CvipCount();
    double getCrSum();

    void payBills(double sum) override;
    void grabCash(double sum) override;
    void payBillByCred(double sum);
    static QString print();
private:
    double crLimit;
    void addPercentToSum();


};

#endif // CVIPCOUNT_H
