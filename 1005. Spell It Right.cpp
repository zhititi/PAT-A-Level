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
void output(int x, int y)//递归做法。
{
	if (x < 10)//如果x小于10（第一位数）
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
	for (string::iterator it = number.begin() ; it < number.end(); it++)//迭代器的用法iterator
	{
		x += *it - '0';
	}
	y = x;
	int i;
	for (i = 1; y >= 10; i++)//确定x有i位，这里必须注意。
	{
		y = y / 10;
	}
	//output(x, i);
	//cout << x << endl << i << endl;
	y = i;
	double q = x / pow(10, y);
	for (int j = 0; j < i; j++)//如果上天再给我一次机会，我绝对不会这样做。我会用字符串去做。不会用递归或者循环逻辑去做。
	{
		int k = q * 10 + 0.01;//这里+0.01为了消去系统误差
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