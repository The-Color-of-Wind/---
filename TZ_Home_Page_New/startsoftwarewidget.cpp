#include "startsoftwarewidget.h"
#include "ui_startsoftwarewidget.h"

StartSoftwareWidget::StartSoftwareWidget(QWidget *parent)
    : IWidget(parent)
    , ui(new Ui::StartSoftwareWidget)
{
    ui->setupUi(this);
    initVariables();
    initMiddle();
}

void StartSoftwareWidget::initVariables()
{
    currentIndex = 0;   // 当前第一个可见方框索引
    totalFrames = 9;    // 总方框数量
    visibleFrames = 4;  // 每次可见的方框数量
    frameWidth = 220;   // 每个方框的宽度

    // ====== 初始化软件描述 ======
    softwareName.append("软件1");
    softwareIcon.append(":/images/a1.jpg");
    softwareURL.append("D:/WeChat/WeChat.exe");

    softwareName.append("管理系统");
    softwareIcon.append(":/images/a2.jpg");
    softwareURL.append("D:/Tencent/QQNT/QQ.exe");

    softwareName.append("监控系统");
    softwareIcon.append(":/images/a3.jpg");
    softwareURL.append(":/images/u0_state0.jpg");

    softwareName.append("aaa");
    softwareIcon.append("C:/Users/19466/Desktop/a/u10.svg");
    softwareURL.append(":/images/u0_state0.jpg");

    softwareName.append("管理系统");
    softwareIcon.append(":/images/a1.jpg");
    softwareURL.append(":/images/u0_state0.jpg");

    softwareName.append("监控系统");
    softwareIcon.append(":/images/a1.jpg");
    softwareURL.append(":/images/u0_state0.jpg");

    softwareName.append("软件1");
    softwareURL.append(":/images/u0_state0.jpg");
    softwareIcon.append(":/images/a1.jpg");

    softwareName.append("管理系统");
    softwareIcon.append(":/images/a1.jpg");
    softwareURL.append(":/images/u0_state0.jpg");

    softwareName.append("监控系统");
    softwareIcon.append(":/images/a1.jpg");
    softwareURL.append(":/images/u0_state0.jpg");

}

