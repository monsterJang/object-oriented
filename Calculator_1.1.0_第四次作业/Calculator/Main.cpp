/************************************************************
    FileName: Main.cpp   
    Author: Jang
    Version : 1.1.0
    Date: 16/03/26
    Description:  ��������Ŀ�ĳ�ʼ���֡�����һ������������ʽ������ַ�ɨ��������ʽ��
                       �����ֺͷ�����ȡ�������õ�һ��string�����������
    Function List: int main(): �����������������Ա��ʽ�����롢����ת�������
***********************************************************/ 

#include "Scan.h"
//#include "Print.h"     // ������
#include "Calculation.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*************************************************
    Description: ���ձ��ʽ�����벢��ֵ
    Input: int argc: �����в�������
              char *argv[] : ʵ�ʴ���������в���
    Ouput: ���ʽ������������
    Return: �������������򷵻�0
*************************************************/
int main(int argc, char *argv[])
{
    string input;
    if (!strcmp(argv[1], "-a"))     // �Դ���Ĳ���Ϊ"-a"�Ĵ���
    {
        input = argv[2];
    }
    else
    {
        input = argv[1];
    }

    Scan *sc = new Scan();
    Calculation *ca = new Calculation();

    // ����Scan���ToStringQueue�õ�string����
    queue<string> qu = sc->ToStringQueue(input);
    // ���������"-a"���򽫱��ʽ���
    if (strcmp(argv[1], "-a") == 0)
    {
        cout << input << "= ";
    }
    // ����Calculation���calculatingExpression�õ����ʽ������������
    ca->calculatingExpression(qu, sc->getIsExceed10());

    // ��������
    delete sc;
    sc = NULL;
    delete ca;
    ca = NULL;
//    system("pause");
    return 0;
}