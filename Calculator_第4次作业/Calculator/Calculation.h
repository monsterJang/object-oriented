#pragma once
#include <string>
#include <queue>
#include <stack>

using namespace std;

const int SIZE = 250;     // ���ʽ����󳤶ȣ���q.size() <= SIZE)

class Calculation
{
public:
    Calculation(void);
    ~Calculation(void);
    void setPriorityLevel();
    bool isOperator(string s);
    bool isDigit(string s);
	void toPostfixExpression(queue<string> q);
    void calculatingExpression(queue<string> q, bool is_Exceed10);
public:
    int priority[128];     // �洢����������ȼ�
    stack<string> cacheStack;     // ����ջ
    stack<string> digitStack;     // ����ջ�������������������
    stack<string> operatorStack;     // ������ջ������"+", "-", "*", "/", "(", ")"
};

