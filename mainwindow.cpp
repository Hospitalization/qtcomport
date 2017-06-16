#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pThread = new PortDetectThread(this);
    connect(pThread, SIGNAL(detect()), this, SLOT(listCompare()));

    connect(this, SIGNAL(signalListRefresh()), this, SLOT(listRefresh()));
    pThread->start();
}


MainWindow::~MainWindow()
{
    pThread->terminate();
    delete ui;
}

void MainWindow::listCompare(){
    QList<QSerialPortInfo> portListNew = QSerialPortInfo::availablePorts();

    if(portList.size() == portListNew.size()){
        return;
    }else{
        listRefresh();
    }

}

void MainWindow::listRefresh(){

    portList = QSerialPortInfo::availablePorts();
    ui->listWidget->clear();
    foreach (const QSerialPortInfo &serialPortInfo, portList)
    {
        ui->listWidget->addItem(serialPortInfo.portName() + ":" + serialPortInfo.description());
    }
}


void MainWindow::on_pushButton_Refresh_clicked()
{
    emit signalListRefresh();
}
void MainWindow::on_pushButton_PortChange_clicked()
{
    qDebug()<<ui->listWidget->currentIndex().row();
}
void MainWindow::on_pushButton_Quit_clicked()
{
    //this->close();
    QApplication::quit();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug()<<ui->listWidget->currentIndex().row();
}
