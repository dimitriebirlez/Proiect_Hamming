QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    afisaregrafica.cpp \
    afisarestatut.cpp \
    afisarestatutnou.cpp \
    alegeredate.cpp \
    alegereindicatori.cpp \
    alegeretaskuri.cpp \
    initializare.cpp \
    main.cpp \
    mainwindow.cpp \
    proiectexistent.cpp \
    proiectnou.cpp

HEADERS += \
    afisaregrafica.h \
    afisarestatut.h \
    afisarestatutnou.h \
    alegeredate.h \
    alegereindicatori.h \
    alegeretaskuri.h \
    initializare.h \
    mainwindow.h \
    proiectexistent.h \
    proiectnou.h

FORMS += \
    afisaregrafica.ui \
    afisarestatut.ui \
    afisarestatutnou.ui \
    alegeredate.ui \
    alegereindicatori.ui \
    alegeretaskuri.ui \
    mainwindow.ui \
    proiectexistent.ui \
    proiectnou.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
