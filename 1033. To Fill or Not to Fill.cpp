#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
//emmm策略问题。贪，，贪心......
struct G {
	double price;
	double dis;
}sta[505];
bool cmp(G a, G b) {
	return a.dis < b.dis;
}
int main() {
	double Cmax, D, Davg;
	int N;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}
	sort(sta, sta + N, cmp);
	if (sta[0].dis != 0) { printf("The maximum travel distance = 0.00"); return 0; }//这种简洁的写法记得加大括号
	sta[N].dis = D;
	sta[N].price = 0.0;
	int now = 0;//now为现在所在的站
	double ans = 0;//ans为总油价钱
	double nowtank = 0;//nowtank为现在油箱里的油量
	double max = Cmax*Davg;//max为最大可到距离
	while (now < N) {
		int k = -1;              //k记录下一个要到的站
		double minprice = 10000000;//记录到下一个要到的站的距离
		for (int i = now + 1; i <= N; i++) {
			if (sta[i].dis - sta[now].dis <= max&&sta[i].price <= minprice) {
				k = i;
				minprice = sta[i].price;
				if (minprice < sta[now].price) break;
			}
		}
		if (k == -1) { printf("The maximum travel distance = %.2lf", (sta[now].dis + max)); return 0; }//注意注意，输出两位小数是%.2lf
		double need = (sta[k].dis - sta[now].dis) / Davg;//到下一站需要的油量
		if (minprice < sta[now].price) {  //下一站价格更低
				ans += (need - nowtank)*sta[now].price;
				nowtank = 0;
		}
		else {//下一站价格更高，或者相同
			ans += (Cmax - nowtank)*sta[now].price;//加满
			nowtank = Cmax - need;
		}
		now = k;
	}
	printf("%.2lf", ans);
}