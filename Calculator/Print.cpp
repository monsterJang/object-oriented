#include "Print.h"
#include <iostream>

Print::Print(void)
{
}


Print::~Print(void)
{
}

void Print::printQueue(queue<string> q, bool isExceed10)
{
	if(isExceed10)     // ������10λ�������ִ���Ϊ��
	{
		cout << "\n�������Ӧ���벻����10λ�����֣�" << endl;
		cout << "Input error !  Not exceeding 10 digits expected! " << endl;
		return ;
	}
	while(q.size())
	{
		cout << q.front() << endl;     // �������Ԫ��
		q.pop();     // ɾ������Ԫ��
	}
}