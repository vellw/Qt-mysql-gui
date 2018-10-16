#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "connection/connection.hpp"
#include "connection/connection_global.hpp"

namespace Ui {
    class MainWindow;
    }
class QPushButton;
class OpenHostDialog;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_add_new_clicked();

public slots:
    void set_database_conn_obj(const QString &host,const QString &user,const QString &password,const QString &port,const QString &database_name);  // 设置数据库连接的对象
    void switch_workspace_tabBar();           // 切换工作区标签
    void switch_workspace_menuBar();          // 切换工作区菜单
    void switch_workspace_toolBar();          // 切换工作区工具
public:
    Connection * ptr_conn;        // 数据库连接
private:
    Ui::MainWindow *ui;
    QPushButton * ptr_addNew;    // 添加新的数据库连接
    QTabBar * ptr_workspace_tabbar;   // 标签栏，用于多个数据库连接的切换
    QMenuBar * ptr_workspace_menubar; // 菜单栏，用于连接数据库后的工作菜单
    QToolBar * ptr_worspace_toolbar;  // 工具栏，用于数据库工作区的工具条
};

#endif // MAINWINDOW_HPP
