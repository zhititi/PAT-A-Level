#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
queue<int> q[20];//���������±�0-19
int N, M, K, Q;//N�����ڣ����������M���ˣ��ܹ�K���ˣ���Q������ʱ��
int processTime[1005];//ÿ���˴���ʱ�䣬�±�0-K
int ques[1005];
int ans[1005];        //��¼ÿ���˽�����ʱ��
int front[20];        //��¼���ڴ�����˵ı��
int totalTime[20];    //��totalTime��С��ȷ����һ�����ĸ�����
int in = 1, out = 0;  //in��ʾ��һ��Ҫ������еģ�out��ʾ�뿪���е�����
//��ʵ������vector����
void compute() {
	/*for (int i = 0; i < N; i++) {
		if (!q[i].empty()) {
			totalTime[i] += processTime[q[i].front()];
			ans[q[i].front()] += processTime[q[i].front()];
		}
	}*/
	while (out <= K) {
		int min = 1000000, temp = -1;
		for (int i = 0; i < N; i++) {
			if (totalTime[i] < min && totalTime[i] != -1) {
				min = totalTime[i];
				temp = i;           //ӵ�е�ǰ�����ʱ����С�Ķ��е��±꣬���¸�����ӵĽ��б�־
			}
		}
		if (temp == -1) {//�Ҳ�����totaltimeȫΪ0�ˡ�
			return;
		}
		//totaltime[i]��¼i�Ŵ��ڵ�ǰ�ͻ��������ʱ�䣬������endTime[]���ܸ���һЩ��
		//����temp, now��˵�����ǡ���ʼ����
		if (!q[temp].empty()) {
			if (min == 0) {      //���û���������ʼ����1ʱ������5����ˣ��൱��ÿ��3����
				int now = q[temp].front(); 
				q[temp].pop();
				out++;
				totalTime[temp] += processTime[now];
				ans[now] = totalTime[temp];
				continue;
			}
			int now = q[temp].front();     //tempΪ�����±꣬nowΪ�˵��±ꡣ
			q[temp].pop();
			out++;
			if (in <= K) {
				q[temp].push(in++);
			}
			//cout << temp << ' ' << in - 1 << endl;
			if (totalTime[temp] >= 540) ans[now] = -1;
			else {
				totalTime[temp] += processTime[now];
				ans[now] = totalTime[temp];
			}
			//cout << temp << ' ' << now << ' ' << in-1<<' '<< ans[now] << endl;
		}
		else { //���п��ˣ��Ͳ�����������
			totalTime[temp] = -1;
		}
	}
}
void disp(int a) {
	if (a < 0) {
		printf("Sorry\n");
		return;
	}
	int h = 8, m = 0;
	h += a / 60;
	m += a % 60;
	printf("%02d:%02d\n", h, m);
}
int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &processTime[i]);
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &ques[i]);
	}
	for (int i = 0; i < M; i++) {//�������ܶ���˷Ž�����
		for (int j = 0; j < N; j++) {
			if (in <= K) q[j].push(in++);
		}
	}
	compute();
	for (int j = 0; j < Q; j++) {
		disp(ans[ques[j]]);
	}
}