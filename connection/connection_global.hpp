#ifndef CONNECTION_GLOBAL_HPP
#define CONNECTION_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(CONNECTION_LIBRARY)
#  define CONNECTIONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CONNECTIONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CONNECTION_GLOBAL_HPP
