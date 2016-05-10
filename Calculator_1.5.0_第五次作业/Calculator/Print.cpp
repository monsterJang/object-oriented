/************************************************************
    FileName: Print.cpp   
    Author: Jang
    Version: 1.5.0
    Date: 2016.05.09
    Description:  针对不同的命令行参数的输出和队列输出的功能
    Function List:
        1.void printError(): 针对输入不符合规范的输出
        1. void printResult(string input): 针对命令行参数为 表达式 的输出
        2. void printResult_a(string input): 针对命令行参数为 "-a"和表达式 的输出
        3. void printResult_f(string inputAddr, string outputAddr): 针对命令行参数为 "-f"和输入、输出文件地址 的输出
        4. void printQueue(queue<string> q, bool isExceed10): 将q队列逐一输出
***********************************************************/ 

#include "Print.h"
#include <iostream>
#include <fstream>

Print::Print(void)     // 在构造函数中初始化 *sc 和 *ca
{
    sc = new Scan();
    ca = new Calculation();
}

Print::~Print(void)     // 在析构函数中释放
{
    delete sc;
    sc = NULL;
    delete ca;
    ca = NULL;
}

void Print::printError()
{
    cout << "Input error!" << endl;
}

/*************************************************
    Description: 针对命令行参数为 表达式 的输出
    Input: string input: 待计算的表达式
    Output: 表达式的值
*************************************************/
void Print::printResult(string input)
{
    ca->calculatingExpression(sc->ToStringQueue(input), sc->getIsExceed10());
    cout << ca->getDigitStack().top() << endl;
    ca->getDigitStack().pop();
}

/*************************************************
    Description: 针对命令行参数为 "-a"和表达式 的输出
    Input: string input: 待计算的表达式
    Output: 表达式及表达式的值
*************************************************/
void Print::printResult_a(string input)
{
    cout << input << " ";
    ca->calculatingExpression(sc->ToStringQueue(input), sc->getIsExceed10());
    cout << ca->getDigitStack().top() << endl;
    ca->getDigitStack().pop();
}

/*************************************************
    Description: 针对命令行参数为 "-f"和输入、输出文件地址 的输出
    Input: string inputAddr: 即读取的文件地址
              string outputAddr: 即写入的文件地址
*************************************************/
void Print::printResult_f(string inputAddr, string outputAddr)
{
    string input;
    fstream file_read(inputAddr);
    fstream file_write(outputAddr, ios::out);
    while (!file_read.eof())
    {
        file_read >> input;
        ca->calculatingExpression(sc->ToStringQueue(input), sc->getIsExceed10());
        file_write << input  << " " << ca->getDigitStack().top() << "\n";
        ca->getDigitStack().pop();
    }
    file_read.close();
    file_write.close();
}

/*************************************************
    Description: 接受一个string队列，逐个输出
    Input: squeue<string> q: 即所要输出的string队列
               bool isExceed10: 即判断队列中是否存在大于10位的数字
*************************************************/
void Print::printQueue(queue<string> q, bool isExceed10)
{
    if (isExceed10)     // 若超过10位数的数字存在为真
    {
        cout << "Input error !  Not exceeding 10 digits expected! " << endl;
        return ;
    }

    while (q.size())
    {
        cout << q.front() << endl;     // 输入队首元素
        q.pop();     // 删除队首元素
    }
}