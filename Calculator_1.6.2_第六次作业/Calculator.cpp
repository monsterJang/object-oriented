/************************************************************
    FileName: Calculator.cpp
    Author: Jang
    Version: 1.6.2
    Date: 2016.06.04
    Description:  计算器界面
***********************************************************/

#include "Calculator.h"
#include "ui_Calculator.h"

Calculator::Calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("计算器"));
    this->setFixedSize(300, 230);
    this->setStyleSheet("background-image:url(D:/Qt_Creator_Projects/Calculator_2/bg_6.jpg)");

    fo = NULL;
    pr = new Printer();

    cacheAnswer = 0;
    equalFlag = false;
    editLine = new QLineEdit("0");
    answerLine = new QLabel("0");
    button_0 = new QPushButton("0");
    button_1 = new QPushButton("1");
    button_2 = new QPushButton("2");
    button_3 = new QPushButton("3");
    button_4 = new QPushButton("4");
    button_5 = new QPushButton("5");
    button_6 = new QPushButton("6");
    button_7 = new QPushButton("7");
    button_8 = new QPushButton("8");
    button_9 = new QPushButton("9");
    button_point = new QPushButton(".");
    button_add = new QPushButton("+");
        button_add->setFixedSize(51, 56);
    button_sub = new QPushButton("-");
    button_mul = new QPushButton(QStringLiteral("×"));
    button_div = new QPushButton(QStringLiteral("÷"));
    button_equal = new QPushButton("=");
    button_file = new QPushButton("File");
        button_file->setToolTip(QStringLiteral("文件读写操作"));
    button_clear = new QPushButton("C");
        button_clear->setFixedSize(51, 56);
    button_del = new QPushButton(QStringLiteral("←"));
    button_lBracket = new QPushButton("(");
    button_rBracket = new QPushButton(")");

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(editLine, 0, 0, 1, 5);
//    mainLayout->addWidget(expLine, 1, 0, 1, 5);
    mainLayout->addWidget(answerLine, 1, 0, 1, 5);
    mainLayout->addWidget(button_equal, 2, 0, 1, 2);
    mainLayout->addWidget(button_del, 2, 2, 1, 2);
    mainLayout->addWidget(button_file, 2, 4);
    mainLayout->addWidget(button_7, 3, 0);
    mainLayout->addWidget(button_8, 3, 1);
    mainLayout->addWidget(button_9, 3, 2);
    mainLayout->addWidget(button_mul, 3, 3);
    mainLayout->addWidget(button_lBracket, 3, 4);
    mainLayout->addWidget(button_4, 4, 0);
    mainLayout->addWidget(button_5, 4, 1);
    mainLayout->addWidget(button_6, 4, 2);
    mainLayout->addWidget(button_sub, 4, 3);
    mainLayout->addWidget(button_rBracket, 4, 4);
    mainLayout->addWidget(button_1, 5, 0);
    mainLayout->addWidget(button_2, 5, 1);
    mainLayout->addWidget(button_3, 5, 2);
    mainLayout->addWidget(button_add, 5, 3, 2, 1);
    mainLayout->addWidget(button_clear, 5, 4, 2, 1);
    mainLayout->addWidget(button_point, 6, 0);
    mainLayout->addWidget(button_0, 6, 1);
    mainLayout->addWidget(button_div, 6, 2);

    connect(button_0, SIGNAL(clicked()), this, SLOT(button_0_clicked()));
    connect(button_1, SIGNAL(clicked()), this, SLOT(button_1_clicked()));
    connect(button_2, SIGNAL(clicked()), this, SLOT(button_2_clicked()));
    connect(button_3, SIGNAL(clicked()), this, SLOT(button_3_clicked()));
    connect(button_4, SIGNAL(clicked()), this, SLOT(button_4_clicked()));
    connect(button_5, SIGNAL(clicked()), this, SLOT(button_5_clicked()));
    connect(button_6, SIGNAL(clicked()), this, SLOT(button_6_clicked()));
    connect(button_7, SIGNAL(clicked()), this, SLOT(button_7_clicked()));
    connect(button_8, SIGNAL(clicked()), this, SLOT(button_8_clicked()));
    connect(button_9, SIGNAL(clicked()), this, SLOT(button_9_clicked()));
    connect(button_point, SIGNAL(clicked()), this, SLOT(button_point_clicked()));
    connect(button_add, SIGNAL(clicked()), this, SLOT(button_add_clicked()));
    connect(button_sub, SIGNAL(clicked()), this, SLOT(button_sub_clicked()));
    connect(button_mul, SIGNAL(clicked()), this, SLOT(button_mul_clicked()));
    connect(button_div, SIGNAL(clicked()), this, SLOT(button_div_clicked()));
    connect(button_equal, SIGNAL(clicked()), this, SLOT(button_equal_clicked()));
    connect(button_file, SIGNAL(clicked()), this, SLOT(button_file_clicked()));
    connect(button_clear, SIGNAL(clicked()), this, SLOT(button_clear_clicked()));
    connect(button_del, SIGNAL(clicked()), this, SLOT(button_del_clicked()));
    connect(button_lBracket, SIGNAL(clicked()), this, SLOT(button_lBracket_clicked()));
    connect(button_rBracket, SIGNAL(clicked()), this, SLOT(button_rBracket_clicked()));

    setLayout(mainLayout);

}

