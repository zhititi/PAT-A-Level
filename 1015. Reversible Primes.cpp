#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
bool isprime(int a) {   //�ж��Ƿ�������
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
int change(int num, int radix) {       //��num��radix�����·�ת�����ط�ת���ʮ���Ƶ�ֵ
	int count = 0;
	//cout << num << ' ' << radix << endl;
	for (int i = 0; i < 1000000; i++) {      //1000000̫���ˡ�����
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
	int num, radix; //num��¼����radix��¼����
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
//The input file consists of "several" test cases!!!!�����ˣ���several��������ÿ��test cases��Ҫ�����
//ע��1�������������������������©�����ж�����ʱ�Ͻ�Ӧ�õ�sqrt(num)��num�Ŀ�������