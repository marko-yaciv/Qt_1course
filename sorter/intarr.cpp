#include "intarr.h"
IntArr::IntArr(int sz)
{
    arr = new int[sz];
    Comparator::size = sz;
    std::cout<<"int arr constructor"<<std::endl;
}

IntArr::~IntArr()
{
    delete [] arr;
    std::cout<<"int arr destructor"<<std::endl;
}

void IntArr::fillArr(int i, int val)
{
    arr[i] = val;
}

void IntArr::setSize(int s)
{
    arr = new int[s];
    Comparator::size = s;
}

void IntArr::sort()
{
    for(int i=1; i < size; ++i){
            int j=i;
            while(arr[j]<arr[j-1] && j>0){
                long tmp;
                tmp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tmp;
                --j;
            }
        }

}
int IntArr::operator[](int i)
{
    return arr[i];
}
