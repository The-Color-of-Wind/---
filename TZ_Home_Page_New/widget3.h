#ifndef WIDGET3_H
#define WIDGET3_H
#include "iwidget.h"
#include <QWidget>

namespace Ui {
class Widget3;
}

class Widget3 : public IWidget
{
    Q_OBJECT

public:
    explicit Widget3(QWidget *parent = nullptr);
    ~Widget3();

    virtual void initMiddle();
private:
    Ui::Widget3 *ui;
};

#endif // WIDGET3_H
