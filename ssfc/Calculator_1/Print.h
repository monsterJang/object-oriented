#pragma once
#include <string>
#include <queue>

using namespace std;

class Print
{
public:
	Print(void);
	~Print(void);
	void printQueue(queue<string> q, bool isExceed10);
};

