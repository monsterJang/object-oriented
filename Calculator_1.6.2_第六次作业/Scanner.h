#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <queue>
#include <fstream>

using namespace std;

class Scanner
{
public:
    Scanner(void);
    ~Scanner(void);
    queue<string> ToStringQueue(string input);
    void setIsExceedMaxNumLen(bool _isExceedMaxNumLen);
    bool getIsExceedMaxNumLen();
private:
    bool isExceedMaxNumLen;     // 记录是否有输入超过MaxNumLen位的数
};

#endif // SCANNER_H
