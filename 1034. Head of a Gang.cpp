#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;
map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//接邻矩阵G，点权weight
int n, k, numPerson = 0;//边数n，下限k，总人数numPerson
bool vis[maxn] = { false };//标记是否有被访问

//DFS函数访问单个连通块，nowVisit为当前访问编号
//head为头目，numMember为成员编号，totalValue为连通块总边权
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) //图的递归遍历算法
{
	numMember++;
	vis[nowVisit] = true;//已访问
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++) {//每个人都判断
		if (G[nowVisit][i] > 0) {//之间存在通话
			totalValue += G[nowVisit][i];       //总电话时间++
			G[nowVisit][i] = G[i][nowVisit] = 0;//置0，防止重复遍历边，因为此时没有判断vis[]
			if (vis[i] == false) {  
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}
//DFS1这种写法是错误的，因为有时可能成环时，两个节点之间存在未遍历的边，但目标结点已经被访问过。
void DFS1(int nowVisit, int& head, int& numMember, int& totalValue) 
{
	numMember++;
	vis[nowVisit] = true;//已访问
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++) {
		if (G[nowVisit][i] > 0 && vis[i]==false) {//之间存在通话且另一个没被访问过。
			totalValue += G[nowVisit][i];
			DFS1(i, head, numMember, totalValue);
		}
	}
}
//哈哈哈，我自己写的BFS，看来这个没有必要用DFS做
void BFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
	queue<int> q;
	q.push(nowVisit);
	vis[nowVisit] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		numMember++;
		if (weight[now] > weight[head]) {
			head = now;
		}
		for (int i = 0; i < numPerson; i++) {
			if (G[i][now] > 0){
				totalValue += G[now][i];
				G[now][i] = G[i][now] = 0;
				if (vis[i] == false) {  //这一步很必要，否则会回头遍历，numMember会错。卧槽，这个等号。。。
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}
}
//DFSTrave遍历整个图，获取每个连通块的信息
void DFSTrave()
{
	for (int i = 0; i < numPerson; i++) {//每个结点
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;// 头目 = i, 团队人数 = 0, 总通话时间 = 0
			BFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k) { //人数大于2个，且总通话时间大于k
				Gang[intToString[head]] = numMember;//Gang的容器中的key为犯罪团伙，value为犯罪团伙的人数
			}
		}
	}
}
//change返回姓名str所对应的编号
int change(string str) {
	if (stringToInt.find(str) != stringToInt.end()) //map容器中find的用法：失配时返回map.end()
	{
		return stringToInt[str];
	}
	else {//失配，没找到
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}
int main(){
	int w;
	string str1,str2;
	cin >> n >> k;  //n is the number of phone calls, k is the weight threshold.
	for (int i = 0; i < n; i++) { //输入环节
		cin >> str1 >> str2 >> w;//两个端点，以及通话时间
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << ' ' << it->second << endl; //用it->first来访问键，it->second来访问值
	}
	return 0;
}
/*
遍历所有结点，不用过河拆桥，只用vis数组标记已访问
遍历所有结点所有边，需要过河拆桥，也需要用vis数组标记已访问
两者的不同
*/
