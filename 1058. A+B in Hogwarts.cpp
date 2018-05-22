#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
char num1[20], num2[20];
long long cal(char num[]) {
	long long ans = 0;
	long long temp = 0;//记录临时的值
	int i;
	for (i = 0; i < strlen(num); i++) {
		if (num[i] == '.') {
			ans += temp * 17 * 29;
			temp = 0;
			break;
		}
		temp = temp * 10 + (num[i] - '0');
	}
	for (i = i+1; i < strlen(num); i++) {
		if (num[i] == '.') {
			ans += temp * 29;
			temp = 0;
			break;
		}
		temp = temp * 10 + (num[i] - '0');
	}
	for (i = i+1; i < strlen(num); i++) {
		temp = temp * 10 + (num[i] - '0');
	}
	ans += temp;
	return ans;
}
void show(long long num) {
	long long temp1 = num /( 17 * 29);
	num = num % (17 * 29);
	long long temp2 = num / 29;
	long long temp3 = num % 29;
	printf("%lld.%lld.%lld", temp1, temp2, temp3);
}
int main() {
	scanf("%s%s", &num1, &num2);
	long long a = cal(num1);
	long long b = cal(num2);
	long long ans = a + b;
	show(ans);
	return 0;
}