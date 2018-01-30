#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int num[10000], n, sum = 0;//n层
	num[0] = 0;//初始为0
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &num[i]);//又特么忘了加&吧！zz！
		if (num[i] - num[i - 1] >= 0) {//向上走
			sum += (num[i] - num[i - 1]) * 6 + 5;
		}
		else {
			sum += (num[i - 1] - num[i]) * 4 + 5;
		}
	}
	printf("%d\n", sum);
}