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
#include <stack>
using namespace std;
//栈的模拟方法。以及这个题目可以分别输出结果？？
int m, n, k;//m为栈的最大容量，n为输入序列的长度，k为需要检查的输出序列的个数
int main() {
	bool ans[1005];
	scanf("%d%d%d", &m, &n, &k);
	int temp[1005];  //输入序列
	stack<int> sta;
	for (int i = 0; i < k; i++) {
		while (!sta.empty()) { sta.pop(); }//清空栈
		for (int j = 0; j < n; j++) {
			scanf("%d", &temp[j]);  //记录输出序列
		}
		int count = 0;
		for (int j = 1; j <= n; j++) {
			sta.push(j);
			if (sta.size() > m) {  //超限了
				ans[i] = false;
				break;
			}
			while (!sta.empty() && sta.top() == temp[count]) {
				sta.pop();
				count++;
			}
		}
		if (sta.empty()) {
			ans[i] = true;
		}
		else ans[i] = false;
	}
	for (int i = 0; i < k; i++) {
		if (ans[i] == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}