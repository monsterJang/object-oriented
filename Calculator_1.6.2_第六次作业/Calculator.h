#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>
#include <string>
#include "fileoperation.h"
#include "scanner.h"
#include "printer.h"
#include "calculation.h"
#include "PrinterForDisplayArea.h"

namespace Ui {
class Calculator;
}

class Calculator : public QDialog
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();
protected:
    FileOperation *fo;
    Printer *pr;

    QLineEdit *editLine;     // 输入框
    QLabel *answerLine;      // 结果框
    QPushButton *button_0;     // 按钮
    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_3;
    QPushButton *button_4;
    QPushButton *button_5;
    QPushButton *button_6;
    QPushButton *button_7;
    QPushButton *button_8;
    QPushButton *button_9;
    QPushButton *button_point;
    QPushButton *button_add;
    QPushButton *button_sub;
    QPushButton *button_mul;
    QPushButton *button_div;
    QPushButton *button_equal;
    QPushButton *button_file;
    QPushButton *button_clear;
    QPushButton *button_del;
    QPushButton *button_lBracket;
    QPushButton *button_rBracket;
    string inputExp;
    QString showAnswer;
    double cacheAnswer;
    bool equalFlag;     // 是否已按下等号
private:
    Ui::Calculator *ui;
private slots:
    void button_0_clicked();     // 槽
    void button_1_clicked();
    void button_2_clicked();
    void button_3_clicked();
    void button_4_clicked();
    void button_5_clicked();
    void button_6_clicked();
    void button_7_clicked();
    void button_8_clicked();
    void button_9_clicked();
    void button_point_clicked();
    void button_add_clicked();
    void button_sub_clicked();
    void button_mul_clicked();
    void button_div_clicked();
    void button_equal_clicked();
    void button_file_clicked();
    void button_clear_clicked();
    void button_del_clicked();
    void button_lBracket_clicked();
    void button_rBracket_clicked();
};

#endif // CALCULATOR_H
