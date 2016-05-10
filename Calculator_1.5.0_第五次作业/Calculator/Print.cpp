/************************************************************
    FileName: Print.cpp   
    Author: Jang
    Version: 1.5.0
    Date: 2016.05.09
    Description:  ��Բ�ͬ�������в���������Ͷ�������Ĺ���
    Function List:
        1.void printError(): ������벻���Ϲ淶�����
        1. void printResult(string input): ��������в���Ϊ ���ʽ �����
        2. void printResult_a(string input): ��������в���Ϊ "-a"�ͱ��ʽ �����
        3. void printResult_f(string inputAddr, string outputAddr): ��������в���Ϊ "-f"�����롢����ļ���ַ �����
        4. void printQueue(queue<string> q, bool isExceed10): ��q������һ���
***********************************************************/ 

#include "Print.h"
#include <iostream>
#include <fstream>

Print::Print(void)     // �ڹ��캯���г�ʼ�� *sc �� *ca
{
    sc = new Scan();
    ca = new Calculation();
}

Print::~Print(void)     // �������������ͷ�
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
    Description: ��������в���Ϊ ���ʽ �����
    Input: string input: ������ı��ʽ
    Output: ���ʽ��ֵ
*************************************************/
void Print::printResult(string input)
{
    ca->calculatingExpression(sc->ToStringQueue(input), sc->getIsExceed10());
    cout << ca->getDigitStack().top() << endl;
    ca->getDigitStack().pop();
}

/*************************************************
    Description: ��������в���Ϊ "-a"�ͱ��ʽ �����
    Input: string input: ������ı��ʽ
    Output: ���ʽ�����ʽ��ֵ
*************************************************/
void Print::printResult_a(string input)
{
    cout << input << " ";
    ca->calculatingExpression(sc->ToStringQueue(input), sc->getIsExceed10());
    cout << ca->getDigitStack().top() << endl;
    ca->getDigitStack().pop();
}

/*************************************************
    Description: ��������в���Ϊ "-f"�����롢����ļ���ַ �����
    Input: string inputAddr: ����ȡ���ļ���ַ
              string outputAddr: ��д����ļ���ַ
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
    Description: ����һ��string���У�������
    Input: squeue<string> q: ����Ҫ�����string����
               bool isExceed10: ���ж϶������Ƿ���ڴ���10λ������
*************************************************/
void Print::printQueue(queue<string> q, bool isExceed10)
{
    if (isExceed10)     // ������10λ�������ִ���Ϊ��
    {
        cout << "Input error !  Not exceeding 10 digits expected! " << endl;
        return ;
    }

    while (q.size())
    {
        cout << q.front() << endl;     // �������Ԫ��
        q.pop();     // ɾ������Ԫ��
    }
}