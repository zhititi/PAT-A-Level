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
int n;
bool cmp(string a, string b) {   //嗯，就这样一排序就行，学到了没。
	return a + b < b + a;
}
int main() {
	scanf("%d", &n);
	string str[10010];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	string ans;
	for (int i = 0; i < n; i++) {
		ans += str[i];
	}
	while (ans.size() != 0 && ans[0] == '0') ans.erase(ans.begin()); //去0操作，注意了，高能。
	if (ans.size() == 0) cout << '0';
	else cout << ans;
}