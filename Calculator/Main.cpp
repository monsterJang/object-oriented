#include <iostream>
#include <string>
#include "Scan.h"
#include "Print.h"

using namespace std;

int main()
{
	// 提示信息
	cout << "请输入四则运算表达式：" << endl;
	cout << "please input the arithmetic expression:\n" << endl;
	string input;
	// 接受用户输入
	cin >> input;
	Scan *sc = new Scan();
	Print *pr = new Print();
	// 调用Scan类的ToStringQueue得到string队列
	queue<string> qu = sc->ToStringQueue(input);
	// 输出该队列
	pr->printQueue(qu, sc->getIsExceed10());
	// 对象销毁
	delete sc;
	sc = NULL;
	delete pr;
	pr = NULL;
	system("pause");
	return 0;
}