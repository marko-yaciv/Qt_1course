#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>

std::stack<float> stack1;
std::stack<float> stack2;

std::queue<float> queue1;
std::queue<float> queue2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sortDown(std::stack<float>& s){
    QList<float> list;
    while (!s.empty()) {
        list.append(s.top());
        s.pop();
    }
    std::sort(list.begin(), list.end(),std::greater<float>());

    for (auto i:list) {
        s.push(i);
    }
}

void MainWindow::sortUp(std::stack<float> &s){
    QList<float> list;
    while (!s.empty()) {
        list.append(s.top());
        s.pop();
    }
    std::sort(list.begin(), list.end());

    for (auto i:list) {
        s.push(i);
    }
}

void MainWindow::sortUp(std::queue<float> &s){
    QList<float> list;
    while (!s.empty()) {
        list.append(s.front());
        s.pop();
    }

    std::sort(list.begin(), list.end());

    for (auto i:list) {
        s.push(i);
    }
}

void MainWindow::on_enterS_1_clicked(){
    ui->outS1->clear();
    while(!stack1.empty()){
        stack1.pop();
    }
    QStringList nums = ui->inS_1->text().split(' ', QString::SkipEmptyParts);
    for (int i = 0; i < nums.size(); ++i){
        stack1.push(nums[i].toFloat());
    }
    auto stackL = stack1;
    QList<float> list;
    while(!stackL.empty()){
        list.append(stackL.top());
        stackL.pop();
    }
    for (auto i = list.begin();i != list.end();++i) {
        ui->outS1->setText(ui->outS1->text() + QString::number(*i) + " ");
    }
    ui->inS_1->clear();
}

void MainWindow::on_enterS_2_clicked(){

    ui->outS2->clear();
    while(!stack2.empty()){
        stack2.pop();
    }
    QStringList nums = ui->inS_2->text().split(' ', QString::SkipEmptyParts);
    for (int i = 0; i < nums.size(); ++i){
        stack2.push(nums[i].toFloat());
    }
    auto stackL = stack2;
    QList<float> list;
    while(!stackL.empty()){
        list.push_back(stackL.top());
        stackL.pop();
    }
    for (auto i = list.begin();i != list.end();++i) {
        ui->outS2->setText(ui->outS2->text() + QString::number(*i) + " ");
    }
    ui->inS_2->clear();
}

void MainWindow::on_enter_N_clicked(){
    ui->outS1->clear();
    float val = ui->in_N->value();
    while(stack1.top() != val){
        stack1.pop();
    }


    auto stackL = stack2;
    QList<float> list;
    while(!stackL.empty()){
        list.append(stackL.top());
        stackL.pop();
    }
    for (const auto it:list)
        stack1.push(it);

    sortDown(stack1);
    auto stackl = stack1;
    while(!stackl.empty()){
         ui->outS1->setText(ui->outS1->text() + QString::number(stackl.top()) + " ");
         stackl.pop();
    }
}

void MainWindow::on_pushButton_clicked()
{
    float val = ui->doubleSpinBox->value();
    auto tmp = stack1;
    while(tmp.top() < val){
        queue1.push(tmp.top());
        tmp.pop();
    }
    sortUp(queue1);
    sortUp(stack1);

    auto tmp1 = queue1;
    while(!tmp1.empty()){
        ui->outQ->setText(ui->outQ->text() + QString::number(tmp1.front()) + " ");
        tmp1.pop();
    }
    tmp = stack1;
    ui->outS1->clear();
    while(!tmp.empty()){
        ui->outS1->setText(ui->outS1->text() + QString::number(tmp.top()) + " ");
        tmp.pop();
    }
}

void MainWindow::on_pushButton_2_clicked(){
    auto tmp  = stack1;
    while(!tmp.empty()) {
        queue2.push(tmp.top());
        tmp.pop();
    }
    auto tmp1 = queue1;
    while(!tmp1.empty()){
        queue2.push(tmp1.front());
        tmp1.pop();
    }

    sortUp(queue2);
    tmp1 = queue2;

    while(!tmp1.empty()){
        ui->outQ_2->setText(ui->outQ_2->text() + QString::number(tmp1.front()) + " ");
        tmp1.pop();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    float val  = ui->doubleSpinBox_2->value();
    int cnt = 0;
    auto tmp = queue2;
    while(tmp.front() < val){
        cnt++;
        tmp.pop();
        if(tmp.empty()) break;
    }
    ui->elsToShow->setNum(cnt);
}
