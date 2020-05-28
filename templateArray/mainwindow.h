#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "masiv.h"
#include "myvector.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;

    Masiv<MyVector> vArr[10];// масив із 10 масивів користувацького типу
    static int CntOfArrays;
    static int CntOfElements;

private slots:

    void on_sortUp_clicked();

    void on_sortDown_clicked();

    void on_start_clicked();

    void on_compareBut_clicked();

    void on_enterAr_clicked();

private:
};
#endif // MAINWINDOW_H
