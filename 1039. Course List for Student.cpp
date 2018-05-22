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
//ɢ�У����������ϵ
const int N = 40000;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[M];

int getID(char name[]) {   //hash���������ַ���nameת�������֣�����ѧ��IDת��������
	int id = 0;
	for (int i = 0; i < 3; i++) {  //ǰ��λ��д��ĸ
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');  //���һλ����
	return id;
}

int main() {
	char name[5];
	int n, k;         //nΪ��ѯ����������kΪ�ܿγ���
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int course, x;  //�ֱ�Ϊ�γ̱�ţ�ѡ������
		scanf("%d%d", &course, &x);
		for (int j = 0; j < x; j++) {  //����ѡ�����������˵�����������֮ת��Ϊ��ţ����ÿγ̱��װ���˱�ŵ�ɢ��
			scanf("%s", name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}
	for (int i = 0; i < n; i++) {   //�����ѯ���ˣ����������Ϊ���������룬û�лس����У����Կ��Ա���������
		scanf("%s", name);
		int id = getID(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		printf("%s %d", name, selectCourse[id].size());
		for (int j = 0; j < selectCourse[id].size(); j++) {
			printf(" %d", selectCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
}