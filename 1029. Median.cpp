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
long long num[2000020];
int main() {
	int n1, n2;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%lld", &num[i]);
	}
	cin >> n2;
	for (int i = n1; i < n1 + n2; i++) {
		scanf("%lld", &num[i]);
	}
	int n = n1 + n2;
	sort(num, num + n);
	printf("%lld", num[(n - 1) / 2]);//����Ӧ���� n - 1 ��Ϊ�±�����
}