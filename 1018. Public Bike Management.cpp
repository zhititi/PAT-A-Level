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
int value[505];  //记录原有车数
bool vis[505];  //记录已确定的
int d[505], w[505], w1[505];  //d[]记录最短距离，w[]最短距离路上多出的车数（为负数说明缺少）
vector<int> path[505], path1[505];  //记录每一个地方的最佳路线
//path1应选车之和>需要且最接近的路线

int count(int index, int &s, int &b) {  //数一条路径上需要送，收各多少辆车
    vector<int> need;
    need.push_back(0);
    int min = 0;
    for (int i = 1; i < path[index].size(); i++){
        need[path[index][i]] = value[path[index][i]] + need[path[index][i - 1]] - Cmax / 2;
        //cout<<need[path[index][i]]<<endl;
        if(need[path[index][i]] < min) {
            min = need[path[index][i]];
        }
    }
    s = abs(min);
    b = w[Sp] + s - (path[Sp].size() - 1) * Cmax / 2;
    if(b < 0) {
        b = 0;
    }
    return 0;
}

void dijsktra(int root) {//  path选出车之和>需要且最接近的路线
    fill(d, d + 505, INF);
    path[root].push_back(0);
    path1[root].push_back(0);
    d[root] = 0;
    w[root] = value[root];
    w1[root] = value[root];
    for (int i = 0; i <= N; i++){
        int u = -1, min = INF;
        for (int j = 0; j <= N; j++){
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        //cout << u << endl;
        if(u == -1) return;
        vis[u] = true;
        for (int v = 0; v <= N; v++){
            if(vis[v] == false && G[u][v] != 0) {  //与正在访问结点相邻的，且没有被确定的
                if(d[v] > d[u] + G[u][v]) {  //通过u再到该结点有更小距离，则更新d[v]
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + value[v];
                    w1[v] = w1[u] + value[v];
                    path[v] = path[u];
                    path[v].push_back(v);
                    path1[v] = path1[u];
                    path1[v].push_back(v);
                } else if(d[v] == d[u] +
                                  G[u][v]) {  //w[v] <= (path[v].size() - 1) * Cmax / 2 可以 w[v] - (path[v].size() - 1) * Cmax / 2 <= 0 不行
                    if(w[v] <= (path[v].size() - 1) * Cmax / 2 && w[u] + value[v] <= (path[v].size() - 1) * Cmax / 2 &&
                       w[v] < w[u] + value[v]) {  //应送车，且送最少的车
                        w[v] = w[u] + value[v];
                        path[v] = path[u];
                        path[v].push_back(v);
                    }
                    if(w1[v] >= (path1[v].size() - 1) * Cmax / 2 &&
                       w1[u] + value[v] >= (path1[v].size() - 1) * Cmax / 2 && w1[v] > w1[u] + value[v]) { //车多出来了
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
    for (int i = 1; i <= N; i++){
        cin >> value[i];
    }
    for (int i = 0; i < M; i++){
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        G[a1][a2] = G[a2][a1] = a3;
    }
    dijsktra(0);
    int s = 0;  //送
    int b = 0;  //收
    count(Sp, s, b);
    cout << s << ' ' << 0;
    for (int i = 1; i < path[Sp].size(); i++){
        printf("->%d", path[Sp][i]);
    }
    cout << ' ' << b;
    return 0;
}
