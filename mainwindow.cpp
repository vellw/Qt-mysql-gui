#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QPushButton>
#include "openhostdialog.hpp"
#include <QTabBar>
#include <QToolBar>
#include <QMessageBox>
#include <QSqlError>

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
    ////////////////////////////////////////////////////////////////////////
    ptr_conn = new Connection();
    /////////////////////////////////////////////////////////////////////////
    ptr_workspace_menubar = new QMenuBar(this);
    ptr_workspace_menubar->setHidden(true);
    ptr_workspace_tabbar = new QTabBar(this);
    ptr_workspace_tabbar->setHidden(true);
    ptr_worspace_toolbar = new QToolBar(this);
    ptr_worspace_toolbar->setHidden(true);
    //////////////////////////////////////////////////////////////////////////
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        QCoreApplication::processEvents();
    } while (n.secsTo(now)<=5);//5为需要延时的秒数
}

MainWindow::~MainWindow()
{
    if(ptr_conn != nullptr)
    {
        ptr_conn->close();
        delete ptr_conn;
    }

    if(ptr_addNew != nullptr) delete ptr_addNew;
    if(ptr_workspace_tabbar != nullptr) delete ptr_workspace_tabbar;
    if(ptr_workspace_menubar != nullptr) delete ptr_workspace_menubar;
    if(ptr_worspace_toolbar != nullptr) delete ptr_worspace_toolbar;

    delete ui;
}

void MainWindow::on_add_new_clicked()
{
    OpenHostDialog  * opendlg =  new OpenHostDialog(this);
    opendlg->show();
    connect(opendlg,
            SIGNAL(set_database_params(QString,QString,QString,QString,QString)),
            this,
            SLOT(set_database_conn_obj(QString,QString,QString,QString,QString)));
}

void MainWindow::set_database_conn_obj(const QString &host, const QString &user, const QString &password, const QString &port, const QString &database_name)
{
    ptr_conn->set_hostName(host);
    ptr_conn->set_hostUser(user);
    ptr_conn->set_hostPort(port);
    ptr_conn->set_hostPassword(password);
    ptr_conn->set_selectDatabase(database_name);

    if(ptr_conn->open())
    {
        QMessageBox::information(this,tr("信息"),tr("连接成功"),QMessageBox::Ok);
        // --打开新的数据库工作区
        // 0.告诉mainwindow添加标签
        // 1.告诉mainwindow替换菜单

        // 2.告诉mainwindow替换工具条
    }
    else
    {
        QMessageBox::critical(this,tr("错误"),tr("连接失败,失败原因：%1").arg(ptr_conn->get_db_obj().lastError().text()),QMessageBox::Close);
    }
}

void MainWindow::switch_workspace_tabBar()
{

}

void MainWindow::switch_workspace_menuBar()
{
    ui->menuBar->setHidden(true);
    ptr_workspace_menubar->show();
}

void MainWindow::switch_workspace_toolBar()
{

}
