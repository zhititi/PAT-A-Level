#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef struct {
	int data;
	vector<int> next;
}G;
G x[10000];
int path[10000];
int sum, n;
void DFS(int down, int index, int s) {
	path[index++] = x[down].data;
	s += x[down].data;
	if (s > sum)
		return;
	if (s == sum) {
		if (x[down].next.size() == 0)
		{
			for (int i = 0; i < index - 1; i++)
			{
				printf("%d ", path[i]);
			}
			printf("%d\n", path[index - 1]);
			return;
		}
		else return;
	}
	if (x[down].next.size() == 0) {
		return;
	}
	for (int i = 0; i < x[down].next.size(); i++)
	{
		DFS(x[down].next[i], index, s);
	}
	return;
}
bool cmp(int A, int B) {//A和B分别是next数组里面是的元素，目的是按next数组元素所指的结点data值从大到小将next数组排序
	return x[A].data > x[B].data;
}
int main()
{
	int a;//a为非叶节点个数
	scanf("%d%d%d", &n, &a, &sum);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i].data);
	}
	int son, num, h;
	for (int i = 0; i < a; i++) {
		scanf("%d%d", &son, &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &h);//????????????????????????&
			x[son].next.push_back(h);
		}
		sort(x[son].next.begin(), x[son].next.end(), cmp);//按next数组元素所指的结点的数据域从大到小排序
	}
	DFS(0, 0, 0);
}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
/*

*/