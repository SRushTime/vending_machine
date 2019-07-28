#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->view->display(QString::number(money));
    //ui->co100->setEnabled(false);

    if (100>money)
        ui->co100->setEnabled(false);
        ui->te150->setEnabled(false);
        ui->la200->setEnabled(false);

    if (150>money)
        ui->te150->setEnabled(false);
        ui->la200->setEnabled(false);

    if (200>money)
        ui->la200->setEnabled(false);

    if (100<=money)
        ui->co100->setEnabled(true);

    if (150<=money)
        ui->te150->setEnabled(true);

    if (200<=money)
        ui->la200->setEnabled(true);
}

void Widget::on_Add10_clicked()
{
    changeMoney(10);
}

void Widget::on_Add50_clicked()
{
    changeMoney(50);
}

void Widget::on_Add100_clicked()
{
    changeMoney(100);
}

void Widget::on_Add500_clicked()
{
    changeMoney(500);
}

void Widget::on_co100_clicked()
{
    changeMoney(-100);
}

void Widget::on_te150_clicked()
{
    changeMoney(-150);
}

void Widget::on_la200_clicked()
{
    changeMoney(-200);
}

void Widget::on_change_clicked()
{
    int won[4] = {500, 100, 50, 10};
    int i, count[4];
    for (i = 0; i < 4; i++){
        count[i] = money / won[i];
        money = money - count[i]*won[i];
    }
    QMessageBox msg;
    msg.information(nullptr, "change",
            "10 won : " + QString::number(count[3])+"\n"+
            "50 won : " + QString::number(count[2])+"\n"+
            "100 won : " + QString::number(count[1])+"\n"+
            "500 won : " + QString::number(count[0])+"\n");

    changeMoney(-money);
}
