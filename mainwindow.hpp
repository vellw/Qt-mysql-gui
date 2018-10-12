#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
    class MainWindow;
    }
class QPushButton;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_add_new_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton * ptr_addNew;    // 添加新的数据库连接
    QTabBar * ptr_workspace_tabbar;   // 标签栏，用于多个数据库连接的切换
    QMenuBar * ptr_workspace_menubar; // 菜单栏，用于连接数据库后的工作菜单
    QToolBar * ptr_worspace_toolbar;  // 工具栏，用于数据库工作区的工具条
};

#endif // MAINWINDOW_HPP
