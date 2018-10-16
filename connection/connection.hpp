#ifndef CONNECTION_HPP
#define CONNECTION_HPP
#include <QtSql/QSqlDatabase>
#include <QString>

#include "connection_global.hpp"


class CONNECTIONSHARED_EXPORT Connection
{

public:
    explicit Connection() = default;
    Connection(const QString &host,const QString &user,const QString &password,const QString &port,const QString &database_name);
public:
    bool open();
    bool close();
    void set_hostName(const QString &host_name);
    void set_hostUser(const QString &host_user);
    void set_hostPassword(const QString &host_password);
    void set_hostPort(const QString & host_port);
    void set_selectDatabase(const QString & select_database);
    QSqlDatabase get_db_obj();
protected:
    QSqlDatabase m_db;
    QString host_name;
    QString host_user;
    QString host_password;
    QString host_port;
    QString select_database;
};

#endif // CONNECTION_HPP
