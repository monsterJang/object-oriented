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

queue<string> Scan::ToStringQueue(string input)
{
	queue<string> q;     // q��Ϊ�����Ҫreturn�Ķ��У����ڱ���input���ʽ�е����ֺͷ���
	string res = "";     // resΪɨ��input���ʽʱ������ʱ�洢���ַ���
	string strArr[N];     // strArrΪɨ��input���ʽʱ���ڴ洢���ֺͷ��ŵ�string����
	int len = input.length();
	int cnt = 0;     // ��ΪstrArr���±��¼�������ȡ�����ֺͷ��ŵĸ���
	setIsExceed10(false);
	for(int i = 0; i < len; i++)
	{
		if((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
		{
			res += input[i];     // �������ֻ� '.' ����ӵ���ʱ�洢��res�
			if(i == len - 1)     // �������ɨ��
			{
				strArr[cnt++] = res;
				break;
			}
			continue;     // �����ж���һԪ��
		}
		else
		{
			if(!res.empty())     // res�ǿձ�ʾ��ʱres�л�����һ������
			{
				strArr[cnt++] = res;
			}
			res = "";     // res�ÿ�
			strArr[cnt++] = res + input[i];     // ���������ֻ� "." ��Ԫ�أ�������Ԫ�أ���ӵ�strArr��
		}
	}
	for(int i =0; i < cnt; i++)     // ��strArr�и���Ԫ����ӵ�q������
	{
		if(strArr[i].length() > 10)
		{
			setIsExceed10(true);     // ���ڴ���10λ��������
		}
		q.push(strArr[i]);
	}
	return q;
}