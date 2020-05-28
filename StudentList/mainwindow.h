#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addMemberToTable(Student m, int rows);
    void getListFromTable(QList<Student> *);
    void findMinMaxAvgInList(QList<Student>&);
    void sortList(QList<Student>&);
private slots:
    //void on_addMember_clicked();

    void on_filterDateB_clicked();
    void on_filterMarksB_clicked();
    void on_resetB_clicked();
    void on_delMember_clicked();
    void on_actionAdd_New_Member_triggered();

    void memberAded(int isAded);


private:
    Dialog* add;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
