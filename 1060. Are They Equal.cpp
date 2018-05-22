#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
string change(string str, int n) {
	string ans;
	int zero = -1, point = -1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '0'&&zero < 0) {
			zero = i;
		}
		if (str[i] == '.'&&point < 0) {
			point = i;
		}
	}
	if (point == -1) {
		point=str.length()-
	}
	int exp = zero - point + 1;
}
int main() {
	int n;
	string a, b;
	cin >> n >> a >> b;
}