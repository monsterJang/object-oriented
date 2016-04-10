/************************************************************
    FileName: Calculation.cpp   
    Author: Jang
    Version : 1.1.0
    Date: 2016.04.07
    Description:  计算string队列表达式的值
    Function List:
        1.void setPriorityLevel() : 设置运算符优先级
        2.bool isOperator(string s) : 判断是否为运算符
        3.bool isDigit(string s) : 判断是否为数字
	    4.void toPostfixExpression(queue<string> q) : 将string队列表达式转换为后缀表达式
        5.void calculatingExpression(queue<string> q, bool is_Exceed10) : 主要的计算函数，计算表达式的值并输出
***********************************************************/ 

#include "Calculation.h"
#include <ctype.h>
#include <iostream>
#include <sstream>

Calculation::Calculation(void)
{
}


Calculation::~Calculation(void)
{
}


/*************************************************
    Description: 设置运算符的优先级（数值越低表示优先级越高）
*************************************************/
void Calculation::setPriorityLevel()
{
    priority['+'] = 4;
    priority['-'] = 4;
    priority['*'] = 3;
    priority['/'] = 3;
}


/*************************************************
    Description: 判断传入的string是否为操作符
    Input: string s: 即待判断的string数据
    Return:  若s为运算符，返回true，否则返回false
*************************************************/
bool Calculation::isOperator(string s)
{  
    return (s == "+" || s == "-" || s == "*" || s == "/");  
}


/*************************************************
    Description: 判断传入的string是否为数字
    Input: string s: 即待判断的string数据
    Return:  若s为数字，返回true，否则返回false
*************************************************/
bool Calculation::isDigit(string s)
{
    return (s.size() > 1 || isdigit(s[0]));
}


/*************************************************
    Description: 将中缀表达式转化为后缀表达式
    Input: queue<string> q: 转入的中缀表达式形式的队列
*************************************************/
void Calculation::toPostfixExpression(queue<string>q)
{
    string temp;     // 记录传入的q队列的队首元素
    while (!q.empty())
    {
        temp = q.front();

        if (isDigit(temp))     // 若该队首元素是数字，则直接进栈
        {
            cacheStack.push(temp);
        }

        else if (isOperator(temp))     // 若该队首元素为运算符，包括"+", "-", "*", "/"
        {
            if (operatorStack.empty())     // 若运算符栈为空，则直接进栈
            {
                operatorStack.push(temp);
            }
            else if (operatorStack.top() == "(")     // 若运算符栈顶为左括号，则直接进栈
            {
                operatorStack.push(temp);
            }
            else if (priority[temp[0]] < priority[operatorStack.top()[0]])     // 若当前temp的优先级比栈顶运算符的优先级高，则直接进栈
            {
                operatorStack.push(temp);
            }
            else     // 当不满足如上3种条件时，将操作符栈的栈顶元素push进缓存栈cacheStack之后出栈，重复操作直到操作符栈满足上述3种情况之一为止
            {
                cacheStack.push(operatorStack.top());
                operatorStack.pop();
                continue;
            }
        }

        else if (temp == "(")     // 若该队首元素为"("，直接进栈
        {
            operatorStack.push(temp);
        }

        else if (temp == ")")     // 若该队首元素为")"，弹出操作符栈栈顶元素直到遇见"("，将弹出元素push进缓存栈
        {
            while (!operatorStack.empty())
            {
                if (operatorStack.top() == "(")
                {
                    operatorStack.pop();
                    break;
                }
                cacheStack.push(operatorStack.top());
                operatorStack.pop();
            }
        }

        q.pop();     // 弹出队首元素，继续下一元素的判断
    }
    while (!operatorStack.empty())     // 将剩下的操作符压入缓存栈cacheStack
    {
        cacheStack.push(operatorStack.top());
        operatorStack.pop();
    }    
}


/*************************************************
    Description: 将传入的表达式转化为后缀表达式并计算出表达式的值
    Function List: void Calculation::toPostfixExpression(queue<string>q): 将传入的表达式转化为后缀表达式
    Input: queue<string> q: 转入的中缀表达式形式的队列
    Ouput: 表达式的值
*************************************************/
void Calculation::calculatingExpression(queue<string> q, bool is_Exceed10)
{
    if (is_Exceed10)     // 若超过10位数的数字存在为真
    {
        cout << "Input error !  Not exceeding 10 digits expected! " << endl;
        return ;
    }

    setPriorityLevel();     // 设置符号的优先级
	toPostfixExpression(q);     // 将中缀表达式转换为后缀表达式

    /**********计算部分***********/
    string postfixExp[SIZE];     // 由于计算时需对缓存栈从栈底到栈顶的逐一扫描，故用string数组进行遍历操作
    int expLen = 0;
    while (!cacheStack.empty())
    {
        postfixExp[expLen++] = cacheStack.top();
        cacheStack.pop();
    }

    stringstream stream;     // 用stringstream流进行string和int的格式转换
    for (int i = expLen - 1; i >= 0; i--)
    {
        if (isDigit(postfixExp[i]))     // 若该元素为数字，则直接入数字栈digitStack
        {
            digitStack.push(postfixExp[i]);
        }
        else if (isOperator(postfixExp[i]))     // 若该元素为运算符，则弹出数字栈的两个数进行相应的运算并将结果push进数字栈
        {
            int rightNum = 0;     // 右操作数
            if (!digitStack.empty())
            {
                stream << digitStack.top();     // 格式转换：string->int
                stream >> rightNum;
                digitStack.pop();
                stream.clear();     // stringstream流的清空，以便重复利用
            }
            int leftNum = 0;     // 左操作数
            if (!digitStack.empty())
            {
                stream << digitStack.top();     // 格式转换：string->int
                stream >> leftNum;
                digitStack.pop();
                stream.clear();
            }

            string res;     // res用于临时存储运算结果，push进数字栈
            if (postfixExp[i] == "+")     // 加法运算
            {
                stream << (leftNum + rightNum);     // 格式转换：int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // 运算结果进栈
                res = "";
            }
            else if (postfixExp[i] == "-")     // 减法运算
            {
                stream << (leftNum - rightNum);     // 格式转换：int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // 运算结果进栈
                res = "";
            }
            else if (postfixExp[i] == "*")     // 乘法运算
            {
                stream << (leftNum * rightNum);     // 格式转换：int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // 运算结果进栈
                res = "";
            }
            else if (postfixExp[i] == "/")     // 除法运算
            {
                stream << (leftNum / rightNum);     // 格式转换：int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // 运算结果进栈
                res = "";
            }
        }
    }

    cout << digitStack.top() << endl;     // 此时，数字栈栈顶保存着最后一次运算的结果，即为表达式的值
	digitStack.pop();
}