void StartSoftwareWidget::initMiddle()
{

    QVBoxLayout *mainLayout = new QVBoxLayout(ui->frame);
    mainLayout->setSpacing(10);

    // ========== 左侧按钮 ==========
    leftButton = new QPushButton(ui->frame);
    leftButton->setFixedSize(40, 60);
    leftButton->setStyleSheet(R"(
        QPushButton {
            border: none;
            background: transparent;
            image: url(:/images/u8.jpg);
        }
        QPushButton:hover {
            image: url(:/images/u8_mouseOver.jpg);
        }
    )");
    QFrame *frameLeftButton = new QFrame(leftButton);
    frameLeftButton->setGeometry(15, 20, 10, 20);  // 设置矩形框的大小和位置
    frameLeftButton->setStyleSheet("border: 2px solid rgba(173, 216, 230, 150);");  // 设置蓝色边框
    frameLeftButton->show();
    connect(leftButton, &QPushButton::clicked, this, &StartSoftwareWidget::scrollLeft);



    // ========== 右侧按钮 ==========
    rightButton = new QPushButton(ui->frame);
    rightButton->setFixedSize(40, 60);
    rightButton->setStyleSheet(R"(
        QPushButton {
            border: none;
            background: transparent;
            image: url(:/images/u8.jpg);
        }
        QPushButton:hover {
            image: url(:/images/u8_mouseOver.jpg);
        }
    )");
    QFrame *frameRightButton = new QFrame(rightButton);
    frameRightButton->setGeometry(15, 20, 10, 20);  // 设置矩形框的大小和位置
    frameRightButton->setStyleSheet("border: 2px solid rgba(173, 216, 230, 150);");  // 设置蓝色边框
    frameRightButton->show();
    connect(rightButton, &QPushButton::clicked, this, &StartSoftwareWidget::scrollRight);

    // ========== 滚动区域 ==========
    scrollArea = new QScrollArea(ui->frame);
    scrollArea->setFixedSize(1000, 500);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setStyleSheet("QScrollArea { background: transparent; border: none; }");

    // ========== 滚动内容窗口 ==========
    scrollWidget = new QWidget();
    layout = new QHBoxLayout(scrollWidget);
    layout->setSpacing(35);

    // ========== 添加 totalFrames 个系统描述框 ==========
    for (int i = 0; i < totalFrames; ++i) {
        QFrame *frame = new QFrame(scrollWidget);
        frame->setFixedSize(frameWidth, 300);
        frame->setStyleSheet("border: none;");

        // ========== 设置背景图片 ==========
        QLabel *backgroundLabel = new QLabel(frame);
        backgroundLabel->setGeometry(0, 0, frameWidth, 300);

        QSvgRenderer backgroundRenderer(QString("C:/Users/19466/Desktop/a/u8.svg"));
        QPixmap backgroundPixmap(backgroundRenderer.defaultSize());  // 使用实际的尺寸初始化 QPixmap
        backgroundPixmap.fill(Qt::transparent);  // 填充透明背景
        QPainter backgroundPainter(&backgroundPixmap);
        backgroundRenderer.render(&backgroundPainter);  // 渲染 SVG
        backgroundLabel->setPixmap(backgroundPixmap.scaled(frameWidth, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        backgroundLabel->setStyleSheet("background: transparent;");
        backgroundLabel->lower();
        backgroundLabel->show();
/*
        QPixmap backgroundPixmap(":/images/u8.jpg");
        backgroundLabel->setPixmap(backgroundPixmap.scaled(frameWidth, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        backgroundLabel->setStyleSheet("background: transparent;");
        backgroundLabel->lower();
*/
        // ========== 显示系统图标 ==========
        QLabel *iconLabel = new QLabel(frame);
        QString imagePath = softwareIcon[i];

        QSvgRenderer renderer(imagePath);
        QPixmap pixmap(renderer.defaultSize()*2);
        pixmap.fill(Qt::transparent);  // 填充透明背景
        QPainter painter(&pixmap);
        renderer.render(&painter);  // 渲染 SVG
        iconLabel->setPixmap(pixmap);
        iconLabel->setFixedSize(pixmap.size());  // 设置 QLabel 的大小
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setGeometry((frameWidth - pixmap.width()) / 2, 50, pixmap.width(), pixmap.height());
        iconLabel->show();

        // ========== 设置 name 标签 ==========
        QLabel *nameLabel = new QLabel(softwareName[i], frame);
        nameLabel->setAlignment(Qt::AlignCenter);
        nameLabel->setGeometry(0, 150, frameWidth, 30);
        nameLabel->setFont(QFont("Arial", 15, QFont::Bold));
        nameLabel->setStyleSheet("color: white; background: transparent; border: none;");
        QLabel *nameLabel2 = new QLabel(softwareName[i], frame);
        nameLabel2->setAlignment(Qt::AlignCenter);
        nameLabel2->setGeometry(0, 170, frameWidth, 30);
        nameLabel2->setFont(QFont("Arial", 10, QFont::Bold));
        nameLabel2->setStyleSheet("color: white; background: transparent; border: none;");

        // ========== 设置按钮 ==========
        QPushButton *openButton = new QPushButton("进入系统", frame);
        openButton->setGeometry((frameWidth - 80) / 2, 210, 80, 30);
        openButton->setStyleSheet(
            "QPushButton {"
            "   color: white;"
            "   background: transparent;"
            "   border: 2px solid white;"  // 设置边框颜色
            "   border-radius: 10px;"  // 设置圆角，越大越圆
            "   padding: 5px 10px;"  // 设置内边距
            "}"
            "QPushButton:hover {"
            "   background-color: rgba(255, 255, 255, 0.2);"  // 鼠标悬停时的背景色
            "}"
            "QPushButton:pressed {"
            "   background-color: rgba(255, 255, 255, 0.3);"  // 鼠标按下时的背景色
            "   padding-left: 8px; padding-top: 8px;"  // 点击时按钮向下移动的效果
            "}"
            );
        connect(openButton, &QPushButton::clicked, this, [=](){
            QProcess::startDetached(softwareURL[i]);
        });
        frame->installEventFilter(this);

        layout->addWidget(frame);
    }
    scrollWidget->setLayout(layout);
    scrollArea->setWidget(scrollWidget);
    scrollWidget->setStyleSheet("background: transparent;");
    scrollArea->setWidgetResizable(true);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(leftButton);
    hLayout->addWidget(scrollArea);
    hLayout->addWidget(rightButton);

    mainLayout->addLayout(hLayout);
    setLayout(mainLayout);
}

// ========== 捕获系统描述框 ==========
bool StartSoftwareWidget::eventFilter(QObject *watched, QEvent *event)
{

    if (event->type() == QEvent::Enter) {
        QFrame *frame = qobject_cast<QFrame *>(watched);
        if (frame) {
            QLabel *backgroundLabel = frame->findChild<QLabel *>();
            if (backgroundLabel) {
                QPixmap mouseOverPixmap(":/images/u8_mouseOver.jpg");
                backgroundLabel->setPixmap(mouseOverPixmap.scaled(backgroundLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }
        }
    } else if (event->type() == QEvent::Leave) {
        QFrame *frame = qobject_cast<QFrame *>(watched);
        if (frame) {
            QLabel *backgroundLabel = frame->findChild<QLabel *>();
            if (backgroundLabel) {
                QPixmap originalPixmap(":/images/u8.jpg");
                backgroundLabel->setPixmap(originalPixmap.scaled(backgroundLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}


// ========== 向左滚动 ==========
void StartSoftwareWidget::scrollLeft()
{
    int remainingFrames = currentIndex;
    if (remainingFrames >= 4) {
        currentIndex -= 4;
    } else {
        currentIndex = 0;
    }
    int targetPosition = currentIndex * (frameWidth + 35);
    smoothScrollTo(targetPosition);
}

// ========== 向右滚动 ==========
void StartSoftwareWidget::scrollRight()
{
    int remainingFrames = totalFrames - visibleFrames - currentIndex;
    if (remainingFrames >= 4) {
        currentIndex += 4;
    } else {
        currentIndex = totalFrames - visibleFrames;
    }
    int targetPosition = currentIndex * (frameWidth + 35);
    smoothScrollTo(targetPosition);
}

// ========== 创建动画 ==========
void StartSoftwareWidget::smoothScrollTo(int targetPosition)
{
    QPropertyAnimation *animation = new QPropertyAnimation(scrollArea->horizontalScrollBar(), "value");
    animation->setDuration(400);
    animation->setStartValue(scrollArea->horizontalScrollBar()->value());
    animation->setEndValue(targetPosition);
    animation->setEasingCurve(QEasingCurve::InOutQuad);  // 设置缓动曲线，使动画效果更加平滑
    animation->start(QAbstractAnimation::DeleteWhenStopped);  // 启动动画，动画结束时自动删除
}



StartSoftwareWidget::~StartSoftwareWidget()
{
    delete ui;
}
