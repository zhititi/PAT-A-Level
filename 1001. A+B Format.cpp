#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a + b;
	if (abs(c) < 1000)
		printf("%d\n", c);
	else if (abs(c) < 1000000) {
		int c1 = c % 1000;
		c = c / 1000;
		printf("%d,%03d\n", c, abs(c1));//注意输出格式
	}
	else {
		int c1 = c % 1000;
		c = c / 1000;
		int c2 = c % 1000;
		c = c / 1000;
		printf("%d,%03d,%03d\n", c, abs(c2), abs(c1));
	}
	return 0;
}