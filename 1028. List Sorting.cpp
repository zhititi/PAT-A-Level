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
//用string, cin, cout会超时，所以学学用字符数组吧，用char n[10]定义，用%s输入输出，用strcmp(n, m)比较（相当于n.compare(m)）
int n, c;
struct G {
	int id;
	char name[10];
	int record;
}stu[100005];
bool cmp1(G a, G b) {
	return a.id < b.id;
}
bool cmp2(G a, G b) {
	//if (a.name.compare(b.name) != 0) return a.name.compare(b.name) < 0;
	if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
	else return a.id < b.id;
}
bool cmp3(G a, G b) {
	if (a.record != b.record) return a.record < b.record;
	else return a.id < b.id;
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].record);
	}
	switch (c) {
	case 1: sort(stu, stu + n, cmp1); break;
	case 2: sort(stu, stu + n, cmp2); break;
	case 3: sort(stu, stu + n, cmp3); break;
	}
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].record);
	}
}