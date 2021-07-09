QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Chicken1.cpp \
    Controller.cpp \
    ExitButton.cpp \
    Gift.cpp \
    Level1Button.cpp \
    Level2button.cpp \
    Level3Button.cpp \
    Level4Button.cpp \
    Level5Button.cpp \
    Level6Button.cpp \
    Menu.cpp \
    Score.cpp \
    SpaceCraft.cpp \
    View.cpp \
    main.cpp

HEADERS += \
    Bullet.h \
    Chicken1.h \
    Controller.h \
    ExitButton.h \
    Gift.h \
    Level1Button.h \
    Level2button.h \
    Level3Button.h \
    Level4Button.h \
    Level5Button.h \
    Level6Button.h \
    Menu.h \
    Score.h \
    SpaceCraft.h \
    View.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rs.qrc
