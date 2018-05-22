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
//ջ��ģ�ⷽ�����Լ������Ŀ���Էֱ�����������
int m, n, k;//mΪջ�����������nΪ�������еĳ��ȣ�kΪ��Ҫ����������еĸ���
int main() {
	bool ans[1005];
	scanf("%d%d%d", &m, &n, &k);
	int temp[1005];  //��������
	stack<int> sta;
	for (int i = 0; i < k; i++) {
		while (!sta.empty()) { sta.pop(); }//���ջ
		for (int j = 0; j < n; j++) {
			scanf("%d", &temp[j]);  //��¼�������
		}
		int count = 0;
		for (int j = 1; j <= n; j++) {
			sta.push(j);
			if (sta.size() > m) {  //������
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