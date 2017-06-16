#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QtSerialPort/qserialportinfo.h>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QListWidgetItem>

#include "portdetectthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    PortDetectThread *pThread;
    QList<QSerialPortInfo> portList;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Quit_clicked();

    void on_pushButton_Refresh_clicked();

    void listCompare();
    void listRefresh();

    void on_pushButton_PortChange_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

signals:
    void signalListRefresh();

private:
    Ui::MainWindow *ui;

    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
