/************************************************************
    FileName: Print.cpp   
    Author: Jang
    Version : 1.0
    Date: 16/03/26
    Description:  ������еĹ���
     Function List: 1. void printQueue(queue<string> q, bool isExceed10): ��q������һ���
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
    Description: ����һ��string���У�������
    Input: squeue<string> q: ����Ҫ�����string����
	           bool isExceed10: ���ж϶������Ƿ���ڴ���10λ������
*************************************************/
void Print::printQueue(queue<string> q, bool isExceed10)
{
    if (isExceed10)     // ������10λ�������ִ���Ϊ��
    {
        cout << "\n�������Ӧ���벻����10λ�����֣�" << endl;
        cout << "Input error !  Not exceeding 10 digits expected! " << endl;
        return ;
    }

    while (q.size())
    {
        cout << q.front() << endl;     // �������Ԫ��
        q.pop();     // ɾ������Ԫ��
    }
}