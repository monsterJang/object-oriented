#pragma once
#include <string>
#include <queue>

using namespace std;

class Scan
{
public:
	Scan(void);
	~Scan(void);
	queue<string> ToStringQueue(string input);
	void setIsExceed10(bool _isExceed10);
	bool getIsExceed10();
private:
	bool isExceed10;     // 记录是否有输入超过10位的数
};

