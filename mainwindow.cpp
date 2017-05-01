#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QtSerialPort/qserialportinfo.h>
#include <QtSerialPort/QSerialPort>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *verticalLayoutWidget = new QWidget(this);
    QVBoxLayout *verticalLayout = new QVBoxLayout(verticalLayoutWidget);
    int nLabel= 3;
    this->resize(QSize(374, 50 * nLabel));
    QLabel *label[nLabel];
    for(int i = 0; i < nLabel; i++)
    {
        label[i] = new QLabel(verticalLayoutWidget);
        label[i]->setText("Label");
        verticalLayout->addWidget(label[i]);
    }

    //verticalLayout->alignment();
    //verticalLayoutWidget->raise();
    this->setCentralWidget(verticalLayoutWidget);

    qDebug() << "Number of serial ports:" << QSerialPortInfo::availablePorts().count();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        qDebug() << serialPortInfo.portName();

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
