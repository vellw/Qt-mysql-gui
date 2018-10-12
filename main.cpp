#include "mainwindow.hpp"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap( ":/png/splash/img/mysqlgui-blue.png" );

    QSplashScreen splash( pixmap );
    splash.show();

    a.processEvents();

    MainWindow w;
    w.show();

    splash.finish(&w);
    return a.exec();
}
