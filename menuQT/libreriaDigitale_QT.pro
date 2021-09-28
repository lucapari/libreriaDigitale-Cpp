QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:RC_ICONS += $$PWD/icon/LibreriaDigitaleIcon.ico

INCLUDEPATH += $$PWD/lib

SOURCES += \
    cercaperiddialog.cpp \
    cercapernomedialog.cpp \
    inseriscinuovarivistadialog.cpp \
    inseriscinuovoaudiodialog.cpp \
    inseriscinuovoaudiolibrodialog.cpp \
    inseriscinuovolibro.cpp \
    main.cpp \
    mainwindow.cpp\
    $$PWD/lib/libreria/*.cpp\
    $$PWD/lib/manager/*.cpp \
    noleggiaarticolodialog.cpp \
    restituisciarticolodialog.cpp \
    rimuoviarticolodialog.cpp \
    visualizzaarticolidialog.cpp

HEADERS += \
    cercaperiddialog.h \
    cercapernomedialog.h \
    inseriscinuovarivistadialog.h \
    inseriscinuovoaudiodialog.h \
    inseriscinuovoaudiolibrodialog.h \
    inseriscinuovolibro.h \
    mainwindow.h \
    noleggiaarticolodialog.h \
    restituisciarticolodialog.h \
    rimuoviarticolodialog.h \
    visualizzaarticolidialog.h

FORMS += \
    cercaperiddialog.ui \
    cercapernomedialog.ui \
    inseriscinuovarivistadialog.ui \
    inseriscinuovoaudiodialog.ui \
    inseriscinuovoaudiolibrodialog.ui \
    inseriscinuovolibro.ui \
    mainwindow.ui \
    noleggiaarticolodialog.ui \
    restituisciarticolodialog.ui \
    rimuoviarticolodialog.ui \
    visualizzaarticolidialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
