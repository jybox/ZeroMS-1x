#ifndef CLIENTCOREEX_H
#define CLIENTCOREEX_H

#include <QMap>
#include "const.h"
#include "oclientcore.h"
#include "chatwidget.h"
class QApplication;
class Login;
class MainWidget;

class OClientCoreEx:public OClientCore
{
    Q_OBJECT
    //该类用意就在连接GUI与ClientCore，为方便GUI存取数据，全部成员公有
public:
    //重写基类的函数
    OClientCoreEx();
    ~OClientCoreEx();
    void init();

    void msgLoginOk(QByteArray *data,unsigned int time);
    void Error(OClientCore::ErrorType e,QString msg,QAbstractSocket::SocketError s);

    Login *login;
    MainWidget *mainwidget;
    //已经打开的聊天窗口列表
    QMap<QString,ChatWidget*> widgets;
public slots:
    void cbTimeChange(unsigned int time);
};

#endif // CLIENTCOREEX_H
