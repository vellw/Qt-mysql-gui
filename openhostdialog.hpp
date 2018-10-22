#ifndef OPENHOSTDIALOG_HPP
#define OPENHOSTDIALOG_HPP

#include <QDialog>

namespace Ui {
    class OpenHostDialog;
    }
class MainWindow;
class Connection;
class OpenHostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenHostDialog(QWidget *parent = nullptr);
    ~OpenHostDialog();

private slots:
    void on_connect_db_clicked();

    void on_connect_cancle_clicked();
signals:
    void set_database_params(const QString &host,const QString &user,const QString &password,const QString &port,const QString &database_name);
private:
    Ui::OpenHostDialog *ui;
    MainWindow * mainwindow;
};

#endif // OPENHOSTDIALOG_HPP
