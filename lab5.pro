QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    stoneedit.cpp

HEADERS += \
    mainwindow.h \
    stoneedit.h

FORMS += \
    mainwindow.ui \
    stoneedit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/../lab4/include
DEPENDPATH  += $$PWD/../lab4/include

LIBS += -L$$PWD/../lab4/build -llab4

win32: LIBS += -L$$PWD/../build-lab4-Desktop_x86_windows_msys_pe_64bit-Debug/debug -llab4

DISTFILES +=