void Calculator::button_0_clicked()
{
   if (editLine->text() == "0" || equalFlag)
   {
       if (equalFlag)
       {
           equalFlag = false;
       }
       editLine->setText(QString('0'));
   }
   else
   {
       editLine->setText(editLine->text() + QString('0'));
   }
}

void Calculator::button_1_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('1'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('1'));
    }
}

void Calculator::button_2_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('2'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('2'));
    }
}

void Calculator::button_3_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('3'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('3'));
    }
}

void Calculator::button_4_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('4'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('4'));
    }
}

void Calculator::button_5_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('5'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('5'));
    }
}

void Calculator::button_6_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('6'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('6'));
    }
}

void Calculator::button_7_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('7'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('7'));
    }
}

void Calculator::button_8_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('8'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('8'));
    }
}

void Calculator::button_9_clicked()
{
    if (editLine->text() == "0" || equalFlag)
    {
        if (equalFlag)
        {
            equalFlag = false;
        }
        editLine->setText(QString('9'));
    }
    else
    {
        editLine->setText(editLine->text() + QString('9'));
    }
}

void Calculator::button_point_clicked()
{
    if (equalFlag)
    {
        equalFlag = false;
    }
    editLine->setText(editLine->text() + QString('.'));
}

void Calculator::button_add_clicked()
{
    if (equalFlag)
    {
        equalFlag = false;
        editLine->setText(showAnswer);
    }
    editLine->setText(editLine->text() + QString('+'));
}

void Calculator::button_sub_clicked()
{
    if (equalFlag)
    {
        equalFlag = false;
        editLine->setText(showAnswer);
    }
    editLine->setText(editLine->text() + QString('-'));
}

void Calculator::button_mul_clicked()
{
    if (equalFlag)
    {
        equalFlag = false;
        editLine->setText(showAnswer);
    }
    editLine->setText(editLine->text() + QString('*'));
}

void Calculator::button_div_clicked()
{
    if (equalFlag)
    {
        equalFlag = false;
        editLine->setText(showAnswer);
    }
    editLine->setText(editLine->text() + QString('/'));
}

void Calculator::button_equal_clicked()
{
    if (equalFlag)
    {
        editLine->setText(QString('0'));
    }
    else
    {
        answerLine->setText(editLine->text() + QString(" = "));
        editLine->setText(editLine->text() + QString('='));
        inputExp = editLine->text().toStdString();
        cacheAnswer = pr->printResult(inputExp);
        showAnswer = QString::number(cacheAnswer, 10, 12);     // 默认至多保留12位小数
        int pointIndex = showAnswer.indexOf(".");
        bool afterPointNonZeroInt = false;     // 小数点后是否存在非零整数
        int afterPointFirstNonZeroIntIndex = pointIndex;
        for (int i = pointIndex; i < showAnswer.length(); i++)
        {
            if (showAnswer[i] >= '1' && showAnswer[i] <= '9')
            {
                afterPointNonZeroInt = true;
                afterPointFirstNonZeroIntIndex = i;
                break;
            }
        }
        int precision = showAnswer.indexOf("0", afterPointFirstNonZeroIntIndex);
        if (precision != -1 && precision > pointIndex)
        {
            if (!afterPointNonZeroInt)     // 若为整数(.000....)，则截取至(不含)小数点
            {
                showAnswer = showAnswer.left(pointIndex);
            }
            else
            {
                showAnswer = showAnswer.left(precision);
            }
        }
        answerLine->setText(answerLine->text() + showAnswer);
    }
    equalFlag = true;
}

void Calculator::button_file_clicked()
{
    fo = new FileOperation();
    fo->show();
}

void Calculator::button_clear_clicked()
{
    editLine->setText(QString('0'));
    answerLine->setText(QString('0'));
}

void Calculator::button_del_clicked()
{
    if (equalFlag)
    {
        equalFlag = false;
        editLine->setText(QString('0'));
        answerLine->setText(QString('0'));
    }
    else
    {
        QString qs = editLine->text();
        int len = qs.length();
        if (len == 1)
        {
            editLine->setText(QString('0'));
        }
        else
        {
            editLine->setText(qs.left(len - 1));
        }
    }
}

void Calculator::button_lBracket_clicked()
{
    if (editLine->text() == "0")
    {
        editLine->setText(QString('('));
    }
    else
    {
        editLine->setText(editLine->text() + QString('('));
    }
}

void Calculator::button_rBracket_clicked()
{
    if (editLine->text() == "0")
    {
        editLine->setText(QString(')'));
    }
    else
    {
        editLine->setText(editLine->text() + QString(')'));
    }
}

Calculator::~Calculator()
{
    delete ui;
}
