#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
//�����Ҳ�����˹����Ժ�����ɢ�о���ɢ�в�˵ɶ�ˡ����Խ��Խ�á�
struct Node {
	int exp;//ָ��
	float coe;//ϵ��
}x1[15],x2[15];
int K1,K2;//����
float sum[2001] = { 0 };//��¼���
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
	int temp, used[110], count = 0;//temp��ʾ��ʱ�±꣬used��¼�Ѿ��м�¼�Ľ����count��¼�м�¼�Ľ������
	for (int i = 0; i < K1; i++) {
		for (int j = 0; j < K2; j++) {
			temp = x1[i].exp + x2[j].exp;
			/*if (sum[temp] == 0 && x1[i].coe * x2[j].coe != 0) {//��ǰδ��¼�����˴�Ϊused���������Ĵ��룩��
				used[count++] = temp;
			}*/
			sum[temp] += x1[i].coe * x2[j].coe;//i��jд����
			//cout << x1[i].coe<<' '<< x2[i].coe<<' '<< x1[i].coe * x2[i].coe << endl;
		}
	}
	//used���������Ĵ��롣һ������֪�Ĵ���
	/*sort(used, used + count);
	if (count == 0) {
		printf("0");
		return 0;
	}
	printf("%d", count);
	for (int i = count - 1; i >= 0; i--) {//i����д����
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