QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Calculator.cpp \
        TelemManager.cpp \
        main.cpp \
        MainWindow.cpp \
        irsdk/irsdk_client.cpp \
        irsdk/irsdk_diskclient.cpp \
        irsdk/irsdk_utils.cpp \
        irsdk/yaml_parser.cpp

HEADERS += \
        Calculator.h \
        MainWindow.h \
        TelemManager.h \
        irsdk/irsdk_client.h \
        irsdk/irsdk_diskclient.h \
        irsdk/yaml_parser.h \
        irsdk/irsdk_defines.h

FORMS += \
        MainWindow.ui

RC_ICONS = icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
