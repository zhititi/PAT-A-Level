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
char ele[5] = { 'S','H','C','D','J' };
//洗牌模拟。运用编号代替实际名称，设置now[],end[]数组相互转换，以及用编号来实现巧妙的输出模式，实现过程的模拟。
int main() {
	int k;
	int now[55], end[55];  //用于相互转换
	int order[55];         //给定的顺序
	for (int i = 1; i < 55; i++) {//刚开始数组的顺序是整齐的
		now[i] = i;
	}

	scanf("%d", &k);        //输入执行次数k
	for (int i = 1; i < 55; i++) {  //输入既定洗牌顺序
		scanf("%d", &order[i]);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < 55; j++) {  //每次将now[]对应到end[]再对应回来
			end[order[j]] = now[j];
		}
		for (int j = 1; j < 55; j++) {  //将now[]换为end[]以便下次循环继续。
			now[j] = end[j];
		}
	}

	printf("%c%d", ele[(now[1] - 1) / 13], (now[1] - 1) % 13 + 1);  //运用编号的组合实现简单的输出
	for (int i = 2; i < 55; i++) {
		printf(" %c%d", ele[(now[i] - 1) / 13], (now[i] - 1) % 13 + 1);
	}
	return 0;
}