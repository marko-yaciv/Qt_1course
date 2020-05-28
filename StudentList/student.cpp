#include "student.h"

double Student::minAvg = 1;
double Student::maxAvg = 1;
Student::Student()
{
    marks = new int[CNT_OF_MARKS];
}

void Student::setFname(QString Fname){
    this->fName = Fname;
}

void Student::setLname(QString Lname){
    this->lName = Lname;
}

void Student::setDate(QDate date){
    this->date = date;
}

void Student::setMarks(int *vals){
    double s = 0;
    for(int i = 0; i < CNT_OF_MARKS; ++i){
        marks[i] = vals[i];
        s+= double(marks[i]);
    }
    avgMark = s/double(CNT_OF_MARKS);
}

void Student::setMinAvg(double val){
    minAvg = val;
}

void Student::setMaxAvg(double val){
    maxAvg = val;
}

 QString Student::getFname() const{
    return fName;
}

QString Student::getLname() const{
    return lName;
}

 QDate Student::getDate() const{
    return date;
}

int* Student::getMarks() const{
    return marks;
}

double Student::getAvg() const{
    return avgMark;
}

int Student::getCntOfMarks(){
    return CNT_OF_MARKS;
}

double Student::getMinAvg(){
    return minAvg;
}

double Student::getMaxAvg(){
    return maxAvg;
}

bool Student::operator<(Student &sec){
    return this->getAvg() < sec.getAvg();
}

void Student::writeToFile(QList<Student>& list, QTextStream & out){
    out.setFieldAlignment(QTextStream::AlignLeft);
    int lSize = list.size();
    for(int i = 0;i < lSize;++i){
        if(i>0) out<<endl;
        out << list.at(i).fName<<"\t\t";
        out << list.at(i).lName<<"\t\t";
        out << list.at(i).date.toString()<<"\t";
        for(int j = 0; j<CNT_OF_MARKS;++j)
            out <<" "<<list.at(i).marks[j];

    }
}

QList<Student> Student::readFromFile(QTextStream & in){
    QList<Student> readList;
    while(!in.atEnd()){
        Student current;
        QStringList member;
        member = in.readLine().split("\t", QString::SkipEmptyParts);
        current.fName = member.at(0);
        current.lName = member.at(1);
        current.date = QDate::fromString(member.at(2));

        QStringList smarks = member.at(3).split(' ',QString::SkipEmptyParts);
        double s = 0;
        for(int i = 0; i < CNT_OF_MARKS;++i){
            current.marks[i] = smarks.at(i).toInt();
            s += current.marks[i];
        }
        current.avgMark = s/CNT_OF_MARKS;

        readList.append(current);
    }
    return readList;

}
