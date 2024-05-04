QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    doctor.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    nurse.cpp \
    patient.cpp \
    register.cpp \
    requestappoint.cpp

HEADERS += \
    chat.h \
    doctor.h \
    login.h \
    mainwindow.h \
    nurse.h \
    patient.h \
    register.h \
    requestappoint.h

FORMS += \
    chat.ui \
    doctor.ui \
    login.ui \
    mainwindow.ui \
    nurse.ui \
    patient.ui \
    register.ui \
    requestappoint.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    files.qrc
