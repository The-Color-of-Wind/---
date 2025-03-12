#ifndef WIDGET2_H
#define WIDGET2_H

#include "iwidget.h"
#include <QWidget>

namespace Ui {
class Widget2;
}

class Widget2 : public IWidget
{
    Q_OBJECT

public:
    explicit Widget2(QWidget *parent = nullptr);
    ~Widget2();
    virtual void initMiddle();

private:
    Ui::Widget2 *ui;
};

#endif // WIDGET2_H
