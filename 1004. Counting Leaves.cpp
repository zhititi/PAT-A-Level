#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
	vector<int> child;
	int level;
}a[105];
int sum[105] ;//��¼���
int n, m;    //������n����Ҷ�ڵ�m��
int maxl = 0;
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int T = q.front();
		q.pop();
		if (a[T].child.size() == 0)  //���û������
		{
			sum[a[T].level]++;
			continue;
		}
		for (int i = 0; i < a[T].child.size(); i++)//������������
		{
			q.push(a[T].child[i]);
			a[a[T].child[i]].level = a[T].level + 1;
			if (a[T].level + 1 > maxl)
			{
				maxl = a[T].level + 1;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 0; i < m; i++)
	{
		int num, chi;  //num��ʾ˫�׽�㣬chiΪ���ӵĸ���
		scanf("%d%d", &num, &chi);//����д&����һ����Ѫ
		for (int j = 0; j < chi; j++)
		{
			scanf("%d", &x);   //����ÿ�����ӱ��
			a[num].child.push_back(x);
		}
	}

	a[1].level = 1;
	BFS(1);
	if (a[1].child.size() == 0)//��������ж������һ�����Ӷ�û��
	{
		printf("1\n");
		return 0;
	}
	for (int i = 1; i < maxl; i++)
	{
		printf("%d ", sum[i]);
	}
	printf("%d\n", sum[maxl]);
	return 0;
}