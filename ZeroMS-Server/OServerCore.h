#ifndef OSERVERCORE_H
#define OSERVERCORE_H

#include <QObject>
#include <QTextStream>
#include <QTcpServer>
#include "../public/OSettings.h"
#include "global.h"
#include "OClient.h"
#include "OProtocolForSC.h"

class OServerCore:public QObject
{
    Q_OBJECT
    friend class OProtocolForSC;
public:
    explicit OServerCore();
    void init();
    void start();
private:
    void log(QString msg);

    QMap<QString,OClient*> cl;
    QTextStream cin;
    QTextStream cout;
    QTcpServer server;
    OSettings config;
    OProtocolForSC protocol;
private slots:
    void Login(OClient::Connect *connect,QString uname,QString pwdHash,bool isMain,bool isForce,bool isShowIp);
    void AskPublicKey(OClient::Connect *connect);
    void onNewConn();
    void onError(OClient::Connect *connect,QString msg,QAbstractSocket::SocketError s);
};

#endif // OSERVERCORE_H