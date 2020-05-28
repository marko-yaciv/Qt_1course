#ifndef COMPARATOR_H
#define COMPARATOR_H
#include <iostream>
class Comparator
{
public:
    Comparator(){std::cout<<"comparator arr constructor"<<std::endl;};
    virtual ~Comparator(){std::cout<<"comparator arr destructor"<<std::endl;};
    virtual void sort() = 0;

protected:
    int size;
};

#endif // COMPARATOR_H
