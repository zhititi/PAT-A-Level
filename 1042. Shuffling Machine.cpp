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
//ϴ��ģ�⡣���ñ�Ŵ���ʵ�����ƣ�����now[],end[]�����໥ת�����Լ��ñ����ʵ����������ģʽ��ʵ�ֹ��̵�ģ�⡣
int main() {
	int k;
	int now[55], end[55];  //�����໥ת��
	int order[55];         //������˳��
	for (int i = 1; i < 55; i++) {//�տ�ʼ�����˳���������
		now[i] = i;
	}

	scanf("%d", &k);        //����ִ�д���k
	for (int i = 1; i < 55; i++) {  //����ȶ�ϴ��˳��
		scanf("%d", &order[i]);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < 55; j++) {  //ÿ�ν�now[]��Ӧ��end[]�ٶ�Ӧ����
			end[order[j]] = now[j];
		}
		for (int j = 1; j < 55; j++) {  //��now[]��Ϊend[]�Ա��´�ѭ��������
			now[j] = end[j];
		}
	}

	printf("%c%d", ele[(now[1] - 1) / 13], (now[1] - 1) % 13 + 1);  //���ñ�ŵ����ʵ�ּ򵥵����
	for (int i = 2; i < 55; i++) {
		printf(" %c%d", ele[(now[i] - 1) / 13], (now[i] - 1) % 13 + 1);
	}
	return 0;
}