#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int G[1005][1005];//���ھ���
int check[1005];
bool vis[1005] = { false };//��ʾ�Ƿ���ʹ�
int n, m, sum;//nΪ��������mΪ·������sumΪ��Ҫ���ҵĸ���
void manage(int num) {
	vis[num] = true;
	for (int i = 1; i < n + 1; i++) {//����i�����
		if (vis[i] == false && G[num][i] != 0) {//����ֻ��Ҫͳ����ͨ��ĸ��������Կ�������д������Ҫ�������бߣ���ο����´���
			manage(i);
		}
	}
	return;
}
/*for (int i = 0; i < n; i++) {   //ÿ��㶼�ж�
	if (G[num][i] > 0) {          //֮����ڱ�
		totalValue += G[num][i];       //�ܵ绰ʱ��++������
		G[num][i] = G[i][num] = 0;    //��0����ֹ�ظ������ߣ���Ϊ��ʱû���ж�vis[]
		if (vis[i] == false) { 
			DFS(i);
		}
	}
}*/
int main() 
{
	cin >> n >> m >> sum;
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		scanf("%d%d", &temp1, &temp2);
		G[temp1][temp2] = G[temp2][temp1] = 1;
	}
	for (int i = 0; i < sum; i++) {
		scanf("%d", &check[i]);//check[]�����¼���±�
	}
	for (int i = 0; i < sum; i++) {//����ÿһ��������Ľ��
		int count = 0;//count��¼����ͨ��Ƭ�ĸ���
		vis[check[i]] = true;
		for (int j = 1; j < n + 1; j++) {//ÿ�����
			if (vis[j] == false) {
				manage(j);//manage������һ��������ӵ�һ����ͨƬ������������Ԫ�ص�vis��true
				count++;
			}
		}
		printf("%d\n", count - 1);
//		vis[1005] = { false };����������
		for (int j = 0; j < n + 1; j++) {
			vis[j] = false;
		}
	}
}
/*ͼ�ı����У����Ƶ��ǣ����һ��ÿ������ѭ�����Լ���ǽ���Ƿ񱻷��ʹ���vis����(vis==false)��ÿ�������δ����������봦
���ڣ�DFS���ݹ�ʵ�֣���BFS���ö��У�������ý�����������н�㣬����vis��Ϊtrue�������Ҫ����Դ���(�Ƿ���Ҫ�������б�
�ᵼ��д����ͬ)��*/