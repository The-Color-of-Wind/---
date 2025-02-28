#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H
#include <QWidget>

#include <QMessageBox>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMap>

#include "user.h"
#include "userfriend.h"
#include "userchat.h"
#include "message.h"

class ServerConnect : public QWidget
{
    Q_OBJECT
public:
    static ServerConnect* instance(){
        static ServerConnect serverConnect;
        return &serverConnect;
    }

    QTcpSocket *getSocket() const {return this->socket;}

    void initConnect();
    void sendData(QString data);
    QPixmap loadImageFromBase64(const QString &base64Data);
signals:
    void loginSuccess(User user);
    void registerSucess(QString id);
    void getFriendsSuccess(QMap<QString, UserFriend> userFriendVector);
    void getChatsSuccess(QVector<UserChat> userChatVector);
    void getFriendsUnreadMessagesSuccess(QVector<Message> friendsUnreadMessages);
    void getUserInformation(UserFriend userFriend, bool isFriend);
    void getUserInformationError();
    void accpetFriendSuccess();
    void deleteFriendSuccess(QString userId, QString friendId);

    void sendErrorSignal(QString message);     //显示错误信息
    void receiveMessageSuccess(Message &message);


private slots:
    void onReadyRead();

private:
    ServerConnect() {}  // 私有构造函数，禁止外部实例化
    ServerConnect(const ServerConnect&) = delete;  // 禁止拷贝构造
    ServerConnect& operator=(const ServerConnect&) = delete;  // 禁止赋值

private:
    QTcpSocket *socket;

};

#endif // SERVERCONNECT_H
