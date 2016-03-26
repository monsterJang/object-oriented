/************************************************************
    FileName: Main.cpp   
    Author: Jang
    Version : 1.0
    Date: 16/03/26
    Description:  ��������Ŀ�ĳ�ʼ���֡�����һ������������ʽ������ַ�ɨ��������ʽ��
                       �����ֺͷ�����ȡ�������õ�һ��string�����������
    Function List: int main(): �����������������Ա��ʽ�����롢����ת�������
***********************************************************/ 

#include <iostream>
#include <string>
#include "Scan.h"
#include "Print.h"

using namespace std;

int main()
{
    // ��ʾ��Ϣ
    cout << "����������������ʽ��" << endl;
    cout << "please input the arithmetic expression:\n" << endl;
    string input;
    // �����û�����
    cin >> input;
    Scan *sc = new Scan();
    Print *pr = new Print();
    // ����Scan���ToStringQueue�õ�string����
    queue<string> qu = sc->ToStringQueue(input);
    // ����ö���
    pr->printQueue(qu, sc->getIsExceed10());
    // ��������
    delete sc;
    sc = NULL;
    delete pr;
    pr = NULL;
    system("pause");
    return 0;
}