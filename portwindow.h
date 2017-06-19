#ifndef PORTWINDOW_H
#define PORTWINDOW_H

#include <QWidget>
#include <QtSerialPort/qserialportinfo.h>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QListWidgetItem>

namespace Ui {
class portwindow;
}

class portwindow : public QWidget
{
    Q_OBJECT

public:
    explicit portwindow(QWidget *parent = 0);
    ~portwindow();

private slots:
    void on_pushButton_OK_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::portwindow *ui;
};

#endif // PORTWINDOW_H
