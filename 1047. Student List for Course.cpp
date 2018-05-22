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
//vector���÷���cmp������д����char[]������÷����Լ���ź����ֵĶ�Ӧ��
int n, k;
char name[40001][10];
vector<int> course[2501];
bool cmp(int a, int b) {  //��name[]�е�Ԫ�ص��ֵ���������vector�б��
	return strcmp(name[a], name[b]) < 0;
}
int main() {
	scanf("%d%d", &n, &k);    //����n������k
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