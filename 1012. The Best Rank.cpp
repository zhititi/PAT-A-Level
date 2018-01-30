#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
string ID[2005], check[2005];
int C[2005], M[2005], E[2005], A[2005];
int n, m;//有N个学生，有M个学生查询自己的成绩
struct MyStruct
{
	int C, M, E, A;
}stu[2005];
bool cmp(int a, int b) {
	return a > b;
}
int find(int a, int b[]) {
	for (int i = 0; i < n; i++) {//找排名
		if (b[i] == a) {
			return i + 1;
		}
	}
}
void check_output(int temp) {
	int a = find(stu[temp].A, A);
	int c = find(stu[temp].C, C);
	int m = find(stu[temp].M, M);
	int e = find(stu[temp].E, E);
	//cout << a << ' ' << c << ' ' << m << ' ' << e << endl;
	char res = 'A';
	int maxrank = a;
	if (maxrank > c) {//这里，应该分别判断，而不是嵌套
		res = 'C';
		maxrank = c;
	}
	if (maxrank > m) {
		res = 'M';
		maxrank = m;
	}
	if (maxrank > e) {
		res = 'E';
		maxrank = e;
	}
	printf("%d %c\n", maxrank, res);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> ID[i] >> C[i] >> M[i] >> E[i];
		A[i] = (C[i] + M[i] + E[i]) / 3;
		stu[i].C = C[i];
		stu[i].M = M[i];
		stu[i].E = E[i];
		stu[i].A = A[i];
	}
	sort(C, C + n, cmp);//都是从大到小排列的
	sort(M, M + n, cmp);
	sort(E, E + n, cmp);
	sort(A, A + n, cmp);
	for (int i = 0; i < m; i++) {
		cin >> check[i];
	}
	for (int i = 0; i < m; i++) {
		int temp = -1;
		for (int j = 0; j < n; j++) {//temp为待找元素的下标
			if (check[i] == ID[j]) {
				temp = j;
			}
		}
		if (temp == -1) {
			printf("N/A\n");
			continue;
		}
		//cout << temp << endl;
		check_output(temp);
	}
}