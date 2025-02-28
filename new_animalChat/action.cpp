#include "action.h"
#include "ui_action.h"

Action::Action(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Action)
{
    ui->setupUi(this);

    ServerConnect::instance();
    ServerConnect::instance()->initConnect();
    //serverConnect = new ServerConnect();

    //connect_Mysql();

    qDebug() << "ServerConnect::instance()->initConnect();";

    stackedWidget = new QStackedWidget(this);

    loginWidget = new LoginWidget();
    registerWidget = new RegisterWidget();
    //mainWidget = new MainWidget();

    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(registerWidget);

    stackedWidget->setCurrentWidget(loginWidget);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    setLayout(layout);
    this->adjustSize();
    qDebug() << "this->adjustSize(); ";
    //接收信号，跳转界面
    connect(loginWidget, &LoginWidget::registerButtonClicked, this, &Action::showRegisterWidget);
    connect(registerWidget, &RegisterWidget::backButtonClicked, this, &Action::showLoginWidget);

    //接收信号，发送信息
    connect(loginWidget, &LoginWidget::loginButtonClicked, this, &Action::loginConnect);
    connect(registerWidget, &RegisterWidget::registerButtonClicked, this, &Action::registerConnect);

    //接收注册成功信号，显示提示，并点击按钮返回登录界面
    connect(ServerConnect::instance(), &ServerConnect::registerSucess, this, &Action::showRegisterSuccess);

}

void Action::showLoginWidget()
{
    this->stackedWidget->setCurrentWidget(loginWidget);
}
void Action::showRegisterWidget()
{
    this->stackedWidget->setCurrentWidget(registerWidget);
}

void Action::showErrorMessage(QString message)
{
    QMessageBox::information(this, "错误提示", message);
}

void Action::loginConnect(QString id, QString password)
{
    QJsonObject json;
    json["type"] = "login";
    json["user_id"] = id;
    json["user_password"] = password;
    QJsonDocument doc(json);

    //发送一个 发送数据信号
    ServerConnect::instance()->sendData(doc.toJson()+ "\n");

}

void Action::registerConnect(QString phone, QString name, QString password)
{
    QJsonObject json;
    json["type"] = "register";
    json["user_phone"] = phone;
    json["user_name"] = name;
    json["user_password"] = password;
    QJsonDocument doc(json);
    ServerConnect::instance()->sendData(doc.toJson()+ "\n");
}
void Action::showRegisterSuccess(QString id)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("注册成功");
    msgBox.setText("账号为：" + id + "，请保存账号！");
    QPushButton *okButton = msgBox.addButton(QMessageBox::Ok);
    okButton->setText("确定");
    msgBox.exec();
    if (msgBox.clickedButton() == okButton) {
        showLoginWidget();
    }
}

void Action::connect_Mysql()
{
    mydb = QSqlDatabase::addDatabase("QODBC");
    mydb.setHostName("localhost");
    mydb.setDatabaseName("animalchat");

    mydb.setUserName("root");
    mydb.setPassword("xy20010515");
    qDebug() << "Available drivers: " << QSqlDatabase::drivers();

    if(mydb.open())
    {
        QMessageBox::information(this, "连接提示", "连接成功");
    }
    else
    {
        QMessageBox::warning(this, "连接提示", "连接失败");
    }
}

Action::~Action()
{
    delete ui;
}
