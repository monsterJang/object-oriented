/************************************************************
    FileName: Main.cpp   
    Author: Jang
    Version : 1.5.0
    Date: 2016.05.09
    Description:  计算器项目的初始部分的改进。在之前接受一个四则运算表达式后输出表达式的值的基础上，
                          增加了对文件的读写操作
    Function List: int main(): 主函数，包含上述对表达式的输入、处理、转换和输出
    Compare to previous vision:
	    1.输入增加文件读写，输出由Print类实现
        2.将Scan类和Calculation类的实例置于Print类的构造函数中初始化，析构函数中释放~
***********************************************************/ 

#include "Print.h"
#include <iostream>
#include <cstring>

using namespace std;

/*************************************************
    Description: 接收表达式的输入并求值
    Input: int argc: 命令行参数个数
              char *argv[] : 实际传入的命令行参数
    Return: 若正常结束，则返回0
*************************************************/
int main(int argc, char *argv[])
{
	Print *pr = new Print();
    if (argc == 2)     // 对传入的参数只有表达式的处理，调用Print类对应的PrintResult方法输出
	{
		pr->printResult(argv[1]);
	}
    else if (!strcmp(argv[1], "-a") && argc == 3)     // 对传入的参数为"-a"的处理，调用Print类对应的PrintResult_a方法输出
    {
		pr->printResult_a(argv[2]);
    }
    else if (!strcmp(argv[1], "-f") && argc == 4)     // 对传入的参数为"-f"的处理，调用Print类对应的PrintResult_f方法输出
    {
		pr->printResult_f(argv[2], argv[3]);
    }
	else
	{
		cout << "Input error!" << endl;
	}

//   system("pause");
    return 0;
}