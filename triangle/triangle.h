#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <mainwindow.h>
class Triangle{

private:
    static int cnt;

    int sites[3];

    double s;
    double P;

    double ha;
    double hb;
    double hc;

    double scaleK;

    double corA;
    double corB;
    double corC;

public:
    Triangle();
    Triangle(double, double, double);
    Triangle(int, int, int);
    ~Triangle();
    void setALen(int sites);
    void setBLen(int sites);
    void setCLen(int sites);
    void setP();
    void setS();
    void setH();
    void setScale(Ui::MainWindow *ui);
    void setCorners();

    double getS();
    double getP();
    double getHa();
    double getHb();
    double getHc();
    double getCorA();
    double getCorB();
    double getCorC();
    double getScale();

    void readInfo(Ui::MainWindow *ui);
    void showInfo(Ui::MainWindow *ui);
    bool isRectang();
    bool isExist();

    int& operator[](const int index);
    Triangle operator*=(const double &);
    Triangle operator+=(const double &);
    Triangle operator()();

    friend  Triangle operator<<(Triangle &triangle,const Ui::MainWindow *ui);
    friend void operator>>(Ui::MainWindow *ui,const Triangle &triangle);
    friend bool operator>(Triangle &, Triangle &);
    friend bool operator<(Triangle &, Triangle &);
    friend bool operator==(Triangle &, Triangle &);

    static void cntObj();
    static void showCnt(Ui::MainWindow *ui);
};
#endif // TRIANGLE_H
