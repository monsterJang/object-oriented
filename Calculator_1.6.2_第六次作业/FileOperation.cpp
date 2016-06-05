/************************************************************
    FileName: FileOperation.cpp
    Author: Jang
    Version: 1.6.2
    Date: 2016.06.04
    Description:  文件操作界面
***********************************************************/

#include "FileOperation.h"
#include <QGridLayout>
#include <QFileDialog>
#include <iostream>

FileOperation::FileOperation(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle(QStringLiteral("文件读写操作"));
    this->setFixedSize(250, 150);
    this->setStyleSheet("background-image:url(D:/Qt_Creator_Projects/Calculator_2/bg_6.jpg)");

    pr = new Printer();
    input_1 = new QLabel("the input file address :");
    input_2 = new QLabel("the output file address :");
    inputAddrLine = new QLineEdit();
    outputAddrLine = new QLineEdit();
    findAddr_1 = new QPushButton("Browse");
        findAddr_1->setToolTip(QStringLiteral("选择输入文件路径"));
    findAddr_2 = new QPushButton("Browse");
        findAddr_2->setToolTip(QStringLiteral("选择输出文件路径"));
    finish = new QPushButton("Finish");
    cancel = new QPushButton("Cancel");
    QGridLayout *fileDialogLayout = new QGridLayout(this);
    fileDialogLayout->addWidget(input_1, 0, 0, 1, 4);
    fileDialogLayout->addWidget(inputAddrLine, 1, 0, 1, 3);
    fileDialogLayout->addWidget(findAddr_1, 1, 3);
    fileDialogLayout->addWidget(input_2, 2, 0, 1, 4);
    fileDialogLayout->addWidget(outputAddrLine, 3, 0, 1, 3);
    fileDialogLayout->addWidget(findAddr_2, 3, 3);
    fileDialogLayout->addWidget(finish, 4, 2);
    fileDialogLayout->addWidget(cancel, 4, 3);

    connect(findAddr_1, SIGNAL(clicked()), this, SLOT(findAddr_1_clicked()));
    connect(findAddr_2, SIGNAL(clicked()), this, SLOT(findAddr_2_clicked()));
    connect(finish, SIGNAL(clicked()), this, SLOT(finish_clicked()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(cancel_clicked()));

    setWindowFlags(Qt::WindowStaysOnTopHint);
    setLayout(fileDialogLayout);
}

void FileOperation::findAddr_1_clicked()
{
    QString fil = QFileDialog::getOpenFileName(this, tr("Open txt"), ".", tr("txt Files(*.txt)"));
    inputAddrLine->setText(fil);
}

void FileOperation::findAddr_2_clicked()
{
    QString fil = QFileDialog::getOpenFileName(this, tr("Open txt"), ".", tr("txt Files(*.txt)"));
    outputAddrLine->setText(fil);
}

void FileOperation::finish_clicked()
{
    inputAddr = inputAddrLine->text().toStdString();
    outputAddr = outputAddrLine->text().toStdString();
    if (inputAddr.empty() || outputAddr.empty())
    {
        cout << "无效地址" << endl;
    }
    else
    {
        pr->printResult_f(inputAddr, outputAddr);
    }
    this->close();
}

void FileOperation::cancel_clicked()
{
    this->close();
}
FileOperation::~FileOperation()
{

}
