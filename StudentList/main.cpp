#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon("D:\\Programing\\QtProjects\\StudentList\\appIcon.ico");
    w.setWindowIcon(icon);
    w.setWindowTitle("Student list");
    w.show();
    return a.exec();
}
