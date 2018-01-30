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
struct G {
	string name, gender, id;
	int grade;
}stu;
int n;
int main() {
	scanf("%d", &n);
	G boy, girl;
	boy.name = "Absent";
	girl.name = "Absent";
	int boymin = 110, girlmax = 0;
	for (int i = 0; i < n; i++) {
		cin >> stu.name >> stu.gender >> stu.id >> stu.grade;
		if (stu.gender[0] == 'M'&&stu.grade < boymin) {
			boy = stu;
			boymin = stu.grade;
		}
		else if (stu.gender[0] == 'F'&&stu.grade > girlmax) {
			girl = stu;
			girlmax = stu.grade;
		}
	}
	bool flag = false;
	cout << girl.name;
	if (girl.name == "Absent") { cout << endl; flag = true; }
	else { cout << ' ' << girl.id << endl; }
	cout << boy.name;
	if (boy.name == "Absent") { cout << endl; flag = true; }
	else { cout << ' ' << boy.id << endl; }
	if (flag == true) { cout << "NA"; }
	else cout << girl.grade - boy.grade;
}