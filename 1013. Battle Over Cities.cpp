#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int G[1005][1005];//接邻矩阵
int check[1005];
bool vis[1005] = { false };//表示是否访问过
int n, m, sum;//n为城市数，m为路径数，sum为需要查找的个数
void manage(int num) {
	vis[num] = true;
	for (int i = 1; i < n + 1; i++) {//这里i是序号
		if (vis[i] == false && G[num][i] != 0) {//这里只是要统计连通块的个数，所以可以这样写，若是要遍历所有边，则参考以下代码
			manage(i);
		}
	}
	return;
}
/*for (int i = 0; i < n; i++) {   //每结点都判断
	if (G[num][i] > 0) {          //之间存在边
		totalValue += G[num][i];       //总电话时间++（处理）
		G[num][i] = G[i][num] = 0;    //置0，防止重复遍历边，因为此时没有判断vis[]
		if (vis[i] == false) { 
			DFS(i);
		}
	}
}*/
int main() 
{
	cin >> n >> m >> sum;
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		scanf("%d%d", &temp1, &temp2);
		G[temp1][temp2] = G[temp2][temp1] = 1;
	}
	for (int i = 0; i < sum; i++) {
		scanf("%d", &check[i]);//check[]里面记录是下标
	}
	for (int i = 0; i < sum; i++) {//对于每一个待处理的结点
		int count = 0;//count记录非连通的片的个数
		vis[check[i]] = true;
		for (int j = 1; j < n + 1; j++) {//每个结点
			if (vis[j] == false) {
				manage(j);//manage遍历与一个结点连接的一个连通片，将其中所有元素的vis置true
				count++;
			}
		}
		printf("%d\n", count - 1);
//		vis[1005] = { false };不能这样。
		for (int j = 0; j < n + 1; j++) {
			vis[j] = false;
		}
	}
}
/*图的遍历中，相似的是，设计一个每个结点的循环，以及标记结点是否被访问过的vis数组(vis==false)。每次若结点未被访问则进入处
理环节，DFS（递归实现）或BFS（用队列）遍历与该结点相连的所有结点，将其vis设为true，或根据要求加以处理(是否需要遍历所有边
会导致写法不同)。*/