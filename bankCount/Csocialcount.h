#ifndef CSOCIALCOUNT_H
#define CSOCIALCOUNT_H
#include "bankcount.h"

class CsocialCount : public bankCount{
public:
    void payBills(double sum) override;
    void grabCash(double sum) override;
    static QString print();
    CsocialCount();
private:
    void addPercentToSum();
};

#endif // CSOCIALCOUNT_H
