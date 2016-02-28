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
	bool isExceed10;     // ��¼�Ƿ������볬��10λ����
};

