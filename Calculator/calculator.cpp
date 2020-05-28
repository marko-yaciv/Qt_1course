#include "calculator.h"
#include "ui_calculator.h"
#include <cstring>


double fNumber;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digit_numbers()));
    connect(ui->pushButton_PlusMinus,SIGNAL(clicked()),this,SLOT(oneNumber_operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(oneNumber_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::digit_numbers(){
    QPushButton *button = (QPushButton *)sender();
    double full_number;
    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0"){
        new_label = ui->result_show->text() + button->text();
    }else{
        full_number = (ui->result_show->text()+button->text()).toDouble();
        new_label = QString::number(full_number, 'g', 15);

    }
    ui->result_show->setText(new_label);
}

void Calculator::on_pushButton_dot_clicked()
{
    if(!ui->result_show->text().contains('.'))
        ui->result_show->setText(ui->result_show->text()+".");
}

void Calculator::oneNumber_operations(){
    QPushButton *button = (QPushButton *)sender();
    double full_number;
    QString new_label;

    if(button->text() == "+/-"){
        full_number = (ui->result_show->text()).toDouble();
        full_number *= -1;
        new_label = QString::number(full_number, 'g', 15);

        ui->result_show->setText(new_label);
    }
    else if(button->text() == "%"){
        full_number = (ui->result_show->text()).toDouble();
        full_number *= 0.01;
        new_label = QString::number(full_number, 'g', 15);

        ui->result_show->setText(new_label);
    }
}
void Calculator::math_operations(){
    QPushButton *button = (QPushButton *)sender();

    fNumber = ui->result_show->text().toDouble();

    //ui->result_show->setText(ui->result_show->text() + button->text());
    ui->result_show->setText(" ");
    button->setChecked(true);
}
void Calculator::on_pushButton_C_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    ui->result_show->setText("0");
}

void Calculator::on_pushButton_equal_clicked()
{
    double labelNum, sNumber;
    QString new_label;


    sNumber = ui->result_show->text().toDouble();
    if(ui->pushButton_plus->isChecked()){
        labelNum = fNumber+sNumber;
        new_label = QString::number(labelNum, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_minus->isChecked()){
        labelNum = fNumber - sNumber;
        new_label = QString::number(labelNum, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }else if(ui->pushButton_divide->isChecked()){
        if(sNumber == 0){
            ui->result_show->setText("do not do this");
        }
        else{
            labelNum = fNumber / sNumber;
            new_label = QString::number(labelNum, 'g', 15);
            ui->result_show->setText(new_label);
        }
        ui->pushButton_divide->setChecked(false);
    }else if(ui->pushButton_multiply->isChecked()){
        labelNum = fNumber * sNumber;
        new_label = QString::number(labelNum, 'g', 15);
        ui->result_show->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    }
}

