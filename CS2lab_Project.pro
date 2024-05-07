QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admindata.cpp \
    chat.cpp \
    doctor.cpp \
    doctorslots.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    nurse.cpp \
    patient.cpp \
    register.cpp \
    requestappoint.cpp

HEADERS += \
    admin.h \
    admindata.h \
    chat.h \
    doctor.h \
    doctorslots.h \
    login.h \
    mainwindow.h \
    nurse.h \
    patient.h \
    register.h \
    requestappoint.h

FORMS += \
    admin.ui \
    admindata.ui \
    chat.ui \
    doctor.ui \
    doctorslots.ui \
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

DISTFILES += \
    3632097.jpg \
    abstract-blur-hospital-clinic-interior.jpg \
    blur-hospital.jpg \
    clipboard-stethoscope.jpg \
    composition-medical-objects-with-copyspace.jpg \
    flat-lay-desk-arrangement-with-copy-space.jpg \
    vintage-grunge-blue-concrete-texture-studio-wall-background-with-vignette.jpg
