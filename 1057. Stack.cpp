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
int getmid(vector<int> s) {
	int len = s.size();
	sort(s.begin(), s.end());
	if (len % 2 == 0) {//元素个数为偶数
		return s[len / 2 - 1];
	}
	else {     //元素个数为奇数
		return s[(len + 1) / 2 - 1];
	}
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> st;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == "Pop") {
			if (st.empty()) {
				printf("Invalid\n");
			}
			else {
				printf("%d\n", st.back());
				st.pop_back();
			}
		}
		if (temp == "PeekMedian") {
			if (st.empty()) {
				printf("Invalid\n");
			}
			else {
				int ans = getmid(st);
				printf("%d\n", ans);   //这里加什么’&‘？？？？
			}
		}
		if (temp == "Push") {
			int num;
			scanf("%d", &num);
			st.push_back(num);
		}
	}
	return 0;
}