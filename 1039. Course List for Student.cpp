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
//散列，输入输出关系
const int N = 40000;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[M];

int getID(char name[]) {   //hash函数，将字符串name转换成数字，即将学生ID转换成数字
	int id = 0;
	for (int i = 0; i < 3; i++) {  //前三位大写字母
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');  //最后一位数字
	return id;
}

int main() {
	char name[5];
	int n, k;         //n为查询的总人数，k为总课程数
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int course, x;  //分别为课程编号，选课人数
		scanf("%d%d", &course, &x);
		for (int j = 0; j < x; j++) {  //根据选课人数输入人的姓名，并将之转换为编号，将该课程编号装入人编号的散列
			scanf("%s", name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}
	for (int i = 0; i < n; i++) {   //输入查询的人，并输出。因为是整行输入，没有回车换行，所以可以边输入边输出
		scanf("%s", name);
		int id = getID(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		printf("%s %d", name, selectCourse[id].size());
		for (int j = 0; j < selectCourse[id].size(); j++) {
			printf(" %d", selectCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
}