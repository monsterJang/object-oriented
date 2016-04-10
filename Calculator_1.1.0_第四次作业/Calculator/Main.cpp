/************************************************************
    FileName: Main.cpp   
    Author: Jang
    Version : 1.1.0
    Date: 16/03/26
    Description:  计算器项目的初始部分。接受一个四则运算表达式，逐个字符扫描这个表达式，
                       将数字和符号提取出来，得到一组string，并存入队列
    Function List: int main(): 主函数，包含上述对表达式的输入、处理、转换和输出
***********************************************************/ 

#include "Scan.h"
//#include "Print.h"     // 测试用
#include "Calculation.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*************************************************
    Description: 接收表达式的输入并求值
    Input: int argc: 命令行参数个数
              char *argv[] : 实际传入的命令行参数
    Ouput: 表达式参数的运算结果
    Return: 若正常结束，则返回0
*************************************************/
int main(int argc, char *argv[])
{
    string input;
    if (!strcmp(argv[1], "-a"))     // 对传入的参数为"-a"的处理
    {
        input = argv[2];
    }
    else
    {
        input = argv[1];
    }

    Scan *sc = new Scan();
    Calculation *ca = new Calculation();

    // 调用Scan类的ToStringQueue得到string队列
    queue<string> qu = sc->ToStringQueue(input);
    // 若传入参数"-a"，则将表达式输出
    if (strcmp(argv[1], "-a") == 0)
    {
        cout << input << "= ";
    }
    // 调用Calculation类的calculatingExpression得到表达式参数的运算结果
    ca->calculatingExpression(qu, sc->getIsExceed10());

    // 对象销毁
    delete sc;
    sc = NULL;
    delete ca;
    ca = NULL;
//    system("pause");
    return 0;
}