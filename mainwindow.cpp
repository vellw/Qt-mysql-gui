#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QPushButton>
#include "openhostdialog.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("mysql gui tool"));
    ptr_addNew = (QPushButton*)ui->add_new;
    if(ptr_addNew)
    {
        ptr_addNew->setText(tr(""));
        ptr_addNew->setIcon(QIcon(":/png/resource/icon/add0.png"));
    }
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

void MainWindow::on_add_new_clicked()
{
    OpenHostDialog  * opendlg =  new OpenHostDialog(this);
    opendlg->show();
}
