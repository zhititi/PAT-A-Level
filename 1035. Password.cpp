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
	string id, password;
	bool flag;
}stu[1005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].id >> stu[i].password;
		stu[i].flag = false;
		for (int j = 0; j < stu[i].password.size(); j++) {
			if (stu[i].password[j] == '1') { stu[i].flag = true; stu[i].password[j] = '@'; }
			else if (stu[i].password[j] == '0') { stu[i].flag = true; stu[i].password[j] = '%'; }
			else if (stu[i].password[j] == 'l') { stu[i].flag = true; stu[i].password[j] = 'L'; }
			else if (stu[i].password[j] == 'O') { stu[i].flag = true; stu[i].password[j] = 'o'; }
		}
	}

	int f = 0;
	for (int i = 0; i < n; i++) {
		if (stu[i].flag == true) f++;
	}
	if (f == 0) {
		if (n > 1) {
			printf("There are %d accounts and no account is modified\n", n);//isºÍare£¬accountºÍaccounts¡£¡£
		}
		else {
			printf("There is %d account and no account is modified\n", n);
		}
	}
	else {
		printf("%d\n", f);
		for (int i = 0; i < n; i++) {
			if (stu[i].flag == true) cout << stu[i].id << ' ' << stu[i].password << endl;
		}
	}
}