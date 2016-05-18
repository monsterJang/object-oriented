#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct List
{
	int addr;
	int nextAddr;
	int data;
	List* next;
};

int inputData[100005];
int inputNext[100005];

List* reHead = NULL;

// head
List* reserveHead(List* head, int k)
{
	List* p = NULL;
	List* q = NULL;
	List* r = NULL;
	
	p = head;
	q = p->next;
	for(int i = 1; i < k; i++) // 每次循环：p->q->r 变为 p<-q<-r
	{
		r = q->next;
		q->next = p;
		
		q->nextAddr = p->addr;
		
		if(i == k - 1)
		{
			reHead = q;
			break;
		}
		
		p = q;
		q = r;
		
	}
	p = head;
	head->next = r;
	head->nextAddr = (r == NULL? -1 : r->addr);
	
	return p;
}

// reserve 中
List* reserveMedi(List* flag, int k)
{
	List* p = NULL;
	List* q = NULL;
	List* r = NULL;
	List* first = flag->next;
	
	p = flag->next;
	q = p->next;
	for(int i = 1; i < k; i++)
	{
		r = q->next;
		q->next = p;
		
		q->nextAddr = p->addr;
		
		if(i == k - 1)
		{
			break;
		}
		
		p = q;
		q = r;
		
	}
	
	flag->next = q;
	flag->nextAddr = q->addr;
	first->next = r;
	first->nextAddr = r == NULL ? -1 : r->addr;
	
	return first;
} 

int main()
{
	int x, y, z, i, j;
	int init, n, k, temp;
	
	scanf("%d %d %d", &init, &n, &k);
	int initAddr = init;
	
	List* head = NULL;
	List* flag = NULL;
	List* p = NULL;
	List* p1 = NULL;
	
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		
		if (x == -1)
		{
			continue;
		}
	
		inputData[x] = y;
		inputNext[x] = z;
		if(z == -1)
		{
			temp = y;
		}
	}
	
	// 输入
	int len = 0;
	while(init != -1)
	{
		p = (List *)malloc(sizeof(struct List));
		p->addr = init;
		p->data = inputData[init];
		p->nextAddr = inputNext[init];
		p->next = NULL;
		
		init = inputNext[init];
		if(len == 0)
		{
			head = p;
		}
		else
		{
			p1->next = p;
		}
		p1 = p;
		len++;
		
		if (len == n)
		{
			p1->nextAddr = -1;
			break;
		}
	}
	p1->next = NULL;
	
	// 反转
	for(i = 0; i < len / k; i++)
	{
		if (n == 1 || k == 1)
		{
			break;
		}
		
		if(i == 0)
		{
			flag = reserveHead(head, k);
			head = reHead;
		}
		else
		{
			flag = reserveMedi(flag, k);
		}
	} 
	
	// 测试输出 
	p = head;
	while(p->next != NULL)
	{
		printf("%05d %d %05d\n", p->addr, p->data, p->nextAddr);
		p = p->next;
	}
	printf("%05d %d -1\n", p->addr, p->data);
	
	return 0;
}
/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

1 20 1
1 1 2
2 2 3
3 3 4
4 4 5
5 5 6
6 6 7
7 7 8
8 8 9
9 9 10
10 10 11
11 11 12
12 12 13
13 13 14
14 14 15
15 15 16
16 16 17
17 17 18
18 18 19
19 19 20
20 20 -1

*/
