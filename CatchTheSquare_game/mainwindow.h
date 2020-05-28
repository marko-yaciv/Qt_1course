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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer* timer;
    int winI;
    int winJ;
    int atempts;
    int level;
    int ticks;
    bool failed;
public slots:
    void fillGrid();
    void cellClicked(int i, int j);
    void tryAgain();
    void lose();
    void MakeLevelShape(int rows, int cols);
private slots:
    void on_actionEasy_triggered();

    void on_actionMedium_triggered();

    void on_actionHard_triggered();



    void on_StartButton_clicked();

    void on_actionHow_to_play_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
