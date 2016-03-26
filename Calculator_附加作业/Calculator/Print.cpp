/************************************************************
    FileName: Print.cpp   
    Author: Jang
    Version : 1.0
    Date: 16/03/26
    Description:  输出队列的功能
     Function List: 1. void printQueue(queue<string> q, bool isExceed10): 将q队列逐一输出
***********************************************************/ 

#include "Print.h"
#include <iostream>

Print::Print(void)
{
}


Print::~Print(void)
{
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
        cout << "\n输入错误！应输入不超过10位的数字！" << endl;
        cout << "Input error !  Not exceeding 10 digits expected! " << endl;
        return ;
    }

    while (q.size())
    {
        cout << q.front() << endl;     // 输入队首元素
        q.pop();     // 删除队首元素
    }
}