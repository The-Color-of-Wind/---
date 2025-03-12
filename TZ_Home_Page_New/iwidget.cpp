#include "iwidget.h"
#include "ui_iwidget.h"

IWidget::IWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IWidget)
{
    ui->setupUi(this);
}

IWidget::~IWidget()
{
    delete ui;
}
