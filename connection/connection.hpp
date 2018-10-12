#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "connection_global.hpp"

class QSqlDatabase;

class CONNECTIONSHARED_EXPORT Connection
{

public:
    Connection(QString host,QString password,QString port,QString database_name);
public:
    bool open();
protected:
    QSqlDatabase m_db;
    QString host_name;
    QString host_password;
    QString host_port;
    QString select_database;
};

#endif // CONNECTION_HPP
