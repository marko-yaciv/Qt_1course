#ifndef MASIV_H
#define MASIV_H
#include <iostream>
#include <QLabel>
#include "myvector.h"

template<typename T>
class Masiv
{
private:
    T max;
    T sum;
    double sumv;
    T* array;
    int size;

public:
    Masiv(int s);
    Masiv();
    ~Masiv();

    void setSize(int s);
    int getSize() const;
    void sortUp();
    void sortDown();

    T bigest();
    double findSum();
    void swap(T& first, T&sec);
    void print(QLabel* label);

    T& at(int pos);
    T& operator[](const int pos);
};
//------------------------------
template<typename T>
Masiv<T>::Masiv(int s){
    size = s;
    array = new T[size];
}

template<typename T>
Masiv<T>::Masiv(){
    size = 0;
}

template<typename T>
Masiv<T>::~Masiv(){
    if(size > 0)
        delete[] array;
}
//--------------------------
template<typename T>
void Masiv<T>::setSize(int s){
    if(s > 1){
        T* newAr = new T[s];
        for(int i = 0;i < size;++i){
            newAr[i] = array[i];
        }
        delete [] array;
        array = newAr;

    }else{
        array = new T[s];
    }
    size = s;
}

template<typename T>
int Masiv<T>::getSize() const{
    return size;
}
//--------------------------------------
template<typename T>
void Masiv<T>::swap(T& first, T&sec){
    T tmp;
    tmp = first;
    first = sec;
    sec = tmp;
}

template<typename T>
void Masiv<T>::sortUp(){
    for(int i=1; i < size; ++i){
        int j=i;
        while(array[j] < array[j-1] && j>0){
            swap(array[j], array[j-1]);
            --j;
        }
    }
}

template<typename T>
void Masiv<T>::sortDown(){
    for(int i=1; i < size; ++i){
        int j=i;
        while(array[j] > array[j-1] && j>0){
            swap(array[j], array[j-1]);
            --j;
        }
    }
}
//-------------------------------------
template<typename T>
T Masiv<T>::bigest(){
    max = array[0];
    for(int i = 1; i < size; ++i){
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

template<typename T>
double Masiv<T>::findSum(){
    sum = 0;
    for(int i = 0; i < size; ++i){
        sum += array[i];
    }
    return sum;
}

template<typename T>
T& Masiv<T>::at(int pos){
    return array[pos];
}

template<typename T>
T& Masiv<T>::operator[](const int pos){
    return array[pos];
}
//-----------------------------------------------------------
//-----------------Спеціалізований клас---------------------------
template<>
class Masiv<MyVector>{
private:
    MyVector max;
    double sumv;
    MyVector* array;
    int size;
public:
    Masiv(int s){
        size = s;
        array = new MyVector[size];
    }
    Masiv(){
        size = 0;
    }
    ~Masiv(){
        if(size > 0)
            delete[] array;
    }
    void setSize(int s){
        if(s > 1){
            MyVector* newAr = new MyVector[s];
            for(int i = 0;i < size;++i){
                newAr[i] = array[i];
            }
            delete [] array;
            array = newAr;

        }else{
            array = new MyVector[s];
        }
        size = s;
    }
    int getSize() const{
        return size;
    }
    void print(QLabel* label){
        label->clear();

        for(int i = 0; i < size; ++i){
            label->setText(label->text() +"( ("+QString::number(array[i].getSX()) + "; " +
                           QString::number(array[i].getSY()) + "), (" +
                           QString::number(array[i].getEX()) + "; " +
                           QString::number(array[i].getEY()) + ")),  ");
        }
    }

    void sortUp(){
        for(int i=1; i < size; ++i){
            int j=i;
            while(array[j] < array[j-1] && j>0){
                swap(array[j], array[j-1]);
                --j;
            }
        }
    }
    void sortDown(){
        for(int i=1; i < size; ++i){
            int j=i;
            while(array[j] > array[j-1] && j>0){
                swap(array[j], array[j-1]);
                --j;
            }
        }
    }

    MyVector bigest(){
        max = array[0];
        for(int i = 1; i < size; ++i){
            if(array[i] > max)
                max = array[i];
        }
        return max;
    }
    double findSum(){

        sumv = 0;
        for(int i = 0; i < size; ++i){
            sumv += array[i].len();
        }
        return sumv;
    }

    MyVector& at(int pos){
        return array[pos];
    }
    MyVector& operator[](const int pos){
        return array[pos];
    }
    void swap(MyVector& first, MyVector&sec){
        MyVector tmp;
        tmp = first;
        first = sec;
        sec = tmp;
    }
};

#endif // MASYVCHIC_H
