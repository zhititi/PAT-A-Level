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
bool cmp(string a, string b) {   //�ţ�������һ������У�ѧ����û��
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
	while (ans.size() != 0 && ans[0] == '0') ans.erase(ans.begin()); //ȥ0������ע���ˣ����ܡ�
	if (ans.size() == 0) cout << '0';
	else cout << ans;
}