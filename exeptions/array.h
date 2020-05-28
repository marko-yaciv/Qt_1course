#ifndef ARRAY_H
#define ARRAY_H

#include <QTextStream>
#include <QVector>
class Array
{
private:
    QVector<double> arr;
    double sum;
    double avg;
    double min;
    double max;
public:
    Array();
    double at(int i);
    int getSize();
    double getsum();
    double getavg();
    double getmax();
    double getmin();
    void readFile(QTextStream& in) throw(QString);
    void writeFile(QTextStream& in);
};

#endif // ARRAY_H
