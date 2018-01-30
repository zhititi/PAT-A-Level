#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;
int Cmax, N, Sp, M;
int G[505][505];
int value[505];
bool vis[505];
int d[505], w[505], w1[505];
vector<int> path[505], path1[505];
//path1应选车之和>需要且最接近的路线
void dijsktra(int root) {//  path选出车之和>需要且最接近的路线
	fill(d, d + 505, INF);
	path[root].push_back(0);
	path1[root].push_back(0);
	d[root] = 0;
	w[root] = value[root];
	w1[root] = value[root];
	for (int i = 0; i <= N; i++) {
		int u = -1, min = INF;
		for (int j = 0; j <= N; j++) {
			if (vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		//cout << u << endl;
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v <= N; v++) {
			if (vis[v] == false && G[u][v] != 0) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + value[v];
					w1[v] = w1[u] + value[v];
					path[v] = path[u];
					path[v].push_back(v);
					path1[v] = path1[u];
					path1[v].push_back(v);
				}
				else if (d[v] == d[u] + G[u][v]) {  //w[v] <= (path[v].size() - 1) * Cmax / 2 可以 w[v] - (path[v].size() - 1) * Cmax / 2 <= 0 不行
					if (w[v] <= (path[v].size() - 1) * Cmax / 2 && w[u] + value[v] <= (path[v].size() - 1) * Cmax / 2 && w[v] < w[u] + value[v]) {  //应送车，且送最少的车
						w[v] = w[u] + value[v];
						path[v] = path[u];
						path[v].push_back(v);
					}
					if (w1[v] >= (path1[v].size() - 1) * Cmax / 2 && w1[u] + value[v] >= (path1[v].size() - 1) * Cmax / 2 && w1[v] > w1[u] + value[v]) { //车多出来了
						w1[v] = w1[u] + value[v];
						path1[v] = path1[u];
						path1[v].push_back(v);
					}
				}
			}
		}
	}
}

int main() {
	cin >> Cmax >> N >> Sp >> M;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
	}
	for (int i = 0; i < M; i++) {
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		G[a1][a2] = G[a2][a1] = a3;
	}
	dijsktra(0);
	int s = (path[Sp].size() - 1) * Cmax/2 - w[Sp];
	if (s > 0) {         //就选对了，应送车过去，优先送车
		cout << s << ' ' << 0;
		for (int i = 1; i < path[Sp].size(); i++) {
			printf("->%d", path[Sp][i]);
		}
		cout << ' ' << 0;
	}
	else {//应收车
		s = w1[Sp] - (path[Sp].size() - 1) * Cmax / 2;
		cout << 0 << ' ' << 0;
		for (int i = 1; i < path1[Sp].size(); i++) {
			printf("->%d", path1[Sp][i]);
		}
		cout << ' ' << s;
	}
}
/*
10 3 3 5
6 7 10
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
*/