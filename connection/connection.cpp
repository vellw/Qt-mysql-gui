#include "connection.hpp"
#include <QSqlDatabase>

Connection::Connection(QString host, QString password, QString port, QString database_name)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    host_name = host;
    host_password = password;
    host_port = port;
    select_database = database_name;
}

bool Connection::open()
{
    m_db.setHostName(host_name);
    m_db.setPort(host_port);
    m_db.setPassword(host_password);
    m_db.setDatabaseName(select_database);
    bool is_open_ok = m_db.open();
    return is_open_ok;
}
