#ifndef ARRAY_H
#define ARRAY_H
#include "comparator.h"

class Array: public virtual Comparator
{

public:
    Array();
    virtual void sort() override;

};

#endif // ARRAY_H
