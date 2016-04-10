/************************************************************
    FileName: Scan.cpp   
    Author: Jang
    Version : 1.1.0
    Date: 2016.04.07
    Description:  ��string���ʽת��Ϊ������������ֿ���string����
    Function List:
	    1. void ToStringQueue(string input) : �õ�string ����
        2. void setIsExceed10(bool _isExceed10) : �ı�isExceed��ֵ
        3. bool getIsExceed10(): �õ�isExceed10
***********************************************************/ 

#include "Scan.h"
#define N 100

using namespace std;


Scan::Scan(void)
{
}


Scan::~Scan(void)
{
}


void Scan::setIsExceed10(bool _isExceed10)
{
	isExceed10 = _isExceed10;
}


bool Scan::getIsExceed10()
{
	return isExceed10;
}


/*************************************************
    Description: ����һ������������ʽ������ַ�ɨ��������ʽ��
                       �����ֺͷ�����ȡ�������õ�һ��string��������в�����
    Input: string input: �������������������ʽ
	Return:  q: �����õ���string����
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
    queue<string> q;     // q��Ϊ�����Ҫreturn�Ķ��У����ڱ���input���ʽ�е����ֺͷ���
    string res = "";     // resΪɨ��input���ʽʱ������ʱ�洢���ַ���
    string strArr[N];     // strArrΪɨ��input���ʽʱ���ڴ洢���ֺͷ��ŵ�string����
    int len = input.length();
    int cnt = 0;     // ��ΪstrArr���±��¼�������ȡ�����ֺͷ��ŵĸ���
    setIsExceed10(false);

    for (int i = 0; i < len; i++)
    {
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
        {
            res += input[i];     // �������ֻ� '.' ����ӵ���ʱ�洢��res�
            if (i == len - 1)     // �������ɨ��
            {
                strArr[cnt++] = res;
                break;
            }
            continue;     // �����ж���һԪ��
        }
        else
        {
			if (i == 0 && res.empty())     // ����һ��Ԫ��Ϊ��-��
			{
				res += input[i];
				continue;
			}
            if (!res.empty())     // res�ǿձ�ʾ��ʱres�л�����һ������ �� ��һ��Ԫ��Ϊ '-'
            {
                strArr[cnt++] = res;
            }
            res = "";     // res�ÿ�
            strArr[cnt++] = res + input[i];     // ���������ֻ� "." ��Ԫ�أ�������Ԫ�أ���ӵ�strArr��
        }
    }

    for (int i =0; i < cnt; i++)     // ��strArr�и���Ԫ����ӵ�q������
    {
        if (strArr[i].length() > 10)
        {
            setIsExceed10(true);     // ���ڴ���10λ��������
        }
        q.push(strArr[i]);
    }

    return q;
}