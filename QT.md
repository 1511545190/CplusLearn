# 图形绘制
#include "widget.h"
#include "./ui_widget.h"
#include <QColorDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pencolor = QColorDialog(this).getColor();
    mpainter = new QPainter(this);//painter对象
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //准备工作
    mpainter->begin(this);

    QPen pen(QColor(pencolor),3);

    mpainter->setPen(pencolor);

    //画线条
    mpainter->drawLine(0,0,100,100);
    mpainter->drawLine(QPoint(10,10),QPoint(10,100));

    //画矩形
    mpainter->setPen(QColorDialog::getColor());
    mpainter->drawRect(100,100,100,200);
    mpainter->drawRect(QRect(QPoint(100,170),QPoint(200,200)));

    //画圆
    mpainter->drawEllipse(QRect(QPoint(200,200),QPoint(205,205)));

}

