#include "triangle.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

int Triangle::cnt = 0;
//-------------------constructors-----------------------------------
Triangle::Triangle()
{
   cnt++;
}
Triangle::~Triangle(){
    --cnt;
}
Triangle::Triangle(double aVal, double bVal, double cVal)
{
    sites[0] = aVal;
    sites[1] = bVal;
    sites[2] = cVal;
    Triangle::cnt++;
}
Triangle::Triangle(int aVal, int bVal, int cVal)
{
    sites[0] = aVal;
    sites[1] = bVal;
    sites[2] = cVal;
    cnt++;
}

void Triangle::cntObj(){
   cnt++;
}

void Triangle::showCnt(Ui::MainWindow *ui)
{
    ui->cnt->setNum(cnt);
}

//---------setters-----------------------------------------------
void Triangle::setALen(int len) {
    sites[0] = abs(len);
}

void Triangle::setBLen(int len) {
    sites[1] = abs(len);
}
void Triangle::setCLen(int len) {
    sites[2] = abs(len);
}

void Triangle::setS(){
    double p = P/2;
    s = sqrt((p*(p-sites[0])*(p-sites[1])*(p-sites[2])));
}
void Triangle::setP(){
    P = (sites[0] + sites[1] + sites[2]);
}
void Triangle::setCorners(){
    corA = acos((pow(sites[1],2)+pow(sites[2],2)-pow(sites[0],2))/(2*sites[1]*sites[2]))*180/M_PI;
    corB = acos((pow(sites[0],2)+pow(sites[2],2)-pow(sites[1],2))/(2*sites[0]*sites[2]))*180/M_PI;
    corC = acos((pow(sites[0],2)+pow(sites[1],2)-pow(sites[2],2))/(2*sites[1]*sites[0]))*180/M_PI;
}
void Triangle::setH(){
    ha = (2*s)/sites[0];
    hb = (2*s)/sites[1];
    hc = (2*s)/sites[2];
}

void Triangle::setScale(Ui::MainWindow *ui){
    scaleK = ui->scaleIn->text().toDouble();
}
//---------------getters---------------------------------------------
double Triangle::getS()
{
    return this->s;
}
double Triangle::getP(){
    return this->P;
}
double Triangle::getHa(){
    return this->ha;
}
double Triangle::getHb(){
    return this->hb;
}
double Triangle::getHc(){
    return this->hc;
}

double Triangle::getCorA(){
    return this->corA;
}

double Triangle::getCorB(){
    return this->corB;
}

double Triangle::getCorC(){
    return this->corC;
}

double Triangle::getScale()
{
    return this->scaleK;
}


//----------------Overloaded operators----------------------------
Triangle Triangle::operator*=(const double &k){
    this->sites[0]*=k;
    this->sites[1]*=k;
    this->sites[2]*=k;
    return *this;
}

Triangle Triangle::operator+=(const double & k)
{
    this->sites[0]+=k;
    this->sites[1]+=k;
    this->sites[2]+=k;
    return *this;
}

int& Triangle::operator[](const int index)
{
    return sites[index];
}

Triangle Triangle::operator()(){
    for(int i=0;i<3;++i)
        this->sites[i] = (double)this->sites[i];
    return *this;
}
//--------------------------------------------------------------
bool Triangle::isExist(){
    if((sites[0]+sites[1]) <= sites[2]){
        return false;
    }else if((sites[0]+sites[2]) <= sites[1]){
        return false;
    }else if((sites[1]+sites[2]) <= sites[0]){
        return false;
    }else return true;
}

void Triangle::readInfo(Ui::MainWindow *ui) {
    sites[0] = ui->aIn->text().toDouble();
    sites[1] = ui->bIn->text().toDouble();
    sites[2] = ui->cIn->text().toDouble();

}

void Triangle::showInfo(Ui::MainWindow *ui){
    ui->aOut->setText("a = " + QString::number(sites[0]));
    ui->bOut->setText("b = " + QString::number(sites[1]));
    ui->cOut->setText("c = " + QString::number(sites[2]));
}
bool Triangle::isRectang(){
    if(sites[0]>sites[1]){
        if(sites[0]>sites[2]){
            return (pow(sites[0],2) == pow(sites[1],2)+pow(sites[2],2));
        }else{
            return (pow(sites[2],2) == pow(sites[1],2)+pow(sites[0],2));
        }
    }else{
        if(sites[1]>sites[2]){
            return (pow(sites[1],2) == pow(sites[2],2)+pow(sites[2],2));
        }else{
            return (pow(sites[2],2) == pow(sites[1],2)+pow(sites[0],2));
        }
    }
}

//-----------------friend operators--------------------------------------
Triangle operator<<(Triangle &triangle,const Ui::MainWindow *ui)
{
   triangle.sites[0] = ui->aIn->text().toDouble();
   triangle.sites[1] = ui->bIn->text().toDouble();
   triangle.sites[2] = ui->cIn->text().toDouble();
   return triangle;
}
void operator >>(Ui::MainWindow *ui,const Triangle &triangle){
    ui->aOut->setText("a = " + QString::number(triangle.sites[0]));
    ui->bOut->setText("b = " + QString::number(triangle.sites[1]));
    ui->cOut->setText("c = " + QString::number(triangle.sites[2]));
}
bool operator>(Triangle &first, Triangle &second){
    return first.getP() > second.getP();
}
bool operator<(Triangle &first, Triangle &second){
    return first.getP() < second.getP();
}
bool operator==(Triangle &first, Triangle &second){
    return first.getS() == second.getS();
}
//-----------------------------------------------------------------------
