#include "myvector.h"
#include <cmath>
MyVector::MyVector()
{
    start.x = 0;
    start.y = 0;

    end.x = 0;
    end.y = 0;
    l = 0;
}

MyVector::MyVector(double sx, double sy, double ex, double ey)
{
    start.x = sx;
    start.y = sy;

    end.x = ex;
    end.y = ey;

    l = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
}

void MyVector::setStart(double sx, double sy)
{
    start.x = sx;
    start.y = sy;

    l = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
}

void MyVector::setEnd(double ex, double ey)
{
    end.x = ex;
    end.y = ey;

    l = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
}

bool MyVector::operator <(const MyVector &sec)
{
    return this->len() < sec.len();
}

bool MyVector::operator >(const MyVector &sec)
{
    return this->len() > sec.len();
}

void MyVector::operator =(const MyVector &sec)
{
    this->start.x = sec.start.x;
    this->start.y = sec.start.y;

    this->end.x = sec.end.x;
    this->end.y = sec.end.y;

    this->l = sec.l;
}

double MyVector::len() const
{
    return l;
}
