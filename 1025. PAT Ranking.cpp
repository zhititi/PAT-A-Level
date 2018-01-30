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
	string id;
	int location;
	int score;
	int totalrank;
	int localrank;
}mem[30010];        //是三万，不是三千。所以发生段错误，300*100=30000 好吗？
bool cmp(G a, G b) {
	if(a.score!=b.score) return a.score > b.score;
	else return a.id.compare(b.id) < 0;  //字符串的比较，注意看题，分数相同时按id从小到大输出
}
int main() {
	int n, k;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> mem[count].id >> mem[count].score;
			mem[count++].location = i;
		}
		sort(mem + count - k, mem + count, cmp);
		mem[count - k].localrank = 1;
		for (int j = count - k + 1; j < count; j++) {
			if (mem[j].score == mem[j - 1].score) {
				mem[j].localrank = mem[j - 1].localrank;
			}
			else {
				mem[j].localrank = j + 1 - (count - k);
			}
		}
	}
	sort(mem, mem + count, cmp);
	mem[0].totalrank = 1;
	for (int j = 1; j < count; j++) {      //设置一个初值，从1开始，这种思想要掌握。一种按值排序的思想
		if (mem[j].score == mem[j - 1].score) {
			mem[j].totalrank = mem[j - 1].totalrank;
		}
		else {
			mem[j].totalrank = j + 1;
		}
	}
	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << mem[i].id << ' ' << mem[i].totalrank << ' ' << mem[i].location << ' ' << mem[i].localrank << endl;
	}
	/*cout << count << endl;   //另一种方法
	int r = 1;
	for (int i = 0; i < count; i++) {
		if (i > 0 && mem[i].score != mem[i - 1].score) {
			r = i + 1;
		}
		cout << mem[i].id << ' ' << r << ' ' << mem[i].location << ' ' << mem[i].localrank << endl;
	}*/
	return 0;
}