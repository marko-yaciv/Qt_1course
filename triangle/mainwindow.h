#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Ui::MainWindow *ui;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_calcArea_clicked();
    void on_enterSites_clicked();
    void on_calcP_clicked();
    void on_calcH_clicked();
    void on_calcCorners_clicked();
    void on_scaleButOn_clicked();
    void on_scaleButIn_clicked();
};
#endif // MAINWINDOW_H
