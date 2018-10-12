#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        QCoreApplication::processEvents();
    } while (n.secsTo(now)<=5);//5为需要延时的秒数
}

MainWindow::~MainWindow()
{
    delete ui;
}
