#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QVBoxLayout"

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
//    QLabel *label1 = new QLabel(verticalLayoutWidget);
//    QLabel *label2 = new QLabel(verticalLayoutWidget);
//    label1->setText("label1");
//    label2->setText("label2");
//    verticalLayout->addWidget(label1);
//    verticalLayout->addWidget(label2);
    verticalLayout->alignment();
    //this->setLayout(verticalLayout);
    verticalLayoutWidget->raise();
    this->setCentralWidget(verticalLayoutWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
