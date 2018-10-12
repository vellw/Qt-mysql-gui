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
    QPushButton * ptr_addNew;
};

#endif // MAINWINDOW_HPP
