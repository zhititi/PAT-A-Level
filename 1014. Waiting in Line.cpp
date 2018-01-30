#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
queue<int> q[20];//窗口数，下标0-19
int N, M, K, Q;//N个窗口，黄线内最多M个人，总共K个人，有Q个人问时间
int processTime[1005];//每个人处理时间，下标0-K
int ques[1005];
int ans[1005];        //记录每个人结束的时间
int front[20];        //记录正在处理的人的编号
int totalTime[20];    //用totalTime最小来确定下一个进哪个队列
int in = 1, out = 0;  //in表示下一个要进入队列的，out表示离开队列的人数
//其实可以用vector数组
void compute() {
	/*for (int i = 0; i < N; i++) {
		if (!q[i].empty()) {
			totalTime[i] += processTime[q[i].front()];
			ans[q[i].front()] += processTime[q[i].front()];
		}
	}*/
	while (out <= K) {
		int min = 1000000, temp = -1;
		for (int i = 0; i < N; i++) {
			if (totalTime[i] < min && totalTime[i] != -1) {
				min = totalTime[i];
				temp = i;           //拥有当前人完成时间最小的队列的下标，即下个出入队的进行标志
			}
		}
		if (temp == -1) {//找不到，totaltime全为0了。
			return;
		}
		//totaltime[i]记录i号窗口当前客户服务结束时间，所以用endTime[]可能更好一些。
		//对于temp, now来说，都是“开始处理”
		if (!q[temp].empty()) {
			if (min == 0) {      //如果没有这个，开始处理1时，就让5入队了，相当于每队3个人
				int now = q[temp].front(); 
				q[temp].pop();
				out++;
				totalTime[temp] += processTime[now];
				ans[now] = totalTime[temp];
				continue;
			}
			int now = q[temp].front();     //temp为队列下标，now为人的下标。
			q[temp].pop();
			out++;
			if (in <= K) {
				q[temp].push(in++);
			}
			//cout << temp << ' ' << in - 1 << endl;
			if (totalTime[temp] >= 540) ans[now] = -1;
			else {
				totalTime[temp] += processTime[now];
				ans[now] = totalTime[temp];
			}
			//cout << temp << ' ' << now << ' ' << in-1<<' '<< ans[now] << endl;
		}
		else { //队列空了，就不会有人来了
			totalTime[temp] = -1;
		}
	}
}
void disp(int a) {
	if (a < 0) {
		printf("Sorry\n");
		return;
	}
	int h = 8, m = 0;
	h += a / 60;
	m += a % 60;
	printf("%02d:%02d\n", h, m);
}
int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &processTime[i]);
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &ques[i]);
	}
	for (int i = 0; i < M; i++) {//将尽可能多的人放进队列
		for (int j = 0; j < N; j++) {
			if (in <= K) q[j].push(in++);
		}
	}
	compute();
	for (int j = 0; j < Q; j++) {
		disp(ans[ques[j]]);
	}
}