#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct Node {
	string num;
	long long index = 0;
	long long value;
};
Node x[2];
int main()//���������͡�
{
	long long flag = 0, ind;//flag�����ĸ�index��֪
	cin >> x[0].num >> x[1].num >> flag >> ind;
	if (flag == 1) {
		x[0].index = ind;
	}
	else x[1].index = ind;
	for (int i = 0; i < 2; i++) {
		if (x[i].index == 0) continue;
		long long count = 0;         //���Ӧ��д�����棬count��¼���η�
		for (int j = x[i].num.length() - 1; j >= 0; j--) {
			if (x[i].num[j] <= '9') {
				x[i].value += (x[i].num[j] - '0')* pow(x[i].index, count);
			}
			else {
				x[i].value += (x[i].num[j] - 'a' + 10)* pow(x[i].index, count);
			}
			count++;
		}
	}
	
	long long value, index;
	string num;          //numΪ���У�valueΪĿ��ֵ
	if (flag == 1) {
		num = x[1].num;
		value = x[0].value;
	}
	else {
		num = x[0].num;
		value = x[1].value;
	}

	char max = '0';
	for (int i = 0; i < num.length(); i++) {
		if (num[i] > max) max = num[i];
	}
	long long Max;
	if (num[0] <= '9') {
		Max = max - '0';
	}
	else {
		Max = max - 'a' + 10;
	}
	long long count = 0, temp = 0;//temp��¼��ǰ�ͣ�count��¼���η�
	for (index = Max + 1; index < pow(2,63); index++) {
		for (int i = num.length() - 1; i >= 0; i--) {
			if (num[i] <= '9') {
				temp += (num[i] - '0')* pow(index, count);
			}
			else {
				temp += (num[i] - 'a' + 10)* pow(index, count);
			}
			count++;//����count����
		}

		if (temp > value){
			printf("Impossible");
			return 0;
		}
		else if (temp == value) {
			printf("%d\n", index);
			return 0;
		}
	}
}