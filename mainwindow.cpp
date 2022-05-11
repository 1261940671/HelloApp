#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456");
    bool ok = db.open();
    if(ok)
    {
        QMessageBox::information(this, "info", "success");
    }
    else
    {
        QMessageBox::information(this, "info", "open failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

