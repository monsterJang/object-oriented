/************************************************************
    FileName: Main.cpp   
    Author: Jang
    Version : 1.5.0
    Date: 2016.05.09
    Description:  ��������Ŀ�ĳ�ʼ���ֵĸĽ�����֮ǰ����һ������������ʽ��������ʽ��ֵ�Ļ����ϣ�
                          �����˶��ļ��Ķ�д����
    Function List: int main(): �����������������Ա��ʽ�����롢����ת�������
    Compare to previous vision:
	    1.���������ļ���д�������Print��ʵ��
        2.��Scan���Calculation���ʵ������Print��Ĺ��캯���г�ʼ���������������ͷ�~
***********************************************************/ 

#include "Print.h"
#include <iostream>
#include <cstring>

using namespace std;

/*************************************************
    Description: ���ձ��ʽ�����벢��ֵ
    Input: int argc: �����в�������
              char *argv[] : ʵ�ʴ���������в���
    Return: �������������򷵻�0
*************************************************/
int main(int argc, char *argv[])
{
	Print *pr = new Print();
    if (argc == 2)     // �Դ���Ĳ���ֻ�б��ʽ�Ĵ�������Print���Ӧ��PrintResult�������
	{
		pr->printResult(argv[1]);
	}
    else if (!strcmp(argv[1], "-a") && argc == 3)     // �Դ���Ĳ���Ϊ"-a"�Ĵ�������Print���Ӧ��PrintResult_a�������
    {
		pr->printResult_a(argv[2]);
    }
    else if (!strcmp(argv[1], "-f") && argc == 4)     // �Դ���Ĳ���Ϊ"-f"�Ĵ�������Print���Ӧ��PrintResult_f�������
    {
		pr->printResult_f(argv[2], argv[3]);
    }
	else
	{
		cout << "Input error!" << endl;
	}

//   system("pause");
    return 0;
}