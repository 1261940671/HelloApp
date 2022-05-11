#include "qmysqlserver.h"
#include <QSqlError>
#include <QDebug>

QMySQLServer* QMySQLServer::instance=new QMySQLServer();

QMySQLServer::QMySQLServer():
    db(QSqlDatabase::addDatabase("QMYSQL")),
    query(QSqlQuery(db))
{
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("test");
}

bool QMySQLServer::open()
{
    bool res=0;
    if(db.open())
    {
        qDebug()<<"数据库打开成功";
        res=1;
    }
    else
    {
        qDebug()<<"数据库打开失败";
        res=0;
    }
    return res;
}

void QMySQLServer::close()
{
    db.close();
}

bool QMySQLServer::operate(QString cmd)
{
    bool res=query.exec(cmd);
    if(!res)
    {
        qDebug()<<query.lastError().text();
    }
    return res;
}

bool QMySQLServer::getNext()
{
    return query.next();
}
