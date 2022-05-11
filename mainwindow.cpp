#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmysqlserver.h"
#include <QStandardItemModel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMySQLServer *db = QMySQLServer::getInstance();
    db->open();
    db->operate("select * from sys_user;");

    QStandardItemModel *model=new QStandardItemModel(this);
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"用户名");
    model->setHeaderData(2,Qt::Horizontal,"密码");

    int row=0;
    while(db->getNext())
    {
        model->setItem(row,0,new QStandardItem(db->getValue("id").toString()));
        model->setItem(row,1,new QStandardItem(db->getValue("username").toString()));
        model->setItem(row,2,new QStandardItem(db->getValue("password").toString()));
        row++;
    }

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveLogin()
{
    this->show();
}
