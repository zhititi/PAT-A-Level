#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int num, radix;
vector<int> res;
void change(int n, int r) {
	while (n >= 1) {
		int temp = n%r;
		n = n / r;
		/*                进制转换用数组存储其实更方便
		res[num++] = n%r;
		n /= r;
		*/
		res.push_back(temp);
	}
	vector<int> res1 = res;
	reverse(res.begin(), res.begin() + res.size());
	if (res == res1) {
		printf("Yes\n");
		for (int i = 0; i < res.size() - 1; i++) {
			printf("%d ", res[i]);
		}
		printf("%d", res[res.size() - 1]);
	}
	else {
		printf("No\n");
		for (int i = 0; i < res.size() - 1; i++) {
			printf("%d ", res[i]);
		}
		printf("%d", res[res.size() - 1]);
	}
}
int main() {
	scanf("%d %d", &num, &radix);
	if (num == 0) {
		printf("Yes\n0");
		return 0;
	}
	change(num, radix);
	return 0;
}