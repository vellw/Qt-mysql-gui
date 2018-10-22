#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "connection/connection.hpp"
#include "connection/connection_global.hpp"
#include "mainpanel.hpp"

namespace Ui {
    class MainWindow;
    }
class QPushButton;
class OpenHostDialog;
class QResizeEvent;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent* event);

private slots:
    void on_add_new_clicked();

public slots:
    void set_database_conn_obj(const QString &host,const QString &user,const QString &password,const QString &port,const QString &database_name);  // 设置数据库连接的对象
    void switch_workspace_tabBar();           // 切换工作区标签
    void switch_workspace_menuBar();          // 切换工作区菜单
    void switch_workspace_toolBar();          // 切换工作区工具
    void switch_workspace_workpanel();        // 切换工作面板
public:
    Connection * ptr_conn;        // 数据库连接
private:
    Ui::MainWindow *ui;
    QPushButton * ptr_addNew;    // 添加新的数据库连接
    QTabBar * ptr_workspace_tabbar;   // 标签栏，用于多个数据库连接的切换
    QMenuBar * ptr_workspace_menubar; // 菜单栏，用于连接数据库后的工作菜单
    QToolBar * ptr_worspace_toolbar;  // 工具栏，用于数据库工作区的工具条
    mainpanel * ptr_workspace_workpanel; // 工作区面板，用于显示和操作数据库相关信息
    QMenuBar * ptr_save_menubar;      // 保存旧的菜单栏
    QWidget * ptr_save_workpanel;        // 保存旧的初始化工作面板
};

#endif // MAINWINDOW_HPP
