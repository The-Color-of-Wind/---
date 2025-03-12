#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    setWindowTitle("天控首页");

    //初始化参数列表
    initVariables();

    // 初始化界面 上
    initTop();

    // 初始化界面 下
    initBottom();

    // 初始化界面 左
    initLeft();

}

// 初始化背景
void MainWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    // 设置父控件的背景
    setAutoFillBackground(true);  // 使得控件能够填充背景
    QPalette palette;
    QPixmap background(":/images/u0_state0.jpg");
    QPixmap scaledBackground = background.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    palette.setBrush(QPalette::Window, QBrush(scaledBackground));
    setPalette(palette);
}

void MainWidget::initVariables()
{
    // ====== 底部功能按钮 ======
    bottomFunctionButton.append("系统通知");
    bottomFunctionButton.append("数据设置");
    bottomFunctionButton.append("系统设置");
    bottomFunctionButton.append("锁定状态");
    bottomFunctionButton.append("退出登录");

    // ====== 左侧按钮 ======
    changePushButton.append(new QPushButton("界面1"));
    changeButtonIcon.append(":/images/a3.jpg");

    changePushButton.append(new QPushButton("界面2"));
    changeButtonIcon.append(":/images/a3.jpg");

    changePushButton.append(new QPushButton("界面3"));
    changeButtonIcon.append(":/images/a3.jpg");

    changePushButton.append(new QPushButton("界面4"));
    changeButtonIcon.append(":/images/a3.jpg");

    // ====== 初始化界面 =======
    stackedWidget = new QStackedWidget(ui->showWidget);
    QVBoxLayout *layout = new QVBoxLayout(ui->showWidget);  // 居中展示
    layout->addStretch();
    layout->addWidget(stackedWidget);
    layout->addStretch();
    ui->showWidget->setLayout(layout);

    // 界面初始化
    startSoftwareWidget = new StartSoftwareWidget();
    widget3 = new Widget3();
    //界面入栈
    stackedWidget->addWidget(startSoftwareWidget);
    stackedWidget->addWidget(widget3);
    // 多态：存储子类界面的容器
    changeWidget.append(startSoftwareWidget);
    changeWidget.append(widget3);

    // 设置当前界面
    stackedWidget->setCurrentWidget(startSoftwareWidget);
}

void MainWidget::initTop()
{
/*
    // ========== 加载动态图，暂未成功 ==========
    QLabel *label = new QLabel(this);
    QMovie *movie = new QMovie(":/images/u4.gif");
    label->setMovie(movie);
    movie->start();
    label->show();
*/
    // ========== 显示u2 ==========
    u2ImageLabel = new QLabel(this);
    QPixmap u2Image(":/images/u2.png");
    QPixmap scaledU2Image = u2Image.scaled(width(), height()/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    u2ImageLabel->setPixmap(scaledU2Image);
    u2ImageLabel->setGeometry(0, 0, scaledU2Image.width(), scaledU2Image.height());

    // ========== 显示文本 ==========
    ui->titlelabel_1->setFont(QFont("Arial", 20, QFont::Bold));
    ui->titlelabel_1->setStyleSheet("color: white;");
    ui->titlelabel_2->setFont(QFont("Arial", 10, QFont::Bold));
    ui->titlelabel_2->setStyleSheet("color: white;");

}

void MainWidget::initBottom()
{
    QPushButton *buttons[5];
    QLabel *labels[5];

    QHBoxLayout *mainLayout = new QHBoxLayout(ui->functionFrame);
    mainLayout->setSpacing(10);
    for (int i = 0; i < 5; ++i) {
        buttons[i] = new QPushButton(ui->functionFrame);
        buttons[i]->setFixedSize(60, 60);
        buttons[i]->setStyleSheet(R"(
            QPushButton {
                border: none;
                background: transparent;
                color: white;
                image: url(:/images/u51.jpg);
                text-align: center;
            }
            QPushButton:hover {
                image: url(:/images/u51_mouseOver.jpg);
            }
        )");
        QFrame *frameRightButton = new QFrame(buttons[i]);
        frameRightButton->setGeometry(25, 22, 10, 15);
        frameRightButton->setStyleSheet("border: 2px solid rgba(255, 255, 255, 1);");
        frameRightButton->show();

        labels[i] = new QLabel(bottomFunctionButton[i], ui->functionFrame);
        labels[i]->setAlignment(Qt::AlignCenter);
        labels[i]->setStyleSheet("color: white; font-size: 12px;");

        QVBoxLayout *buttonLayout = new QVBoxLayout();
        buttonLayout->addWidget(buttons[i]);
        buttonLayout->addWidget(labels[i]);
        buttonLayout->setAlignment(Qt::AlignCenter);

        mainLayout->addLayout(buttonLayout);

        // 响应点击事件
        connect(buttons[i], &QPushButton::clicked, this, [=]() {

        });
    }

    // 设置布局
    ui->functionFrame->setLayout(mainLayout);
}

void MainWidget::initLeft()
{
    QFrame *buttonFrame = new QFrame(ui->leftWidget);
    buttonFrame->setStyleSheet("background: transparent;");
    buttonFrame->setFrameShape(QFrame::NoFrame);

    QVBoxLayout *layout = new QVBoxLayout(buttonFrame);
    layout->setSpacing(10);
    layout->setContentsMargins(0, 0, 0, 0);

    for (int i = 0; i < changePushButton.size(); ++i) {
        changePushButton[i]->setFixedSize(100, 50);  // 设置按钮大小
        changePushButton[i]->setStyleSheet(R"(
            QPushButton {
                border: none;
                background: transparent;
                image: url(:/images/u51.jpg);
            }
            QPushButton:hover {
                image: url(:/images/u51_mouseOver.jpg);
            }
            )");
        layout->addWidget(changePushButton[i]);

        connect(changePushButton[i], &QPushButton::clicked, this, [=]() {
            stackedWidget->setCurrentWidget(changeWidget[i]);
        });
    }

    // 3. 设置布局
    ui->leftWidget->setLayout(layout);

}



MainWidget::~MainWidget()
{
    delete ui;
}

