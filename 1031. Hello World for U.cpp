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
string str;
int main() {
	cin >> str;
	int n1 = (str.size() + 2) / 3;
	int n2 = (str.size() + 2 - 2 * n1);
	int front = 0;
	int last = str.size() - 1;     //作为下标
	for (int j = 0; j < n1; j++) {   //j记录竖行
		for (int i = 0; i < n2; i++) {  //i记录横行
			if (j == n1 - 1) {
				cout << str[front++];
			}
			else {
				if (i == 0) cout << str[front++];
				else if (i == n2 - 1) cout << str[last--] << endl;
				else cout << ' ';
			}
		}
	}
	cout << endl;
}