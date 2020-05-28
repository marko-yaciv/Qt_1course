#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <bankcount.h>
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
    void showCabinet(bankCount *owner);


signals:
    void signalFromRadioBut(int butID);
   // void accountSignalType(bankCount *count);
public slots:
    void slotRadioBut();
    void slotRadioBut2();
    void slotRadioBut3();
    void slotMsg(int butID);
    //void createSpecType(bankCount *count);
private slots:
    void on_radioButton_customContextMenuRequested(const QPoint &pos);

    void on_radioButton_2_customContextMenuRequested(const QPoint &pos);

    void on_radioButton_3_customContextMenuRequested(const QPoint &pos);

    void on_createCount_clicked();

    void on_replenishBut_clicked();

    void on_action_triggered();

    void on_getCashBtn_clicked();

    void on_payByOwnBtn_clicked();

    void on_payByCredBtn_clicked();

    void on_transByOwnBtn_clicked();

    void on_actionVIP_count_triggered();

    void on_actionSocial_count_triggered();

    void on_actionOrdinary_count_triggered();

    void on_actionShow_counts_triggered();

private:
};
#endif // MAINWINDOW_H
