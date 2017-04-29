#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window  | Qt::WindowStaysOnTopHint); // hide title bar // | Qt::FramelessWindowHint
    // w.setAttribute(Qt::WA_TranslucentBackground);    // transparent
    // w.setMask(); // transparent by pixmap
    w.show();

    return a.exec();
}
