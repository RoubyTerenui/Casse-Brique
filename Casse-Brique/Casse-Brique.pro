# configuration Qt
QT       += core gui opengl widgets
TEMPLATE  = app

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}

# nom de l'exe genere
TARGET 	  = CasseBrique

# fichiers sources/headers
SOURCES	+= main.cpp myglwidget.cpp \
    ball.cpp \
    square.cpp \
    palette.cpp \
    player.cpp \
    gamemanager.cpp
HEADERS += myglwidget.h \
    ball.h \
    square.h \
    palette.h \
    player.h \
    gamemanager.h

RESOURCES += \
    textures.qrc

DISTFILES += \
    Images/Background 2.jpg

FORMS +=
