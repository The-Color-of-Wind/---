#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "iwidget.h"
#include "startsoftwarewidget.h"
#include "widget3.h"

#include <QWidget>

#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QPalette>
#include <QPainter>
#include <QPixmap>

#include <QFrame>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QMovie>
#include <QTimer>
#include <QProcess>
#include <QSplitter>
#include <QStackedWidget>
#include <QSvgRenderer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE
class StartSoftwareWidget;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public:
    void showEvent(QShowEvent *event);  // 初始化背景
    void initVariables();   // 初始化参数
    void initTop();

    void initBottom();
    void initLeft();

public:


private:
    Ui::MainWidget *ui;
    QStackedWidget *stackedWidget;
    IWidget* startSoftwareWidget;
    IWidget* widget3;

private:    // top 参数
    QLabel *u2ImageLabel;  // 用于显示图片
    QLabel *titleLabel;   // 用于显示文字

private:    //left 参数
    QVector<QPushButton*> changePushButton;
    QVector<QString> changeButtonIcon;
    QVector<IWidget*> changeWidget;

private:    //bottom 参数
    QVector<QString> bottomFunctionButton;

};
#endif // MAINWIDGET_H

