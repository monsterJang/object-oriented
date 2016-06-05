/************************************************************
    FileName: Scanner.cpp
    Author: Jang
    Version : 1.6.2
    Date: 2016.06.04
    Description:  将string表达式转换为数字与操作符分开的string队列
    Function List:
        1. void ToStringQueue(string input) : 得到string 队列
        2. void setIsExceedMaxNumLen(bool _isExceedMaxNumLen) : 改变isExceed的值
        3. bool getIsExceedMaxNumLen(): 得到isExceedMaxNumLen
    Compare to previous vision:
        这次输入的表达式多出了一个等号‘=’，所以在扫描表达式时，循环次数较之前少1次，即忽略等号
***********************************************************/

#include "Scanner.h"
#define maxExpLen 100
#define maxNumLen 10

using namespace std;


Scanner::Scanner(void)
{
    setIsExceedMaxNumLen(false);     // isExceedMaxNumLen的初始化
}


Scanner::~Scanner(void)
{
}


void Scanner::setIsExceedMaxNumLen(bool _isExceedMaxNumLen)
{
    isExceedMaxNumLen = _isExceedMaxNumLen;
}


bool Scanner::getIsExceedMaxNumLen()
{
    return isExceedMaxNumLen;
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

/*************************************************
    Description: 接受一个四则运算表达式，逐个字符扫描这个表达式，
                       将数字和符号提取出来，得到一组string，存入队列并返回
    Input: string input: 即所输入的四则运算表达式
    Return:  q: 即所得到的string队列
*************************************************/
queue<string> Scanner::ToStringQueue(string input)
{
    queue<string> q;     // q即为最后所要return的队列，用于保存input表达式中的数字和符号
    string res = "";     // res为扫描input表达式时用于临时存储的字符串
    string strArr[maxExpLen];     // strArr为扫描input表达式时用于存储数字和符号的string数组
    int len = input.length() - 1; // 省略最后的等号'='
    int cnt = 0;     // 作为strArr的下标记录已完成提取的数字和符号的个数

    for (int i = 0; i < len; i++)
    {
        if (input[i] == '-' && i - 1 >= 0 && (isDigit(input[i - 1]) || input[i - 1] == ')') && i + 1 < len && isDigit(input[i + 1]))
        {
            strArr[cnt++] = "+";
        }
        if (isDigit(input[i]) || input[i] == '.')
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
            if (input[i] == '-')     // 若元素为‘-’，则要根据res空或非空及下一元素进行判断
            {
                if (res.empty())     // 若res空，则根据下一元素进行判断
                {
                    res += input[i];
                    continue;
                }
                else     // 若res非空，则将res内缓存的符号添加，再根据下一元素进行判断
                {
                    strArr[cnt++] = res;
                    res = "-";
                    continue;
                }
            }
            if (!res.empty())     // res非空表示此时res中缓存着一个数字 或 第一个元素为 '-'
            {
                strArr[cnt++] = res;
            }
            res = "";     // res置空
            strArr[cnt++] = res + input[i];     // 将不是数字或 "." 的元素（即符号元素）添加到strArr中
        }
    }

    for (int i = 0; i < cnt; i++)     // 将strArr中各个元素添加到q队列中
    {
        if (strArr[i].length() > maxNumLen)
        {
            setIsExceedMaxNumLen(true);     // 存在大于MaxNumLen位数的数字
        }
        q.push(strArr[i]);
    }

    return q;
}
