#-------------------------------------------------
#
# Project created by QtCreator 2018-10-11T16:46:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

TARGET = v-mysql
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    openhostdialog.cpp \
    mainpanel.cpp

HEADERS += \
        mainwindow.hpp \
    openhostdialog.hpp \
    global_data.hpp \
    mainpanel.hpp

FORMS += \
        mainwindow.ui \
    openhostdialog.ui \
    mainpanel.ui

DISTFILES += \
    .gitignore

RESOURCES += \
    resource.qrc

DESTDIR = ../bin


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -lconnection
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -lconnection
else:unix: LIBS += -L$$PWD/lib/ -lconnection

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -lopen_workspace
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -lopen_workspace
else:unix: LIBS += -L$$PWD/lib/ -lopen_workspace

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -lsave_workspace
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -lsave_workspace
else:unix: LIBS += -L$$PWD/lib/ -lsave_workspace

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
