#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T21:53:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator_2
TEMPLATE = app


SOURCES += main.cpp \
    Calculator.cpp \
    Calculation.cpp \
    printer.cpp \
    Scanner.cpp \
    FileOperation.cpp \
    TipsDialog.cpp \
    PrinterForDisplayArea.cpp

HEADERS  += \
    Calculator.h \
    Calculation.h \
    Printer.h \
    Scanner.h \
    FileOperation.h \
    TipsDialog.h \
    PrinterForDisplayArea.h

FORMS    += calculator.ui
RC_FILE  += calculatorIcon.rc
