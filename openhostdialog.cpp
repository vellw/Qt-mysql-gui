#include "openhostdialog.hpp"
#include "ui_openhostdialog.h"

OpenHostDialog::OpenHostDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenHostDialog)
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

}

void OpenHostDialog::on_connect_cancle_clicked()
{
    close();
}
