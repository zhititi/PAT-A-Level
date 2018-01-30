#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;
map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//���ھ���G����Ȩweight
int n, k, numPerson = 0;//����n������k��������numPerson
bool vis[maxn] = { false };//����Ƿ��б�����

//DFS�������ʵ�����ͨ�飬nowVisitΪ��ǰ���ʱ��
//headΪͷĿ��numMemberΪ��Ա��ţ�totalValueΪ��ͨ���ܱ�Ȩ
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) //ͼ�ĵݹ�����㷨
{
	numMember++;
	vis[nowVisit] = true;//�ѷ���
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++) {//ÿ���˶��ж�
		if (G[nowVisit][i] > 0) {//֮�����ͨ��
			totalValue += G[nowVisit][i];       //�ܵ绰ʱ��++
			G[nowVisit][i] = G[i][nowVisit] = 0;//��0����ֹ�ظ������ߣ���Ϊ��ʱû���ж�vis[]
			if (vis[i] == false) {  
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}
//DFS1����д���Ǵ���ģ���Ϊ��ʱ���ܳɻ�ʱ�������ڵ�֮�����δ�����ıߣ���Ŀ�����Ѿ������ʹ���
void DFS1(int nowVisit, int& head, int& numMember, int& totalValue) 
{
	numMember++;
	vis[nowVisit] = true;//�ѷ���
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++) {
		if (G[nowVisit][i] > 0 && vis[i]==false) {//֮�����ͨ������һ��û�����ʹ���
			totalValue += G[nowVisit][i];
			DFS1(i, head, numMember, totalValue);
		}
	}
}
//�����������Լ�д��BFS���������û�б�Ҫ��DFS��
void BFS(int nowVisit, int& head, int& numMember, int& totalValue)
{
	queue<int> q;
	q.push(nowVisit);
	vis[nowVisit] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		numMember++;
		if (weight[now] > weight[head]) {
			head = now;
		}
		for (int i = 0; i < numPerson; i++) {
			if (G[i][now] > 0){
				totalValue += G[now][i];
				G[now][i] = G[i][now] = 0;
				if (vis[i] == false) {  //��һ���ܱ�Ҫ��������ͷ������numMember����Բۣ�����Ⱥš�����
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}
}
//DFSTrave��������ͼ����ȡÿ����ͨ�����Ϣ
void DFSTrave()
{
	for (int i = 0; i < numPerson; i++) {//ÿ�����
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;// ͷĿ = i, �Ŷ����� = 0, ��ͨ��ʱ�� = 0
			BFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k) { //��������2��������ͨ��ʱ�����k
				Gang[intToString[head]] = numMember;//Gang�������е�keyΪ�����ŻvalueΪ�����Ż������
			}
		}
	}
}
//change��������str����Ӧ�ı��
int change(string str) {
	if (stringToInt.find(str) != stringToInt.end()) //map������find���÷���ʧ��ʱ����map.end()
	{
		return stringToInt[str];
	}
	else {//ʧ�䣬û�ҵ�
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}
int main(){
	int w;
	string str1,str2;
	cin >> n >> k;  //n is the number of phone calls, k is the weight threshold.
	for (int i = 0; i < n; i++) { //���뻷��
		cin >> str1 >> str2 >> w;//�����˵㣬�Լ�ͨ��ʱ��
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << ' ' << it->second << endl; //��it->first�����ʼ���it->second������ֵ
	}
	return 0;
}
/*
�������н�㣬���ù��Ӳ��ţ�ֻ��vis�������ѷ���
�������н�����бߣ���Ҫ���Ӳ��ţ�Ҳ��Ҫ��vis�������ѷ���
���ߵĲ�ͬ
*/
