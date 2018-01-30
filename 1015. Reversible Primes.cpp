#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
bool isprime(int a) {   //判断是否是素数
	int temp = sqrt(a);
	if (a <= 1) {
		return false;
	}
	for (int i = 2; i <= temp; i++) {
		if (a%i == 0) return false;
	}
	return true;
}
int ans[1000000];
int change(int num, int radix) {       //将num在radix进制下反转，返回反转后的十进制的值
	int count = 0;
	//cout << num << ' ' << radix << endl;
	for (int i = 0; i < 1000000; i++) {      //1000000太长了。。。
		if (num > 0) {
			ans[i] = num%radix;
			num = num / radix;
			count++;
		}
		else break;
	}
	int res = 0;
	for (int i = 0; i < count; i++) {
		res = res*radix + ans[i];
	}
	return res;
}
//The input file consists of "several" test cases.!!!!
int main() {
	int num, radix; //num记录数，radix记录基数
	int temp, count = 0;
	for (int i = 0; i < 100000; i++) {
		scanf("%d", &num);
		if (num < 0) break;
		else {
			scanf("%d", &radix);
			if (isprime(num) == true) {
				temp = change(num, radix);
				//cout << temp << endl;
				if (isprime(temp) == true) {
					printf("Yes\n");
					continue;
				}
			}
			printf("No\n");
		}
	}
}
//The input file consists of "several" test cases!!!!看好了，是several！！所以每个test cases后都要有输出
//注意1不是素数（质数）这点容易遗漏！！判断素数时上界应该到sqrt(num)即num的开方！！