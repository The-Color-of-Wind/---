#ifndef STARTSOFTWAREWIDGET_H
#define STARTSOFTWAREWIDGET_H

#include <QWidget>
#include "mainwidget.h"
#include "iwidget.h"

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

namespace Ui {
class StartSoftwareWidget;
}

class StartSoftwareWidget : public IWidget
{
    Q_OBJECT

public:
    explicit StartSoftwareWidget(QWidget *parent = nullptr);
    ~StartSoftwareWidget();

public:

    void initVariables();

    virtual void initMiddle();

    bool eventFilter(QObject *watched, QEvent *event);  // 捕获系统描述框

    void smoothScrollTo(int targetPosition);    // 增加滚动效果

private slots:
    void scrollLeft();   // 左侧滚动
    void scrollRight();  // 右侧滚动

private:
    Ui::StartSoftwareWidget *ui;

private:    // middle 参数
    QScrollArea *scrollArea;  // 滚动区域
    QWidget *scrollWidget;    // 容纳所有方框的滚动容器
    QHBoxLayout *layout;      // 水平布局
    QPushButton *leftButton;  // 向左滚动按钮
    QPushButton *rightButton; // 向右滚动按钮

    int currentIndex;   // 当前第一个可见方框索引
    int totalFrames;    // 总方框数量
    int visibleFrames;    // 每次可见的方框数量
    int frameWidth;    // 每个方框的宽度

    QVector<QString> softwareName;  // 软件名
    QVector<QString> softwareIcon;  // 软件图标
    QVector<QString> softwareFileName;  // .exe 文件名
    QVector<QString> softwareURL;   // .exe 路径
};

#endif // STARTSOFTWAREWIDGET_H
