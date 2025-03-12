#include "widget3.h"
#include "ui_widget3.h"
#include <QApplication>
#include <QLabel>
#include <QSvgRenderer>
#include <QPixmap>
#include <QPainter>
Widget3::Widget3(QWidget *parent)
    : IWidget(parent)
    , ui(new Ui::Widget3)
{
    ui->setupUi(this);
    initMiddle();
}
void Widget3::initMiddle()
{

    QLabel *label = new QLabel(this);
    QMovie *movie = new QMovie("C:/Users/19466/Desktop/aaa.gif");

    if (!movie->isValid()) {
        qDebug() << "Failed to load GIF!";
    } else {
        qDebug() << "GIF loaded successfully.";
    }
    label->setMovie(movie);

    movie->start();
/*
    // 加载 SVG 图像
    QSvgRenderer renderer(QString("C:/Users/19466/Desktop/a/u10.svg"));

    QSize svgSize = renderer.defaultSize();  // 获取 SVG 图像的默认尺寸
    QPixmap pixmap(svgSize*2);  // 使用实际的尺寸初始化 QPixmap
    pixmap.fill(Qt::transparent);  // 填充透明背景

    // 使用 QPainter 绘制 SVG 到 QPixmap 上
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);  // 启用抗锯齿
    painter.setRenderHint(QPainter::SmoothPixmapTransform);  // 启用平滑变换
    painter.begin(&pixmap);  // 开始渲染
    renderer.render(&painter);  // 渲染 SVG
    painter.end();  // 结束渲染

    // 设置 QLabel 显示渲染后的图像
    label->setPixmap(pixmap);
    label->setFixedSize(pixmap.size());  // 设置 QLabel 的大小
    label->show();
*/
}
Widget3::~Widget3()
{
    delete ui;
}
