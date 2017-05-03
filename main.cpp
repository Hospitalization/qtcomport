#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window  | Qt::WindowStaysOnTopHint); // hide title bar // | Qt::FramelessWindowHint
    // w.setAttribute(Qt::WA_TranslucentBackground);    // transparent
    // w.setMask(); // transparent by pixmap
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    w.move(width - 550, height - 350);

    w.show();

    return a.exec();
}
