/************************************************************
    FileName: Scan.cpp   
    Author: Jang
    Version : 1.1.0
    Date: 2016.04.07
    Description:  将string表达式转换为数字与操作符分开的string队列
    Function List:
	    1. void ToStringQueue(string input) : 得到string 队列
        2. void setIsExceed10(bool _isExceed10) : 改变isExceed的值
        3. bool getIsExceed10(): 得到isExceed10
***********************************************************/ 

#include "Scan.h"
#define N 100

using namespace std;


Scan::Scan(void)
{
}


Scan::~Scan(void)
{
}


void Scan::setIsExceed10(bool _isExceed10)
{
	isExceed10 = _isExceed10;
}


bool Scan::getIsExceed10()
{
	return isExceed10;
}


/*************************************************
    Description: 接受一个四则运算表达式，逐个字符扫描这个表达式，
                       将数字和符号提取出来，得到一组string，存入队列并返回
    Input: string input: 即所输入的四则运算表达式
	Return:  q: 即所得到的string队列
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
    queue<string> q;     // q即为最后所要return的队列，用于保存input表达式中的数字和符号
    string res = "";     // res为扫描input表达式时用于临时存储的字符串
    string strArr[N];     // strArr为扫描input表达式时用于存储数字和符号的string数组
    int len = input.length();
    int cnt = 0;     // 作为strArr的下标记录已完成提取的数字和符号的个数
    setIsExceed10(false);

    for (int i = 0; i < len; i++)
    {
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
        {
            res += input[i];     // 若是数字或 '.' 则添加到临时存储器res里，
            if (i == len - 1)     // 若已完成扫描
            {
                strArr[cnt++] = res;
                break;
            }
            continue;     // 继续判断下一元素
        }
        else
        {
			if (i == 0 && res.empty())     // 若第一个元素为‘-’
			{
				res += input[i];
				continue;
			}
            if (!res.empty())     // res非空表示此时res中缓存着一个数字 或 第一个元素为 '-'
            {
                strArr[cnt++] = res;
            }
            res = "";     // res置空
            strArr[cnt++] = res + input[i];     // 将不是数字或 "." 的元素（即符号元素）添加到strArr中
        }
    }

    for (int i =0; i < cnt; i++)     // 将strArr中各个元素添加到q队列中
    {
        if (strArr[i].length() > 10)
        {
            setIsExceed10(true);     // 存在大于10位数的数字
        }
        q.push(strArr[i]);
    }

    return q;
}