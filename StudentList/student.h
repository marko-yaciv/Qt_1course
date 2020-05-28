#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <QDate>
#include <QTextStream>
#include <QFile>
class Student
{
private:
    QString fName;
    QString lName;
    QDate date;
    int* marks;
    double avgMark;

    static const int CNT_OF_MARKS = 5;

    static double minAvg;
    static double maxAvg;
public:
    Student();
    void setFname(QString fName);
    void setLname(QString lName);
    void setDate(QDate date);
    void setMarks(int* marks);

    static void setMinAvg(double val);
    static void setMaxAvg(double val);

    QString getFname() const;
    QString getLname() const;
    QDate getDate() const;
    int* getMarks() const;
    double getAvg() const;
    static int getCntOfMarks();
    static double getMinAvg();
    static double getMaxAvg();

    bool operator<(Student&sec);

    static void writeToFile(QList<Student>&, QTextStream&);
    static QList<Student> readFromFile(QTextStream&);
};

static QList<Student> sList;
#endif // STUDENT_H
