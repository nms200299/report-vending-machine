#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money_ += diff;
    ui->lcd->display(money_);

    if (money_ >= 100){
        ui->pbCoffee->setEnabled(true);
        if (money_ >= 150){
            ui->pbTea->setEnabled(true);
            if (money_ >= 200){
                ui->pbMilk->setEnabled(true);
            } else {
                ui->pbMilk->setEnabled(false);
            }
        } else {
            ui->pbTea->setEnabled(false);
            ui->pbMilk->setEnabled(false);
        }
    } else {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }

}

void Widget::countMoney(int std){
    QString temp="";

    if (money_ / std >= 1){
       temp += QString::number(std);
       temp += "원=";
       temp += QString::number(money_ / std);
       temp += "개 ";
       changeMoney(0 - (std * (int)(money_ / std)));
       ui->label->setText(ui->label->text()+temp);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}
void Widget::on_pb50_clicked()
{
    changeMoney(50);
}
void Widget::on_pb100_clicked()
{
    changeMoney(100);
}
void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}
void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}
void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    if (money_ <= 0){
        ui->label->setText("초기화할 잔액이 없습니다.");
    } else {
        ui->label->setText("");
        countMoney(500);
        countMoney(100);
        countMoney(50);
        countMoney(10);
    }
}

