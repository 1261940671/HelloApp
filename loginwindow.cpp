#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QKeyEvent>
#include <QMessageBox>
#include "qmysqlserver.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_ok_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    if(username=="" || password=="")
    {
        QMessageBox::warning(this,tr("提示"),tr("用户名或密码不能为空"),QMessageBox::Yes);
        ui->lineEdit_username->clear();
        ui->lineEdit_username->setFocus();
        return;
    }

    QMySQLServer *db=QMySQLServer::getInstance();
    db->open();
    db->operate("select * from sys_user where username='"+username+"' and password='"+password+"';");
    if(db->getNext())
    {
        qDebug()<<"id="<<db->getValue("id").toInt();
        qDebug()<<"username="<<db->getValue("username").toString();
        qDebug()<<"password="<<db->getValue("password").toString();
        this->hide();
        emit showmain();
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("登录失败，用户名或密码错误"),QMessageBox::Yes);
    }

    db->close();
}

void LoginWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter)
    {
        emit ui->pushButton_ok->click();
    }
}
