#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int elem[10005], k;//k����
int main()
{
	int large = 0, first, last, now;//now��ʾ�������еĵ�һλ
	int sum[2] = { 0 };//sum[0]���ȥ��sum[1]������
	bool flag = false;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &elem[i]);
		sum[0] = sum[1];
		sum[1] += elem[i];
		if (sum[1] < 0) {      //����<0
			sum[1] = 0;
		}
		else                   //����>=0������=0�������ʵ������ν�ġ���ΪҪ����������ǰ��sum[1]=0�������֤��i��ǰ
		{
			if (flag == false) //�зǸ�������
			{
				flag = true;//����flag��¼��һ���Ǹ����������������flag�϶���0��������ʵû��Ҫ������
			}
			if (sum[0] == 0)   //�����еĵ�һ����
			{
				now = elem[i];
			}
			if (sum[1] > large)//�ҵ���������������sum[1]=large�������������֤��j��ǰ����first,now��ϱ�֤���п�ǰ��
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
			printf("%d 0 0\n", large);//��ʵ����0 0 0
		}
		return 0;
	}
	printf("%d %d %d\n", large, first, last);
}