#ifndef QMYSQLSERVER_H
#define QMYSQLSERVER_H
#include <QSqlDatabase>
#include <QSqlQuery>

class QMySQLServer
{
private:
    QMySQLServer();
    static QMySQLServer* instance;
    QSqlDatabase db;
    QSqlQuery query;
public:
    static QMySQLServer* getInstance(){return instance;}
    bool open();
    void close();
    bool operate(QString);
    bool getNext();
    QVariant getValue(QString column){return query.value(column);}
};

#endif // QMYSQLSERVER_H
