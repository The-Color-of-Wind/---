#ifndef IWIDGET_H
#define IWIDGET_H

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

namespace Ui {
class IWidget;
}

class IWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IWidget(QWidget *parent = nullptr);
    ~IWidget();

    virtual void initMiddle() = 0;

private:
    Ui::IWidget *ui;
};

#endif // IWIDGET_H
