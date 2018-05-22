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
struct G{
	int num, exp;       //质因子&系数
}fac[10];
bool isprime(int num) {
	int n = sqrt(num);
	for (int i = 2; i <= n; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int num,num1;
	scanf("%d", &num);
	int n = sqrt(num);
	int count = 0;
	num1 = num;      //副本

	if (num == 1) {
		printf("1=1");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (isprime(i) == true) {
			if (num%i == 0) {
				fac[count].num = i;
				fac[count].exp = 0;
				while (num%i == 0) {
					fac[count].exp++;
					num = num / i;
				}
				count++;
			}
		}
	}

	if (num != 1) {
		fac[count].num = num;
		fac[count].exp = 1;
		count++;
	}

	printf("%d=", num1);
	if (fac[0].exp > 1) {  //输出第一位
		printf("%d^%d", fac[0].num, fac[0].exp);
	}
	else printf("%d", fac[0].num);

	for (int i = 1; i < count; i++) {
		if (fac[i].exp > 1) {
			printf("*%d^%d", fac[i].num, fac[i].exp);
		}
		else printf("*%d", fac[i].num);
	}
}