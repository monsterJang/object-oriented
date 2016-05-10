/************************************************************
    FileName: Calculation.cpp   
    Author: Jang
    Version : 1.5.0
    Date: 2016.05.09
    Description:  计算string队列表达式的值
    Function List:
        1.void setPriorityLevel() : 设置运算符优先级
        2.stack<double>& getDigitStack() : 得到DigitStack栈
        3.bool isOperator(string s) : 判断是否为运算符
        4.bool isDigit(string s) : 判断是否为数字
        5.void toPostfixExpression(queue<string> q) : 将string队列表达式转换为后缀表达式
        6.void calculatingExpression(queue<string> q, bool is_Exceed10) : 主要的计算函数，计算表达式的值并输出
    Compare to previous vision:
	    1.将运算符的4个if-else语句换成了swich-case语句(感觉还是方便了不少)
        2.将数字栈digitStack的类型由stack<string>换成了stack<double>，在操作上简便了很多，减少了stringstream流
           的使用频率，也缩减了代码量
        3.将类成员变量置为private，并为digitStack提供了getter方法以便外部调用
        4.改变了calculatingExpression的返回值类型，由digitStack.top()得到计算结果
        5.在构造函数中进行必要的初始化
***********************************************************/ 

#include "Calculation.h"
#include <ctype.h>
#include <iostream>
#include <sstream>

Calculation::Calculation(void)
{
    setPriorityLevel();     // 初始化符号的优先级
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


stack<double>& Calculation::getDigitStack()
{
    return digitStack;
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
        return;
    }

	toPostfixExpression(q);     // 将中缀表达式转换为后缀表达式

    /**********计算部分***********/
    string postfixExp[SIZE];     // 由于计算时需对缓存栈从栈底到栈顶的逐一扫描，故用string数组进行遍历操作
    int expLen = 0;
    while (!cacheStack.empty())
    {
        postfixExp[expLen++] = cacheStack.top();
        cacheStack.pop();
    }

    stringstream str_stream;     // 用stringstream流进行string和double的格式转换
    double res = 0;     // res用于临时存储，push进数字栈
    double rightNum = 0;     // 右操作数
    double leftNum = 0;     // 左操作数
    for (int i = expLen - 1; i >= 0; i--)
    {
        if (isDigit(postfixExp[i]))     // 若该元素为数字，则直接入数字栈digitStack
        {
            str_stream << postfixExp[i];     // 格式转换：string->double
            str_stream >> res;
            digitStack.push(res);
            str_stream.clear();     // stringstream流的清空，以便重复利用
            str_stream.str("");
        }
        else if (isOperator(postfixExp[i]))     // 若该元素为运算符，则弹出数字栈的两个数进行相应的运算并将结果push进数字栈
        {
            if (!digitStack.empty())
            {
                rightNum = digitStack.top();
                digitStack.pop();
            }
            if (!digitStack.empty())
            {
                leftNum = digitStack.top();
                digitStack.pop();
            }

            switch (postfixExp[i][0])     // 对应加法、减法、乘法、除法运算
            {
            case '+':
                digitStack.push(leftNum + rightNum);
                break;
            case '-':
                digitStack.push(leftNum - rightNum);
                break;
            case '*':
                digitStack.push(leftNum * rightNum);
                break;
            case '/':
                digitStack.push(leftNum / rightNum);
                break;
            default:
                break;
            }
        }
    }
}