#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <stack>
#include <queue>
#include <deque>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void sortDown(std::stack<float>& s);
    void sortUp(std::stack<float>& s);
    void sortUp(std::queue<float>& s);

private slots:
    void on_enterS_1_clicked();

    void on_enterS_2_clicked();

    void on_enter_N_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
