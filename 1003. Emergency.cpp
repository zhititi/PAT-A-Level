#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;   //��������ô�д
const int MAXV = 510;         //������Ҫ����max�����ı���
int d[MAXV] ; int num[MAXV] ; int w[MAXV] ;//d[]��¼���·����num[]��¼���·��������w[]��¼����Ȩ֮��
int G[MAXV][MAXV];            //����ģ����ֳ�ʼ����ʽ�����⡣��int d[510] = { inf }; int num[510] = { 0 }; int w[510] = { 0 }ֻ�������±�Ϊ0���Ǹ�����
int wei[MAXV] ;
bool vis[MAXV] = { false };//�����Ϳ��ԡ�vis[]��¼�Ƿ���ʹ���
int C1, C2, N, M;//���C1���յ�C2��N�����㣬M����

//���·�������DFS�㷨�������γ����ǣ�vis�����ã���ΪҪ�ظ�����һЩ��㣩�����Ӳ��ţ��ظ������޷���������ì�ܡ�
//DFS�ʺ���ͼ�ı������������еıߣ����еĵ㣬���ʺ�Ѱ�����·����

void Dijsktra(int s) {
	fill(d, d + 510, INF);
	/*fill(w, w + 510, 0);
	fill(num, num + 510, 0);*/  //ȫ�ֱ��������Ժ��ֵ��Ϊ0������û��Ҫ
	d[s] = 0;
	num[s] = 1;
	w[s] = wei[s];
	for (int i = 0; i < N; i++) {//�ҳ�d[]��С�Ľ��
		int u = -1, min = INF;
		for (int j = 0; j < N; j++){
			if (d[j] < min && vis[j] == false) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;     //����ѷ���
		for (int v = 0; v < N; v++){
			if (vis[v] == false && G[v][u] != 0){
				if (d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + wei[v];
					num[v] = num[u];
				}
				else if (d[u] + G[u][v] == d[v]){
					if (w[v] < w[u] + wei[v]){
						w[v] = w[u] + wei[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
bool in[MAXV] = { false }; //��¼�Ƿ��ڶ�����

void SPFA(int s){ //�Ҳ���������ˡ�����֡�
	fill(d, d + 510, INF);
	queue<int> q;
	q.push(s);
	in[s] = true;
	d[s] = 0;
	num[s] = 1;     //num[]��¼���·������
	w[s] = wei[s];
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		in[u] = false;
		for (int v = 0; v < N; v++)//���н�㣬�ҳ���u�����Ľ��
		{
			if (G[u][v] != 0 && d[u] + G[u][v] <= d[v])//u��v��ͨ�ҿ��ɳ�or·����ȣ���������ͬ�����·��ͳ������
			{
				if (d[u] + G[u][v] < d[v])//���ɳ�
				{
					d[v] = d[u] + G[u][v];//�������v�Ƿ��ڶ������Ҫ�����ɳڲ������ڶ�����Ļ���������������·��������Ӱ����䱾����ɳڡ�
					num[v] = num[u];
					w[v] = w[u] + wei[v];
					if (in[v] == false) {//�ҿ�ȥ����İɣ���������˫�Ⱥš�v���ڶ�����ʱ�����²���
						q.push(v);
						in[v] = true;   //��v�ڶ�����
					}
				}
				else if (d[u] + G[u][v] == d[v])//��Ϲ�˰ɡ�·����ȵ����
				{
					num[v] += num[u];    //�Բۣ���������Ӧ�ô�num[u]���̳й���������������
					if (w[v] < w[u] + wei[v])
						w[v] = w[u] + wei[v];
				}
			}
		}
	}
}
int main()
{
	fill(G[0], G[0] + MAXV * MAXV, 0);//ע���ά�����ʼ���ķ�ʽ��G[0]������ʵ���Ҳ����Ҫ����Ϊ��ȫ�ֱ�����
	//fill(wei, wei + MAXV, 0);����Ҫ��
	scanf("%d%d%d%d", &N, &M, &C1, &C2);//�����ʽ%d֮�䲻��Ҫ����
	for (int i = 0; i < N; i++){
		scanf("%d", &wei[i]);
	}
	int c1, c2, l;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &c1, &c2, &l);
		G[c1][c2] = G[c2][c1] = l;
	}
	//Dijsktra(C1);
	SPFA(C1);
	printf("%d %d", num[C2], w[C2]);
}
//ȫ�ֱ���һ��������ʼֵΪ0������bool��int�ȵȡ�
//�����ж�������鲻����ʼ����Ϊĳ�ض�ֵ�������е����鶨���Ժ�{ }��ʼ��ֻ�ı��һ��Ԫ�ص�ֵ������Ķ�Ϊ0������ֻ����{ }��ʼ��Ϊ0��
//bool�ͱ�����trueΪ1��falseΪ0��ֻ����{ }��ʼ��Ϊ0��
/*5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1*/