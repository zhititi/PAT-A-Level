#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int k;
	scanf("%d", &k);
	float x[1010] = { 0 }, num;
	int add, used[1010] = { 0 }, sum = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &add); //����ָ��
		scanf("%f", &num); //����ϵ��
		x[add] += num;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) 
	{
		scanf("%d", &add); //����ָ��
		scanf("%f", &num); //����ϵ��
		x[add] += num;
	}
	for (int i = 0; i < 1010; i++) {
		if (x[i] != 0)
		{
			used[sum++] = i;
		}
	}
	printf("%d", sum);
	for (int i = sum - 1; i >= 0; i--) {
		printf(" %d %.1f", used[i], x[used[i]]);
	}
	printf("\n");
	return 0;
}
//ע��Ҫ���ǵ������������ȫ���ǡ