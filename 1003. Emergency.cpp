#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;   //常量最好用大写
const int MAXV = 510;         //尽量不要定义max这样的变量
int d[MAXV] ; int num[MAXV] ; int w[MAXV] ;//d[]记录最短路径，num[]记录最短路径个数，w[]记录最大点权之和
int G[MAXV][MAXV];            //他妈的，这种初始化方式有问题。。int d[510] = { inf }; int num[510] = { 0 }; int w[510] = { 0 }只定义了下标为0的那个。。
int wei[MAXV] ;
bool vis[MAXV] = { false };//这样就可以。vis[]记录是否访问过。
int C1, C2, N, M;//起点C1，终点C2，N个顶点，M个边

//最短路径问题的DFS算法，不能形成三角（vis不好用，因为要重复访问一些结点）、过河拆桥（重复访问无法做到）的矛盾。
//DFS适合与图的遍历，访问所有的边，所有的点，不适合寻找最短路径。

void Dijsktra(int s) {
	fill(d, d + 510, INF);
	/*fill(w, w + 510, 0);
	fill(num, num + 510, 0);*/  //全局变量定义以后初值都为0，所以没必要
	d[s] = 0;
	num[s] = 1;
	w[s] = wei[s];
	for (int i = 0; i < N; i++) {//找出d[]最小的结点
		int u = -1, min = INF;
		for (int j = 0; j < N; j++){
			if (d[j] < min && vis[j] == false) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;     //标记已访问
		for (int v = 0; v < N; v++){
			if (vis[v] == false && G[v][u] != 0){
				if (d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + wei[v];
					num[v] = num[u];
				}
				else if (d[u] + G[u][v] == d[v]){
					if (w[v] < w[u] + wei[v]){
						w[v] = w[u] + wei[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
bool in[MAXV] = { false }; //记录是否在队列里

void SPFA(int s){ //找不出哪里错了。很奇怪。
	fill(d, d + 510, INF);
	queue<int> q;
	q.push(s);
	in[s] = true;
	d[s] = 0;
	num[s] = 1;     //num[]记录最短路径个数
	w[s] = wei[s];
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		in[u] = false;
		for (int v = 0; v < N; v++)//所有结点，找出与u相连的结点
		{
			if (G[u][v] != 0 && d[u] + G[u][v] <= d[v])//u与v连通且可松弛or路径相等，或者有相同的最短路径统计数量
			{
				if (d[u] + G[u][v] < d[v])//可松弛
				{
					d[v] = d[u] + G[u][v];//这里，不管v是否在队列里，都要进行松弛操作。在队列里的话，由其检查其后面的路径，并不影响对其本身的松弛。
					num[v] = num[u];
					w[v] = w[u] + wei[v];
					if (in[v] == false) {//我可去你妈的吧，总忘了是双等号。v不在队列中时做如下操作
						q.push(v);
						in[v] = true;   //置v在队列中
					}
				}
				else if (d[u] + G[u][v] == d[v])//眼瞎了吧。路径相等的情况
				{
					num[v] += num[u];    //卧槽！！！这里应该从num[u]处继承过来。。哭死。。
					if (w[v] < w[u] + wei[v])
						w[v] = w[u] + wei[v];
				}
			}
		}
	}
}
int main()
{
	fill(G[0], G[0] + MAXV * MAXV, 0);//注意二维数组初始化的方式：G[0]。。其实这个也不必要，因为是全局变量。
	//fill(wei, wei + MAXV, 0);不必要。
	scanf("%d%d%d%d", &N, &M, &C1, &C2);//输入格式%d之间不需要逗号
	for (int i = 0; i < N; i++){
		scanf("%d", &wei[i]);
	}
	int c1, c2, l;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &c1, &c2, &l);
		G[c1][c2] = G[c2][c1] = l;
	}
	//Dijsktra(C1);
	SPFA(C1);
	printf("%d %d", num[C2], w[C2]);
}
//全局变量一旦定义便初始值为0。包括bool，int等等。
//函数中定义的数组不经初始化均为某特定值，函数中的数组定义以后经{ }初始化只改便第一个元素的值，后面的都为0，所以只可用{ }初始化为0。
//bool型变量，true为1，false为0，只可用{ }初始化为0。
/*5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1*/