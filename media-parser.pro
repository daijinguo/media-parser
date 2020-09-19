QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++17
TEMPLATE = app
TARGET   = media-parser

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/basic/filereader.cc \
    src/ui/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/mp4-display.cc

HEADERS += \
    include/basic/types.hpp \
    include/basic/filereader.hpp \
    src/ui/mainwindow.h \
    src/ui/mp4-display.hpp


FORMS += \
    res/layout/mainwindow.ui

INCLUDEPATH += include/

message("platform information")
macx {
    message("platform MAXC")
    ICON += res/mac-app-icon.icns
}
uinx:!macx {
    message("platform linux or unix")
}
win32{
message("platform window")
# the real exe file
    RC_FILE += res/app-icon.rc
}

# just for edit
OTHER_FILES += \
    res/app-icon.rc \
    res/mac-app-icon.icns



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
