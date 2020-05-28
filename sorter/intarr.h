#ifndef INTARR_H
#define INTARR_H
#include "comparator.h"
#include <iostream>
class IntArr: public virtual Comparator
{
private:
    int* arr;
public:
    IntArr(){std::cout<<"int arr constructor"<<std::endl;};
    IntArr(int);
    ~IntArr() override;

    void fillArr(int i, int val);

    virtual void setSize(int s);

    void sort() override;

    int operator[](int i);
};

#endif // INTARR_H
