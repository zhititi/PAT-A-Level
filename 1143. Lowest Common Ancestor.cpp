#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
int m, n;
int pre[10010], in[10010];
bool hashTable[10010];
struct Node{
	int father;
	int lchild,rchild;
}node[10010];//二叉树的静态存储方式

int create(int prel, int prer, int inl, int inr) {//先序，中序序列建树
	if (prel > prer) {
		return -1;
	}
	int k;
	for (k = 0; k < n; k++) {
		if (in[k] == pre[prel]) break;
	}
	int root = in[k];
	int numleft = k - inl;
	node[root].lchild = create(prel + 1, prel + numleft, inl, k - 1);
	node[root].rchild = create(prel + numleft + 1, prer, k + 1, inr);
	return root;
}

void DFS(int root, int pre) { //为树中每个结点设置先驱
	if (root == -1) return;
	node[root].father = pre;
	DFS(node[root].lchild, root);
	DFS(node[root].rchild, root);
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
		in[i] = pre[i];
	}
	sort(in, in + n);
	int root = create(0, n - 1, 0, n - 1);
	DFS(root, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		if ((a < 1) || (a > n) || (b < 1) || (b > n)) {//有问题
			if (((a < 1) || (a > n)) && ((b < 1) || (b > n))) {
				printf("ERROR: %d and %d are not found.\n", a, b);
			}
			else if ((a < 1) || (a > n)) {
				printf("ERROR: %d is not found.\n", a);
			}
			else {
				printf("ERROR: %d is not found.\n", b);
			}
		}

		else {
			fill(hashTable, hashTable + n + 1, false);//忘了初始化
			int temp = a;
			while (temp != -1) {
				hashTable[temp] = true;
				temp = node[temp].father;
			}
			temp = b;
			while (hashTable[temp] == false) {
				temp = node[temp].father;
			}
			if (temp == a) {
				printf("%d is an ancestor of %d.\n", a, b);
			}
			else if (temp == b) {
				printf("%d is an ancestor of %d.\n", b, a);
			}
			else {
				printf("LCA of %d and %d is %d.\n", a, b, temp);
			}
		}
	}
	return 0;
}
/*
10 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
7 8
3 2
6 7
5 4
*/