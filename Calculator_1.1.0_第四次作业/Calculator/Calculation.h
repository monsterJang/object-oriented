#pragma once
#include <string>
#include <queue>
#include <stack>

using namespace std;

const int SIZE = 250;     // 表达式的最大长度（即q.size() <= SIZE)

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
    int priority[128];     // 存储运算符的优先级
    stack<string> cacheStack;     // 缓存栈
    stack<string> digitStack;     // 数字栈，包括处理与运算过程
    stack<string> operatorStack;     // 操作符栈，包括"+", "-", "*", "/", "(", ")"
};

