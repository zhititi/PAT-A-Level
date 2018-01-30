#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
//奇怪我也是日了狗，以后能用散列就用散列不说啥了。最好越简单越好。
struct Node {
	int exp;//指数
	float coe;//系数
}x1[15],x2[15];
int K1,K2;//数量
float sum[2001] = { 0 };//记录结果
int main()
{
	scanf("%d", &K1);
	for (int i = 0; i < K1; i++) {
		scanf("%d%f", &x1[i].exp, &x1[i].coe);
	}
	scanf("%d", &K2);
	for (int i = 0; i < K2; i++) {
		scanf("%d%f", &x2[i].exp, &x2[i].coe);
	}
	int temp, used[110], count = 0;//temp表示临时下标，used记录已经有记录的结果，count记录有记录的结果数量
	for (int i = 0; i < K1; i++) {
		for (int j = 0; j < K2; j++) {
			temp = x1[i].exp + x2[j].exp;
			/*if (sum[temp] == 0 && x1[i].coe * x2[j].coe != 0) {//以前未记录过（此处为used数组做法的代码）。
				used[count++] = temp;
			}*/
			sum[temp] += x1[i].coe * x2[j].coe;//i和j写错。。
			//cout << x1[i].coe<<' '<< x2[i].coe<<' '<< x1[i].coe * x2[i].coe << endl;
		}
	}
	//used数组做法的代码。一处不可知的错误。
	/*sort(used, used + count);
	if (count == 0) {
		printf("0");
		return 0;
	}
	printf("%d", count);
	for (int i = count - 1; i >= 0; i--) {//i减减写错了
		printf(" %d %.1f", used[i], sum[used[i]]);
	}
	return 0;*/

	for (int i = 0; i < 2001; i++)
	{
		if (sum[i] != 0)
			count++;
	}
	printf("%d", count);
	for (int i = 2000; i >= 0; i--) {
		if (sum[i] != 0) {
			printf(" %d %.1f", i, sum[i]);
		}
	}
}