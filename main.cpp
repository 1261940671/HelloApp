#include "mainwindow.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginWindow login;
    login.show();
//    w.show();

    QObject::connect(&login,SIGNAL(showmain()),&w,SLOT(receiveLogin()));
    return a.exec();
}
