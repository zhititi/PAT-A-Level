#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
string num[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
void output(int x, int y)//�ݹ�������
{
	if (x < 10)//���xС��10����һλ����
	{
		cout << num[x] ;
		return;
	}
	output(x / 10, y-1);
	int q = x - pow(10, y-1);
	cout << ' ' << num[q] ;
}
int main()
{
	string number;
	long int sum, x = 0, y;
	cin >> number;
	for (string::iterator it = number.begin() ; it < number.end(); it++)//���������÷�iterator
	{
		x += *it - '0';
	}
	y = x;
	int i;
	for (i = 1; y >= 10; i++)//ȷ��x��iλ���������ע�⡣
	{
		y = y / 10;
	}
	//output(x, i);
	//cout << x << endl << i << endl;
	y = i;
	double q = x / pow(10, y);
	for (int j = 0; j < i; j++)//��������ٸ���һ�λ��ᣬ�Ҿ��Բ������������һ����ַ���ȥ���������õݹ����ѭ���߼�ȥ����
	{
		int k = q * 10 + 0.01;//����+0.01Ϊ����ȥϵͳ���
		q = q * 10 - k;
		if (j == 0)
		{
			cout << num[k];
			continue;
		}
		cout << ' ' << num[k];
	}
	cout << endl;
}