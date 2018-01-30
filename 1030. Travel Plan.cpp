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
int n, m, S, D;
/*where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); 
M is the number of highways; S and D are the starting and the destination cities, respectively.*/
int G[505][505], cost[505][505];
int d[505], w[505];
bool vis[505];
vector<int> path[505];
void dijsktra(int start) {//  path选出车之和>需要且最接近的路线
	fill(d, d + 505, INF);
	d[start] = 0;
	path[start].push_back(start);
	for (int i = 0; i <= n; i++) {
		int u = -1, min = INF;
		for (int j = 0; j <= n; j++) {
			if (vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v <= n; v++) {
			if (vis[v] == false && G[u][v] != 0) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + cost[u][v];
					path[v] = path[u];
					path[v].push_back(v);
				}
				else if (d[v] == d[u] + G[u][v]) {
					if (w[v] > w[u] + cost[u][v]) {
						w[v] = w[u] + cost[u][v];
						path[v] = path[u];
						path[v].push_back(v);
					}
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> S >> D;
	for (int i = 0; i < m; i++) {
		int a, b, dis, c;
		cin >> a >> b >> dis >> c;
		G[a][b] = G[b][a] = dis;
		cost[a][b] = cost[b][a] = c;
	}
	dijsktra(S);
	int totald = 0, totalc = 0;
	for (int i = 0; i < path[D].size(); i++) {
		if (i > 0) {
			totald += G[path[D][i - 1]][path[D][i]];
			totalc += cost[path[D][i]][path[D][i - 1]];
		}
		printf("%d ", path[D][i]);
	}
	printf("%d %d\n", totald, totalc);
	return 0;
}