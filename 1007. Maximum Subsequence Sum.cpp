#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int elem[10005], k;//k个数
int main()
{
	int large = 0, first, last, now;//now表示现在序列的第一位
	int sum[2] = { 0 };//sum[0]表过去，sum[1]表现在
	bool flag = false;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &elem[i]);
		sum[0] = sum[1];
		sum[1] += elem[i];
		if (sum[1] < 0) {      //现在<0
			sum[1] = 0;
		}
		else                   //现在>=0，现在=0的情况其实是无所谓的。因为要求两个都靠前，sum[1]=0的情况保证了i靠前
		{
			if (flag == false) //有非负数出现
			{
				flag = true;//若用flag记录第一个非负数，能输出出来，flag肯定是0，所以其实没必要这样。
			}
			if (sum[0] == 0)   //新序列的第一个数
			{
				now = elem[i];
			}
			if (sum[1] > large)//找到更大的数，这里对sum[1]=large的情况不做处理保证了j靠前，与first,now配合保证序列靠前。
			{
				large = sum[1];
				first = now;
				last = elem[i];
			}
		}
	}
	if (large == 0)
	{
		if (flag == false)
		{
			printf("%d %d %d\n", large, elem[0], elem[k-1]);
		}
		else
		{
			printf("%d 0 0\n", large);//其实就是0 0 0
		}
		return 0;
	}
	printf("%d %d %d\n", large, first, last);
}