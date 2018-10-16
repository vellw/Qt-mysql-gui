#include "openhostdialog.hpp"
#include "ui_openhostdialog.h"
#include "connection/connection.hpp"
#include "connection/connection_global.hpp"
#include <QMessageBox>
#include "mainwindow.hpp"
#include <QSqlError>

OpenHostDialog::OpenHostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenHostDialog),
    mainwindow(dynamic_cast < MainWindow* > (parent))
{
    ui->setupUi(this);
    setWindowTitle(tr("添加数据库"));
}

OpenHostDialog::~OpenHostDialog()
{
    delete ui;
}

void OpenHostDialog::on_connect_db_clicked()
{
    QString host_name = ui->edit_hostName->text();
    QString host_port = ui->edit_hostPort->text();
    QString host_password = ui->edit_hostPassword->text();
    QString database_name = ui->edit_database->text();
    QString user_name = ui->edit_username->text();

    if(host_name.isEmpty() || host_name.isNull())
    {
        QMessageBox::warning(this,tr("警告"),tr("主机名不能为空"),QMessageBox::Abort);
        return;
    }

    if(host_port.isEmpty() || host_port.isNull())
    {
        QMessageBox::warning(this,tr("警告"),tr("主机端口不能为空"),QMessageBox::Abort);
        return;
    }

    if(user_name.isEmpty() || user_name.isNull())
    {
        QMessageBox::warning(this,tr("警告"),tr("用户名为空"),QMessageBox::Abort);
        return;
    }

    if(host_password.isEmpty() || host_password.isNull())
    {
        QMessageBox::warning(this,tr("警告"),tr("主机密码为空"),QMessageBox::Abort);
        return;
    }

    if(database_name.isEmpty() || database_name.isNull())
    {
        QMessageBox::warning(this,tr("警告"),tr("数据库名称为空"),QMessageBox::Abort);
        return;
    }

    emit set_database_params(host_name,user_name,host_password,host_port,database_name);
    close();
}

void OpenHostDialog::on_connect_cancle_clicked()
{
    close();
}
