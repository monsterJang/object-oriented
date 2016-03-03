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
	if(isExceed10)     // 若超过10位数的数字存在为真
	{
		cout << "\n输入错误！应输入不超过10位的数字！" << endl;
		cout << "Input error !  Not exceeding 10 digits expected! " << endl;
		return ;
	}
	while(q.size())
	{
		cout << q.front() << endl;     // 输入队首元素
		q.pop();     // 删除队首元素
	}
}