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
//vector的用法，cmp函数的写法，char[]数组的用法，以及编号和名字的对应。
int n, k;
char name[40001][10];
vector<int> course[2501];
bool cmp(int a, int b) {  //以name[]中的元素的字典序来整理vector中编号
	return strcmp(name[a], name[b]) < 0;
}
int main() {
	scanf("%d%d", &n, &k);    //人数n，课数k
	for (int i = 0; i < n; i++) {
		scanf("%s", &name[i]);
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int temp;
			scanf("%d", &temp);
			course[temp].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++) {
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}