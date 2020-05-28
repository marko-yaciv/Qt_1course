#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Calculator w;
    w.setWindowIcon(QIcon("D:\\PhotoVideo\\Wallpapers\\Icons\\Calculator_22687.ico"));
    w.show();

    return a.exec();
}
