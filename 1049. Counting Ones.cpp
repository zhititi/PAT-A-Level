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
//数学问题
int n;
int main() {
	scanf("%d", &n);
	int ans = 0, a = 1;
	while (n / a > 0) {
		int now = (n / a) % 10;
		int right = n % a;
		int left = n / a / 10;
		if (now < 1)ans += left*a;
		if (now == 1)ans += left*a + right + 1;
		if (now > 1)ans += (left + 1)*a;
		a *= 10;
	}
	printf("%d", ans);
}