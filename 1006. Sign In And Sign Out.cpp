#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct G
{
	string ID;
	string IN;
	string OUT;
	int InTime = 0;
	int OutTime = 0;
}member[100000];
int M;//������M
bool cmp1(G a,G b)
{
	return a.InTime < b.InTime;
}
bool cmp2(G a, G b)
{
	return a.OutTime > b.OutTime;
}
int main()
{
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> member[i].ID >> member[i].IN >> member[i].OUT;
	}
	int n;
	for (int i = 0; i < M; i++)//ÿ����Ա�����볡ʱ��
	{
		n = 100000;               //!Ӧ���������ʼ����
		for (int j = 0; j < member[i].IN.length(); j++)
		{
			if (member[i].IN[j] == ':')
				continue;
			member[i].InTime += (member[i].IN[j]-'0') * n;  //!����char����int�͵�ת��
			n /= 10;
		}
	}
	for (int i = 0; i < M; i++)//ÿ����Ա�������ʱ��
	{
		n = 100000;
		for (int j = 0; j < member[i].OUT.length(); j++)
		{
			if (member[i].OUT[j] == ':')
				continue;
			member[i].OutTime += (member[i].OUT[j]-'0') * n;
			n /= 10;
		}
	}
	//cout << member[2].InTime << endl << member[2].OutTime;
	sort(member, member + M, cmp1);
	cout << member[0].ID << ' ';
	sort(member, member + M, cmp2);
	cout << member[0].ID << endl;
}