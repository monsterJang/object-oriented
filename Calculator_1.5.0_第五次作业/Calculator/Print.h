#pragma once
#include <string>
#include <queue>
#include "Scan.h"
#include "Calculation.h"

using namespace std;

class Print
{
public:
    Print(void);
    ~Print(void);
    void printError();
    void printResult(string input);
    void printResult_a(string input);
    void printResult_f(string inputAddr, string outputAddr);
    void printQueue(queue<string> q, bool isExceed10);
private:
    Scan *sc;
    Calculation *ca;
};

