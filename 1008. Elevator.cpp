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
	int num[10000], n, sum = 0;//n��
	num[0] = 0;//��ʼΪ0
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &num[i]);//����ô���˼�&�ɣ�zz��
		if (num[i] - num[i - 1] >= 0) {//������
			sum += (num[i] - num[i - 1]) * 6 + 5;
		}
		else {
			sum += (num[i - 1] - num[i]) * 4 + 5;
		}
	}
	printf("%d\n", sum);
}