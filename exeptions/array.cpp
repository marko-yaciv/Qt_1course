#include "array.h"
#include <stdexcept>
Array::Array()
{
    arr.reserve(50);
}

double Array::at(int i)
{
    return arr.at(i);
}

int Array::getSize()
{
    return arr.size();
}

double Array::getsum()
{
    sum = 0;
    for (auto i : arr){
        sum += i;
    }
    return sum;
}

double Array::getavg()
{
    avg = getsum() / double(arr.size());
    return avg;
}

double Array::getmax()
{
    max = arr.first();
    for (auto i : arr){
        if (max < i){
            max = i;
        }
    }
    return max;
}

double Array::getmin()
{
    min  = arr.first();
    for(auto i : arr){
        if(min > i){
            min = i;
        }
    }
    return min;
}

void Array::readFile(QTextStream &in) throw(QString)
{
    QString er;
    QString sArr = in.readLine();
    if(sArr.size() == 0){
        er = "blank file";
        throw er;
    }
    QStringList snums = sArr.split(' ', QString::SkipEmptyParts);

    if(snums.size() > 20){
        er = "array in file is so big (>20)";
        throw er;
    }
    if(arr.size() + snums.size() > 20){
        er = "Reached limit of elements in array(>20).\\n"
             "Please shorten the array in file.";
        throw er;
    }
    bool ok = false;
    for (auto i = 0; i < snums.size(); ++i){
       snums.at(i).toDouble(&ok);
       if(!ok)
       {
           er = "The array has incorrect numbers";
           throw er;
       }
    }

    for(auto i: snums){
        arr.push_back(i.toDouble());
    }
    sum = getsum();
    avg = getavg();
    max = getmax();
    min = getmin();
}

void Array::writeFile(QTextStream &in )
{
    for(auto i : arr){
        in << i <<" ";
    }
    in << endl;
    in << "Max: "<< max <<" Min: "<< min << endl;
    in << "Sum: "<< sum <<" Avg: "<< avg << endl;
}
