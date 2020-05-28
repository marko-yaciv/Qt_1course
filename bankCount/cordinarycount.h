#ifndef CORDINARYCOUNT_H
#define CORDINARYCOUNT_H
#include "bankcount.h"

class CordinaryCount : public bankCount
{
public:
    void payBills(double sum) override;
    void grabCash(double sum) override;

    static QString print();
    CordinaryCount();
};

#endif // CORDINARYCOUNT_H
