#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QtGui>
#include <QString>
#include <string>
#include "Scanner.h"
#include "Printer.h"
#include "Calculation.h"

class FileOperation : public QDialog
{
    Q_OBJECT
public:
    explicit FileOperation(QWidget *parent = 0);
    ~FileOperation();
protected:
    Printer *pr;
    QLabel *input_1;
    QLabel *input_2;
    QLineEdit *inputAddrLine;
    QLineEdit *outputAddrLine;
    QPushButton *findAddr_1;
    QPushButton *findAddr_2;
    QPushButton *finish;
    QPushButton *cancel;
    string inputAddr;
    string outputAddr;
signals:
    void clicked();
private slots:
    void findAddr_1_clicked();
    void findAddr_2_clicked();
    void finish_clicked();
    void cancel_clicked();
};

#endif // FILEOPERATION_H
