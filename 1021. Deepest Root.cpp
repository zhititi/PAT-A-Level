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
vector<int> G[N];//接邻表
bool isRoot[N];  //记录每个结点是否作为某个集合的根结点
int father[N];
//并查集，见书P328
int findFather(int x) {       //查找x所在集合的根结点
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	//路径压缩（可不写），但是写了。
	while (a != father[x]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {   //合并a和b所在的集合
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
void init(int n) {        //并查集初始化
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
}
int calBlock(int n) {//计算连通块个数
	int Block = 0;
	for (int i = 1; i <= n; i++) {
		isRoot[findFather(i)] = true;  //i的根结点是findFather[i]
	}
	for (int i = 1; i <= n; i++) {
		Block += isRoot[i];   //累加根结点个数
	}
	return Block;
}

int maxH = 0;//最大高度
vector<int> temp, Ans;//temp临时存放DFS的最远结果，Ans保存答案

//DFS函数，u为当前访问节点编号，Height为当前树高，pre为u的父节点

void DFS(int u, int Height, int pre) {
	if (Height > maxH) {       //如果获得了更大的树高
		temp.clear();          //清空temp
		temp.push_back(u);     //将当前结点u加入temp中
		maxH = Height;         //将最大树高赋给maxH
	}
	else if(Height == maxH) {  //如果树高等于最大树高
		temp.push_back(u);     //将当前结点加入temp中
	}
	for (int i = 0; i < G[u].size(); i++) { //遍历u的所有子结点
		if (G[u][i] == pre) continue;  //因为接邻表中存放无向图，因此需要跳过回去的边
		DFS(G[u][i], Height + 1, u);  //访问子结点
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
	int Block = calBlock(n);//计算集合数目
	if (Block != 1) {       //不止一个连通块
		printf("Error: %d components\n", Block);
	}
	else {
		DFS(1, 1, -1);      //从1号结点开始DFS，初始高度为1
		Ans = temp;         //temp为集合A，赋给Ans，temp中存储的从1号结点能到达最深的结点集合
		DFS(Ans[0], 1, -1); //从任意一个结点开始遍历
		for (int i = 0; i < temp.size(); i++) {
			Ans.push_back(temp[i]);    //此时temp为集合B，将其加到Ans中
		}
		sort(Ans.begin(), Ans.end());  //按编号从小到大排序
		printf("%d\n", Ans[0]);
		for (int i = 1; i < Ans.size(); i++) {
			if (Ans[i] != Ans[i - 1]) {//重复编号不输出
				printf("%d\n", Ans[i]);
			}
		}
	}
	return 0;
}