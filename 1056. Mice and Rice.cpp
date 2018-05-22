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
struct G {
	int rank;   //��������
	int score;
	//int order;  //����˳��
}mem[100010];
int Np, Ng;
map<int, int> mp;
int findMax(queue<int> q) {//�ҵ�����������Ԫ�ص��±�
	int index, max = -1;
	for (int i = 0; i < Ng; i++) {
		if (!q.empty()) {
			if (mem[q.front()].score > max) {
				max = mem[q.front()].score;
				index = q.front();
			}
			q.pop();
		}
		else continue;
	}
	return index;
}

int main() {
	scanf("%d%d", &Np, &Ng);
	for (int i = 0; i < Np; i++) {
		scanf("%d", &mem[i].score);
	}
	int order[100010];  //����˳��
	queue<int> now, next;
	for (int i = 0; i < Np; i++) {
		scanf("%d", &order[i]);
		now.push(order[i]);
	}
	int rank = 1;
	while (!now.empty()) {
		if (now.size() == 1) {
			mem[now.front()].rank = rank;
			mp[rank] = next.size() + 1;
			now.pop();
			break;
		}
		while (!now.empty()) {    //һ�ִ����ҵ����ķ���next�������е���
			int max = findMax(now);
			next.push(max);
			for (int i = 0; i < Ng; i++) {
				if (!now.empty()) {
					if (now.front() == max) {
						now.pop(); continue;
					}
					else {
						mem[now.front()].rank = rank;
						now.pop();
					}
				}
				else continue;
			}
		}
		mp[rank] = next.size() + 1;
		now = next;
		while (!next.empty()) next.pop();
		rank++;
	}		
	printf("%d", mp[mem[0].rank]);
	for (int i = 1; i < Np; i++) {
		printf(" %d", mp[mem[i].rank]);
	}
}