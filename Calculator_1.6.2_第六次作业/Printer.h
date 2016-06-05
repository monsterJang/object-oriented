#ifndef PRINTER_H
#define PRINTER_H

#include <string>
#include <queue>
#include "Scanner.h"
#include "Calculation.h"

using namespace std;

class Printer
{
public:
    Printer(void);
    ~Printer(void);
    //virtual void printResult() = 0;
    void printError();
    double printResult(string input);
    void printResult_a(string input);
    void printResult_f(string inputAddr, string outputAddr);
    void printQueue(queue<string> q, bool isExceedMaxNumLen);
private:
    Scanner *sc;
    Calculation *ca;
};

#endif // PRINTER_H
