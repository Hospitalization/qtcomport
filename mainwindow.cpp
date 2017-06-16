#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    p_thread = new PortDetectThread(this);
    connect(p_thread, SIGNAL(detect()), this, SLOT(listRefresh()));

    connect(this, SIGNAL(signalListRefresh()), this, SLOT(listRefresh()));
    //emit signalListRefresh();

    p_thread->start();
}


MainWindow::~MainWindow()
{
    p_thread->terminate();
    delete ui;
}

void MainWindow::listRefresh(){
    ui->listWidget->clear();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
//        qDebug() << serialPortInfo.portName();
//        qDebug() << serialPortInfo.description();
        ui->listWidget->addItem(serialPortInfo.portName() + ":" + serialPortInfo.description());
    }
}

void MainWindow::on_pushButton_clicked()
{
    //this->close();
    QApplication::quit();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit signalListRefresh();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
m_nMouseClick_X_Coordinate = event->x();
m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}
