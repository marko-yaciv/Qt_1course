#include "doublearr.h"

DoubleArr::DoubleArr(){
    std::cout<<"double arr constructor"<<std::endl;
}

DoubleArr::DoubleArr(int sz)
{
    arr = new double[sz];
    Comparator::size = sz;
    std::cout<<"double arr constructor"<<std::endl;
}

DoubleArr::~DoubleArr()
{
    delete [] arr;
    std::cout<<"double arr destructor"<<std::endl;
}

void DoubleArr::fillArr(int i, double val)
{
    arr[i] = val;
}

void DoubleArr::setSize(int s)
{
    arr = new double[s];
    Comparator::size = s;
}

void DoubleArr::sort()
{
    for(int i=1; i < size; ++i){
        int j=i;
        while(arr[j]<arr[j-1] && j>0){
            double tmp;
            tmp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=tmp;
            --j;
        }
    }
}

double DoubleArr::operator[](int i)
{
    return arr[i];
}
