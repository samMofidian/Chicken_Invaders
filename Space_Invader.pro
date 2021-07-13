QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Chicken.cpp \
    Controller.cpp \
    Egg.cpp \
    ExitButton.cpp \
    GameOverImage.cpp \
    Gift.cpp \
    Hen.cpp \
    Home.cpp \
    Level1Button.cpp \
    Level2button.cpp \
    Level3Button.cpp \
    Level4Button.cpp \
    Level5Button.cpp \
    Level6Button.cpp \
    Life.cpp \
    Menu.cpp \
    Next.cpp \
    Replay.cpp \
    Score.cpp \
    SpaceCraft.cpp \
    SuperHen.cpp \
    View.cpp \
    WinImage.cpp \
    main.cpp

HEADERS += \
    Bullet.h \
    Chicken.h \
    Controller.h \
    Egg.h \
    ExitButton.h \
    GameOverImage.h \
    Gift.h \
    Hen.h \
    Home.h \
    Level1Button.h \
    Level2button.h \
    Level3Button.h \
    Level4Button.h \
    Level5Button.h \
    Level6Button.h \
    Life.h \
    Menu.h \
    Next.h \
    Replay.h \
    Score.h \
    SpaceCraft.h \
    SuperHen.h \
    View.h \
    WinImage.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rs.qrc
