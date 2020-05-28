#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openRfile(QFile& f) throw(QString);
private slots:
    void on_read_clicked();

    void on_write_clicked();

    void on_maxB_clicked();

    void on_MinB_clicked();

    void on_SumB_clicked();

    void on_AvgB_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
