#Generated by VisualGDB project wizard. 
#Feel free to modify any flags you want.
#Visit http://visualgdb.com/makefiles for more details.

QT       += core core network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Agro2
TEMPLATE = app

#By default the following file lists are updated automatically by VisualGDB.

SOURCES   += Agro2.cpp HW.cpp NW.cpp
HEADERS   += HW.h NW.h ProjectDef.h
FORMS     += 
RESOURCES += 
LIBS += -L/usr/local/include -lwiringPi

include($$lower($$join(CONFIGNAME,,,.pro)))

QMAKE_CFLAGS 	+= $$COMMONFLAGS
QMAKE_CXXFLAGS 	+= $$COMMONFLAGS
QMAKE_LFLAGS 	+= $$COMMONFLAGS

OBJECTS_DIR = $$DESTDIR
MOC_DIR     = $$DESTDIR
RCC_DIR     = $$DESTDIR
UI_DIR      = $$DESTDIR
