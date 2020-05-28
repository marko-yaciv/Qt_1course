#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
private slots:
    void digit_numbers();
    void on_pushButton_dot_clicked();
    void oneNumber_operations();
    void on_pushButton_C_clicked();
    void on_pushButton_equal_clicked();
    void math_operations();
};
#endif // CALCULATOR_H
