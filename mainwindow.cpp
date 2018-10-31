#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QPushButton>
#include "openhostdialog.hpp"
#include <QTabBar>
#include <QToolBar>
#include <QMessageBox>
#include <QSqlError>
#include <QTreeView>
#include <QTabWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>
#include <QSqlQuery>
#include <exception>
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("mysql gui tool"));
    ptr_addNew = dynamic_cast<QPushButton *> (ui->add_new);
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
    ptr_workspace_workpanel = new mainpanel(this);
    ptr_workspace_workpanel->setHidden(true);
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
    if(ptr_save_workpanel != nullptr) delete  ptr_save_workpanel;

    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if(ptr_workspace_workpanel)
    {
        ptr_workspace_workpanel->resize(size());
    }
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

        // 1.告诉mainwindow替换菜单
        switch_workspace_menuBar();
        // 2.告诉mainwindow替换工具条

        // 3.告诉mainwindow替换工作区
        switch_workspace_workpanel();
    }
    else
    {
        QMessageBox::critical(this,tr("错误"),tr("连接失败,失败原因：%1").arg(ptr_conn->get_db_obj().lastError().text()),QMessageBox::Close);
    }
}

void MainWindow::switch_workspace_tabBar()
{

}

/** **********************
  * 切换工作菜单
  *
  *
*/
void MainWindow::switch_workspace_menuBar()
{
    ptr_save_menubar = ui->menuBar;
    ui->menuBar->setHidden(true);
    /////////////////////////////////////////////////////////////////////
    QMenu * ptr_file_menu = new QMenu(this);
    ptr_file_menu->setTitle(tr("文件(&F)"));
    ////
    QAction * ptr_file_menu_item_newModel = new QAction(ptr_file_menu);
    ptr_file_menu_item_newModel->setText(tr("新建模型"));
    ptr_file_menu->addAction(ptr_file_menu_item_newModel);
    ////
    QAction * ptr_file_menu_item_newTab = new QAction(ptr_file_menu);
    ptr_file_menu_item_newTab->setText(tr("新建标签"));
    ptr_file_menu->addAction(ptr_file_menu_item_newTab);
    ////
    QAction * ptr_file_menu_item_openModel = new QAction(ptr_file_menu);
    ptr_file_menu_item_openModel->setText(tr("打开模型"));
    ptr_file_menu->addAction(ptr_file_menu_item_openModel);
    ////
    QAction * ptr_file_menu_item_openSql = new QAction(ptr_file_menu);
    ptr_file_menu_item_openSql->setText(tr("打开脚本"));
    ptr_file_menu->addAction(ptr_file_menu_item_openSql);
    ////
    QAction * ptr_file_menu_item_close_con = new QAction(ptr_file_menu);
    ptr_file_menu_item_openSql->setText(tr("关闭连接"));
    ptr_file_menu->addAction(ptr_file_menu_item_close_con);
    ////
    QMenu * ptr_edit_menu = new QMenu(this);
    ptr_edit_menu->setTitle(tr("编辑(&E)"));
    
    ptr_edit_menu->setProperty("menu",true);
    ////
    QMenu * ptr_view_menu = new QMenu(this);
    ptr_view_menu->setTitle(tr("查看(&V)"));
    
    ptr_view_menu->setProperty("menu",true);
    ////
    QMenu * ptr_query_menu = new QMenu(this);
    ptr_query_menu->setTitle(tr("查询(&Q)"));
    

    ////
    QMenu * ptr_database_menu = new QMenu(this);
    ptr_database_menu->setTitle(tr("数据库(&D)"));
    ////
    QMenu * ptr_server_menu = new QMenu(this);
    ptr_server_menu->setTitle(tr("服务器(&S)"));
    ////
    QMenu * ptr_tool_menu = new QMenu(this);
    ptr_tool_menu->setTitle(tr("工具(&T)"));
    ////
    ptr_workspace_menubar->addMenu(ptr_file_menu);
    ptr_workspace_menubar->addMenu(ptr_edit_menu);
    ptr_workspace_menubar->addMenu(ptr_view_menu);
    ptr_workspace_menubar->addMenu(ptr_query_menu);
    ptr_workspace_menubar->addMenu(ptr_database_menu);
    ptr_workspace_menubar->addMenu(ptr_server_menu);
    ptr_workspace_menubar->addMenu(ptr_server_menu);
    ptr_workspace_menubar->setGeometry(0,0,this->width(),30); // 设置菜单栏位置
    ui->menuBar = ptr_workspace_menubar;
    setMenuBar(ptr_workspace_menubar);
    ui->menuBar->show();
}

/***
 *  切换工作区工具条
 *
 *
*/
void MainWindow::switch_workspace_toolBar()
{

}

/********
 * 切换工作区面板
 *
*/
void MainWindow::switch_workspace_workpanel()
{
    ptr_save_workpanel = ui->centralWidget;
    ptr_workspace_workpanel->setSizeIncrement(ptr_save_workpanel->size());
    ui->centralWidget->setHidden(true);
    ptr_workspace_workpanel->setObjectName(QStringLiteral("centralWidget_workspace"));
    ////----构造workpanel组件>>
    QTreeView * ptr_table_list = ptr_workspace_workpanel->get_table_list();
    ptr_table_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(ptr_conn->get_db_obj().isValid() &&
            ptr_conn->get_db_obj().isOpen() &&
            !ptr_conn->get_db_obj().isOpenError())
    {
        QStandardItemModel * ptr_item_model = ptr_workspace_workpanel->get_item_model();

        QString cmd = "show tables;";
        QSqlQuery query(ptr_conn->get_db_obj()); // 这里必须写，否则始终无法查询且报告 数据库没有打开
        try
        {
            query.exec(cmd);
            while (query.next())
            {
                QStandardItem * ptr_item = new QStandardItem(query.value(0).toString());

                 ptr_item_model->appendRow(ptr_item);
            }
        }
        catch (std::exception e)
        {
            qDebug() << ptr_conn->get_db_obj().lastError();
        }
    }
    else
    {
        qDebug() << ptr_conn->get_db_obj().lastError();
    }
    ////----end<<
    ui->centralWidget = ptr_workspace_workpanel;
    setCentralWidget(ptr_workspace_workpanel);
    ui->centralWidget->show();
}
