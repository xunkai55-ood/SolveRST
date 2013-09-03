#-------------------------------------------------
#
# Project created by QtCreator 2013-08-27T14:14:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = solveRST
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rststrategy.cpp \
    rst.cpp \
    ImplementationA/SMST/SMST.cpp \
    ImplementationA/SMST/PointsGenerator.cpp \
    ImplementationA/LMST/LMST.cpp \
    ImplementationA/ZMST/ZMST.cpp \
    gendialog.cpp \
    rstviewer.cpp \
    mainrstview.cpp \
    minirstview.cpp \
    apdialog.cpp

HEADERS  += mainwindow.h \
    rst.h \
    ImplementationA/Headers/overlap.h \
    ImplementationA/Headers/data_format.h \
    ImplementationA/LMST/LMST.h \
    ImplementationA/SMST/SMST.h \
    ImplementationA/SMST/PointsGenerator.h \
    ImplementationA/ZMST/ZMST.h \
    gendialog.h \
    rststrategy.h \
    rstviewer.h \
    mainrstview.h \
    minirstview.h \
    apdialog.h

FORMS    += mainwindow.ui \
    gendialog.ui \
    apdialog.ui

OTHER_FILES +=

RESOURCES += \
    icons.qrc


