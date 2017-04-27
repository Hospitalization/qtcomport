#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::FramelessWindowHint); // hide title bar
    // w.setAttribute(Qt::WA_TranslucentBackground);    // transparent
    // w.setMask(); // transparent by pixmap
    w.show();

    return a.exec();
}
