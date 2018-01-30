#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int N, K;//N表示总人数，K为总柜台数
struct G {   //结构体数组初值就是0
	int arrive;
	int time;
}temp;
vector<G> custom;        //用vector保存客户，既可以不限数量，又可以排序
int endTime[105];           //记录i号窗口当前客户服务结束时间，精髓啊！！
int change(int h, int m, int s) {           //学着点吧！
	return h * 3600 + m * 60 + s;
}
bool cmp(G a, G b) {
	return(a.arrive < b.arrive);
}
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) endTime[i] = change(8, 0, 0);//endtime[]都初始化为8点
	for (int i = 0; i < N; i++) {
		int h, m, s, serveTime;
		scanf("%d:%d:%d %d", &h, &m, &s, &serveTime); //以后都给我这样输入，听见没？
		int arrive = change(h, m, s);
		if (arrive > 61200) continue;
		temp.arrive = arrive;
		temp.time = serveTime <= 60 ? serveTime * 60 : 3600;
		custom.push_back(temp);
	}
	sort(custom.begin(), custom.end(), cmp);
	int totalTime = 0;
	for (int i = 0; i < custom.size(); i++) {
		int index = -1, minEndtime = 10000000;
		for (int j = 0; j < K; j++) {  //找到结束时间最早的窗口的下标
			if (endTime[j] < minEndtime) {
				minEndtime = endTime[j];
				index = j;
			}
		}
		if (endTime[index] < custom[i].arrive) endTime[index] = custom[i].arrive + custom[i].time;
		else {
			totalTime += (endTime[index] - custom[i].arrive);
			endTime[index] += custom[i].time;
		}
	}
	if (custom.size() == 0)printf("0.0");
	else printf("%.1f", totalTime / 60.0 / custom.size());
	return 0;
}
/*int change(string str) {                    敌我装备对比。
	int res = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ':') {
			res = res * 10 + (str[i] - '0');//总是忘了-'0'
		}
	}
	return res;
}
int change1(int n) {
	int res;
	res = n % 100 + 60 * ((n / 100) % 100) + 3600 * (n / 10000);
	//res += 3600 * n / 10000;这样就不行，因为先3600*n再除以10000。。？？
	return res;
}
int main() {
	string temp;
	int n;
	scanf("%d%d", &N, &K);
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp >> n;
		int temp1 = change(temp);
		if (temp1 < 170000 && n <= 60) {
			temp1 = change1(temp1);
			mum[count].arrive = temp1;
			mum[count++].time = n;

		}
	}
	sort(mum, mum + count, cmp);
	//cout << mum[4].arrive << ' ' << mum[4].time;
}*/