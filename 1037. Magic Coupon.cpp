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
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int NC, NP;
	int coup[100005], prop[100005];//�ۡ�����Ȼ����������޵Ķ���
	int coun[100005], pron[100005];
	int temp;
	int count = 0, count1 = 0;
	scanf("%d", &NC);
	for (int i = 0; i < NC; i++) {
		scanf("%d", &temp);
		if (temp > 0) coup[count++] = temp;
		else if (temp < 0) coun[count1++] = temp;
	}
	int count2 = 0, count3 = 0;
	scanf("%d", &NP);
	for (int i = 0; i < NP; i++) {
		scanf("%d", &temp);
		if (temp > 0) prop[count2++] = temp;
		else if (temp < 0) pron[count3++] = temp;
	}
	sort(coup, coup + count, cmp);//������ȯ
	sort(coun, coun + count1);    //������ȯ
	sort(prop, prop + count2, cmp);//������Ʒ
	sort(pron, pron + count3);    //������Ʒ
	int total = count < count2 ? count : count2;
	int total1 = count1 < count3 ? count1 : count3;
	long long ans = 0;
	for (int i = 0; i < total; i++) {
		ans += coup[i] * prop[i];
	}
	for (int i = 0; i < total1; i++) {
		ans += coun[i] * pron[i];
	}
	printf("%lld\n", ans);
}