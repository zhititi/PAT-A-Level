#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
//大整数运算。
string n;
int k;    //n为数，k为最大操作次数
string pluss(string a, string b) {  //大整数之和
	int alen = a.size();
	int blen = b.size();
	int flag;
	if (alen > blen) {
		flag = 1;
	}
	else flag = 2;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans;
	if (flag == 1) {
		int x = 0, i;
		for (i = 0; i < alen; i++) {
			if (i < blen) {
				int y = (a[i] - '0' + b[i] - '0') + x;
				ans += y % 10 + '0';
				x = y / 10;
			}
			else {
				ans += (a[i] - '0') % 10 + x + '0';
				x = 0;
			}
		}
		if (x == 1) {
			ans += '1';
		}
	}
	else {
		int x = 0, i;
		for (i = 0; i < blen; i++) {
			if (i < alen) {
				/*
				ans += (a[i] - '0' + b[i] - '0') % 10 + x + '0';       大错特错！！
				x = (a[i] - '0' + b[i] - '0') / 10;
				*/
				int y = (a[i] - '0' + b[i] - '0') + x;
				ans += y % 10 + '0';
				x = y / 10;
			}
			else {
				ans += (b[i] - '0') % 10 + x + '0';
				x = 0;
			}
		}
		if (x == 1) {
			ans += '1';
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
void operate() {//将其操作一次
	string n1 = n;
	reverse(n1.begin(), n1.end());
	n = pluss(n1, n);
}
bool judge(string a) {
	string temp = a;
	reverse(a.begin(), a.end());
	if (temp == a) return true;
	else return false;
}
int main() {
	cin >> n >> k;
	if (judge(n) == true) {
		cout << n << endl << '0';
		return 0;
	}
	for (int i = 0; i < k; i++) {
		operate();
		if (judge(n) == true) {
			cout << n << endl << i + 1;
			return 0;
		}
	}
	cout << n << endl << k;
	return 0;
}