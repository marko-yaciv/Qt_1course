#ifndef DOUBLEARR_H
#define DOUBLEARR_H
#include "comparator.h"
#include "intarr.h"

class DoubleArr:public virtual Comparator, public IntArr
{
private:
    double * arr;
public:
    DoubleArr();
    DoubleArr(int);
    ~DoubleArr() override;

    void fillArr(int i, double val);

    void setSize(int s) override;

    void sort() override;

    double operator[](int i);
};

#endif // DOUBLEARR_H
