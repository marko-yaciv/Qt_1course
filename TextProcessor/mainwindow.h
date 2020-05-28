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

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_text_editor_triggered();

    void on_actionFont_triggered();

    void on_actionFind_triggered();

    void on_findButton_pressed();

    void on_findButton_clicked();

    void on_actionAdd_image_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString file_path;
};
#endif // MAINWINDOW_H
