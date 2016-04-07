/************************************************************
    FileName: Calculation.cpp   
    Author: Jang
    Version : 1.1.0
    Date: 2016.04.07
    Description:  ����string���б��ʽ��ֵ
    Function List:
        1.void setPriorityLevel() : ������������ȼ�
        2.bool isOperator(string s) : �ж��Ƿ�Ϊ�����
        3.bool isDigit(string s) : �ж��Ƿ�Ϊ����
	    4.void toPostfixExpression(queue<string> q) : ��string���б��ʽת��Ϊ��׺���ʽ
        5.void calculatingExpression(queue<string> q, bool is_Exceed10) : ��Ҫ�ļ��㺯����������ʽ��ֵ�����
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
    Description: ��������������ȼ�����ֵԽ�ͱ�ʾ���ȼ�Խ�ߣ�
*************************************************/
void Calculation::setPriorityLevel()
{
    priority['+'] = 4;
    priority['-'] = 4;
    priority['*'] = 3;
    priority['/'] = 3;
}


/*************************************************
    Description: �жϴ����string�Ƿ�Ϊ������
    Input: string s: �����жϵ�string����
    Return:  ��sΪ�����������true�����򷵻�false
*************************************************/
bool Calculation::isOperator(string s)
{  
    return (s == "+" || s == "-" || s == "*" || s == "/");  
}


/*************************************************
    Description: �жϴ����string�Ƿ�Ϊ����
    Input: string s: �����жϵ�string����
    Return:  ��sΪ���֣�����true�����򷵻�false
*************************************************/
bool Calculation::isDigit(string s)
{
    return (s.size() > 1 || isdigit(s[0]));
}


/*************************************************
    Description: ����׺���ʽת��Ϊ��׺���ʽ
    Input: queue<string> q: ת�����׺���ʽ��ʽ�Ķ���
*************************************************/
void Calculation::toPostfixExpression(queue<string>q)
{
    string temp;     // ��¼�����q���еĶ���Ԫ��
    while (!q.empty())
    {
        temp = q.front();

        if (isDigit(temp))     // ���ö���Ԫ�������֣���ֱ�ӽ�ջ
        {
            cacheStack.push(temp);
        }

        else if (isOperator(temp))     // ���ö���Ԫ��Ϊ�����������"+", "-", "*", "/"
        {
            if (operatorStack.empty())     // �������ջΪ�գ���ֱ�ӽ�ջ
            {
                operatorStack.push(temp);
            }
            else if (operatorStack.top() == "(")     // �������ջ��Ϊ�����ţ���ֱ�ӽ�ջ
            {
                operatorStack.push(temp);
            }
            else if (priority[temp[0]] < priority[operatorStack.top()[0]])     // ����ǰtemp�����ȼ���ջ������������ȼ��ߣ���ֱ�ӽ�ջ
            {
                operatorStack.push(temp);
            }
            else     // ������������3������ʱ����������ջ��ջ��Ԫ��push������ջcacheStack֮���ջ���ظ�����ֱ��������ջ��������3�����֮һΪֹ
            {
                cacheStack.push(operatorStack.top());
                operatorStack.pop();
                continue;
            }
        }

        else if (temp == "(")     // ���ö���Ԫ��Ϊ"("��ֱ�ӽ�ջ
        {
            operatorStack.push(temp);
        }

        else if (temp == ")")     // ���ö���Ԫ��Ϊ")"������������ջջ��Ԫ��ֱ������"("��������Ԫ��push������ջ
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

        q.pop();     // ��������Ԫ�أ�������һԪ�ص��ж�
    }
    while (!operatorStack.empty())     // ��ʣ�µĲ�����ѹ�뻺��ջcacheStack
    {
        cacheStack.push(operatorStack.top());
        operatorStack.pop();
    }    
}


/*************************************************
    Description: ������ı��ʽת��Ϊ��׺���ʽ����������ʽ��ֵ
    Function List: void Calculation::toPostfixExpression(queue<string>q): ������ı��ʽת��Ϊ��׺���ʽ
    Input: queue<string> q: ת�����׺���ʽ��ʽ�Ķ���
    Ouput: ���ʽ��ֵ
*************************************************/
void Calculation::calculatingExpression(queue<string> q, bool is_Exceed10)
{
    if (is_Exceed10)     // ������10λ�������ִ���Ϊ��
    {
        cout << "Input error !  Not exceeding 10 digits expected! " << endl;
        return ;
    }

    setPriorityLevel();     // ���÷��ŵ����ȼ�
	toPostfixExpression(q);     // ����׺���ʽת��Ϊ��׺���ʽ

    /**********���㲿��***********/
    string postfixExp[SIZE];     // ���ڼ���ʱ��Ի���ջ��ջ�׵�ջ������һɨ�裬����string������б�������
    int expLen = 0;
    while (!cacheStack.empty())
    {
        postfixExp[expLen++] = cacheStack.top();
        cacheStack.pop();
    }

    stringstream stream;     // ��stringstream������string��int�ĸ�ʽת��
    for (int i = expLen - 1; i >= 0; i--)
    {
        if (isDigit(postfixExp[i]))     // ����Ԫ��Ϊ���֣���ֱ��������ջdigitStack
        {
            digitStack.push(postfixExp[i]);
        }
        else if (isOperator(postfixExp[i]))     // ����Ԫ��Ϊ��������򵯳�����ջ��������������Ӧ�����㲢�����push������ջ
        {
            int rightNum = 0;     // �Ҳ�����
            if (!digitStack.empty())
            {
                stream << digitStack.top();     // ��ʽת����string->int
                stream >> rightNum;
                digitStack.pop();
                stream.clear();     // stringstream������գ��Ա��ظ�����
            }
            int leftNum = 0;     // �������
            if (!digitStack.empty())
            {
                stream << digitStack.top();     // ��ʽת����string->int
                stream >> leftNum;
                digitStack.pop();
                stream.clear();
            }

            string res;     // res������ʱ�洢��������push������ջ
            if (postfixExp[i] == "+")     // �ӷ�����
            {
                stream << (leftNum + rightNum);     // ��ʽת����int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // ��������ջ
                res = "";
            }
            else if (postfixExp[i] == "-")     // ��������
            {
                stream << (leftNum - rightNum);     // ��ʽת����int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // ��������ջ
                res = "";
            }
            else if (postfixExp[i] == "*")     // �˷�����
            {
                stream << (leftNum * rightNum);     // ��ʽת����int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // ��������ջ
                res = "";
            }
            else if (postfixExp[i] == "/")     // ��������
            {
                stream << (leftNum / rightNum);     // ��ʽת����int->string
                stream >> res;
                stream.clear();
                digitStack.push(res);     // ��������ջ
                res = "";
            }
        }
    }

    cout << digitStack.top() << endl;     // ��ʱ������ջջ�����������һ������Ľ������Ϊ���ʽ��ֵ
	digitStack.pop();
}