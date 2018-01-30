#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int N = 100010;
vector<int> G[N];//���ڱ�
bool isRoot[N];  //��¼ÿ������Ƿ���Ϊĳ�����ϵĸ����
int father[N];
//���鼯������P328
int findFather(int x) {       //����x���ڼ��ϵĸ����
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	//·��ѹ�����ɲ�д��������д�ˡ�
	while (a != father[x]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {   //�ϲ�a��b���ڵļ���
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
void init(int n) {        //���鼯��ʼ��
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
}
int calBlock(int n) {//������ͨ�����
	int Block = 0;
	for (int i = 1; i <= n; i++) {
		isRoot[findFather(i)] = true;  //i�ĸ������findFather[i]
	}
	for (int i = 1; i <= n; i++) {
		Block += isRoot[i];   //�ۼӸ�������
	}
	return Block;
}

int maxH = 0;//���߶�
vector<int> temp, Ans;//temp��ʱ���DFS����Զ�����Ans�����

//DFS������uΪ��ǰ���ʽڵ��ţ�HeightΪ��ǰ���ߣ�preΪu�ĸ��ڵ�

void DFS(int u, int Height, int pre) {
	if (Height > maxH) {       //�������˸��������
		temp.clear();          //���temp
		temp.push_back(u);     //����ǰ���u����temp��
		maxH = Height;         //��������߸���maxH
	}
	else if(Height == maxH) {  //������ߵ����������
		temp.push_back(u);     //����ǰ������temp��
	}
	for (int i = 0; i < G[u].size(); i++) { //����u�������ӽ��
		if (G[u][i] == pre) continue;  //��Ϊ���ڱ��д������ͼ�������Ҫ������ȥ�ı�
		DFS(G[u][i], Height + 1, u);  //�����ӽ��
	}
}
int main() {
	int a, b, n;
	scanf("%d", &n);
	init(n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a, b);
	}
	int Block = calBlock(n);//���㼯����Ŀ
	if (Block != 1) {       //��ֹһ����ͨ��
		printf("Error: %d components\n", Block);
	}
	else {
		DFS(1, 1, -1);      //��1�Ž�㿪ʼDFS����ʼ�߶�Ϊ1
		Ans = temp;         //tempΪ����A������Ans��temp�д洢�Ĵ�1�Ž���ܵ�������Ľ�㼯��
		DFS(Ans[0], 1, -1); //������һ����㿪ʼ����
		for (int i = 0; i < temp.size(); i++) {
			Ans.push_back(temp[i]);    //��ʱtempΪ����B������ӵ�Ans��
		}
		sort(Ans.begin(), Ans.end());  //����Ŵ�С��������
		printf("%d\n", Ans[0]);
		for (int i = 1; i < Ans.size(); i++) {
			if (Ans[i] != Ans[i - 1]) {//�ظ���Ų����
				printf("%d\n", Ans[i]);
			}
		}
	}
	return 0;
}