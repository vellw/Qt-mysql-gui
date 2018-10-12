#ifndef OPENHOSTDIALOG_HPP
#define OPENHOSTDIALOG_HPP

#include <QDialog>

namespace Ui {
    class OpenHostDialog;
    }

class OpenHostDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenHostDialog(QWidget *parent = 0);
    ~OpenHostDialog();

private slots:
    void on_connect_db_clicked();

    void on_connect_cancle_clicked();

private:
    Ui::OpenHostDialog *ui;
};

#endif // OPENHOSTDIALOG_HPP
