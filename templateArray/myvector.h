#ifndef MYVECTOR_H
#define MYVECTOR_H


class MyVector
{
public:
    MyVector();
    MyVector(double sx, double sy, double ex, double ey);

    void setStart(double sx, double sy);
    void setEnd(double ex, double ey);

    double getSX()const{return start.x;}
    double getSY()const{return start.y;}
    double getEX()const{return end.x;}
    double getEY()const{return end.y;}

    double len()const;
    bool operator <(const MyVector& sec);
    bool operator >(const MyVector& sec);

    void operator = (const MyVector&sec);
private:
    typedef struct{
        double x;
        double y;
    }dot;

    dot start;
    dot end;

    double l;
};

#endif // MYVECTOR_H
