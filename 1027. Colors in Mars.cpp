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
char trans(int a) { //将一个小于13的数转化为13进制中的字符
	if (a < 10) return a + '0';
	else return a - 10 + 'A';
}
string change(int a) {
	string n;
	char x = trans(a / 13);
	char y = trans(a % 13);
	n = n + x + y;
	return n;
}
int main() {
	int r, g, b;
	cin >> r >> g >> b;
	string r1 = change(r);
	string g1 = change(g);
	string b1 = change(b);
	cout << '#' << r1 << g1 << b1;
}