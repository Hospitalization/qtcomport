#include "portwindow.h"
#include "ui_portwindow.h"

portwindow::portwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portwindow)
{
    ui->setupUi(this);
}

portwindow::~portwindow()
{
    qDebug()<<"portwindow destroy";
    delete ui;
}

void portwindow::on_pushButton_OK_clicked()
{

}

void portwindow::on_pushButton_Cancel_clicked()
{
    close();
}
