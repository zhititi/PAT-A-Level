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
string num, ans;
int calculate(string n) {  //大整数*2的乘法
	int x = 0, y;
	for (int i = 0; i <n.size(); i++) {
		y = (n[i] - '0') * 2 + x;
		ans += y % 10 + '0';
		x = y / 10;
	}
	if (x == 0) {
		reverse(ans.begin(), ans.end());
		return 0;
	}
	else { 
		ans += '1';
		reverse(ans.begin(), ans.end());
		return 1;
	}
}
int main() {
	cin >> num;
	reverse(num.begin(), num.end());
	int k = calculate(num);
	if (k == 1) {
		cout << "No" << endl << ans;
	}
	else {
		string ans1 = ans;
		sort(num.begin(), num.end());
		sort(ans1.begin(), ans1.end());
		if (num == ans1) {
			cout << "Yes" << endl << ans;
		}
		else {
			cout << "No" << endl << ans;
		}
	}
}