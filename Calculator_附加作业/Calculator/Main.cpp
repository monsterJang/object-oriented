/************************************************************
    FileName: Main.cpp   
    Author: Jang
    Version : 1.0
    Date: 16/03/26
    Description:  计算器项目的初始部分。接受一个四则运算表达式，逐个字符扫描这个表达式，
                       将数字和符号提取出来，得到一组string，并存入队列
    Function List: int main(): 主函数，包含上述对表达式的输入、处理、转换和输出
***********************************************************/ 

#include <iostream>
#include <string>
#include "Scan.h"
#include "Print.h"

using namespace std;

int main()
{
    // 提示信息
    cout << "请输入四则运算表达式：" << endl;
    cout << "please input the arithmetic expression:\n" << endl;
    string input;
    // 接受用户输入
    cin >> input;
    Scan *sc = new Scan();
    Print *pr = new Print();
    // 调用Scan类的ToStringQueue得到string队列
    queue<string> qu = sc->ToStringQueue(input);
    // 输出该队列
    pr->printQueue(qu, sc->getIsExceed10());
    // 对象销毁
    delete sc;
    sc = NULL;
    delete pr;
    pr = NULL;
    system("pause");
    return 0;
}