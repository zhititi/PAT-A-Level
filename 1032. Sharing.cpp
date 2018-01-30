#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	char data;
	int next;
	bool flag;
}a[100010];
int main() {
	int n, first, second;
	cin >> first >> second >> n;
	for (int i = 0; i < n; i++)
	{
		int addr;
		cin >> addr;
		cin >> a[addr].data >> a[addr].next;
		a[addr].flag = false;
	}
	int p = first, q = second;
	int count = 0;
	while (p != -1) {
		a[p].flag = true;
		p = a[p].next;
	}
	int result = -1;
	while (q != -1) {
		if (a[q].flag == true) {
			result = q;
			break;
		}
		q = a[q].next;
	}
	if (result == -1) {
		printf("-1\n");
		return 0;
	}
	printf("%05d\n", result);
	return 0;
}