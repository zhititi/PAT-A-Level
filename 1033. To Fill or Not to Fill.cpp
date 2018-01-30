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
//emmm�������⡣̰����̰��......
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
	if (sta[0].dis != 0) { printf("The maximum travel distance = 0.00"); return 0; }//���ּ���д���ǵüӴ�����
	sta[N].dis = D;
	sta[N].price = 0.0;
	int now = 0;//nowΪ�������ڵ�վ
	double ans = 0;//ansΪ���ͼ�Ǯ
	double nowtank = 0;//nowtankΪ���������������
	double max = Cmax*Davg;//maxΪ���ɵ�����
	while (now < N) {
		int k = -1;              //k��¼��һ��Ҫ����վ
		double minprice = 10000000;//��¼����һ��Ҫ����վ�ľ���
		for (int i = now + 1; i <= N; i++) {
			if (sta[i].dis - sta[now].dis <= max&&sta[i].price <= minprice) {
				k = i;
				minprice = sta[i].price;
				if (minprice < sta[now].price) break;
			}
		}
		if (k == -1) { printf("The maximum travel distance = %.2lf", (sta[now].dis + max)); return 0; }//ע��ע�⣬�����λС����%.2lf
		double need = (sta[k].dis - sta[now].dis) / Davg;//����һվ��Ҫ������
		if (minprice < sta[now].price) {  //��һվ�۸����
				ans += (need - nowtank)*sta[now].price;
				nowtank = 0;
		}
		else {//��һվ�۸���ߣ�������ͬ
			ans += (Cmax - nowtank)*sta[now].price;//����
			nowtank = Cmax - need;
		}
		now = k;
	}
	printf("%.2lf", ans);
}