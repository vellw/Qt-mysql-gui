#include "connection.hpp"
#include <QDateTime>
#include <QException>
#include <QDebug>


Connection::Connection(const QString &host,const QString &user,const QString &password,const QString &port, const QString &database_name)
    :host_name(host),host_user(user),host_password(password),host_port(port),select_database(database_name)
{}

bool Connection::open()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL",QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss"));
    m_db.setHostName(host_name);
    m_db.setUserName(host_user);
    m_db.setPort(host_port.toInt());
    m_db.setPassword(host_password);
    m_db.setDatabaseName(select_database);
    bool is_open_ok = m_db.open();
    return is_open_ok;
}

bool Connection::close()
{
    if(m_db.isValid())
    {
        if(m_db.isOpen())
        {
            try
            {
                m_db.close();
            }
            catch(QException e)
            {
                qDebug() << e.what() << endl;
                return false;
            }

            return true;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

void Connection::set_hostName(const QString &host_name)
{
    this->host_name = host_name;
    // ...
}

void Connection::set_hostPassword(const QString &host_password)
{
    this->host_password = host_password;
    // ...
}

void Connection::set_hostPort(const QString &host_port)
{
    this->host_port = host_port;
    // ...
}

void Connection::set_selectDatabase(const QString &select_database)
{
    this->select_database = select_database;
    // ...
}

void Connection::set_hostUser(const QString &host_user)
{
    this->host_user = host_user;
    // ...
}

QSqlDatabase Connection::get_db_obj()
{
    return m_db;
}
