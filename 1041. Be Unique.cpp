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
//ɢ�е�Ӧ�á�
int hashTable[10005];
int id[100005];
int main() {
	int n;
	scanf("%d", &n);
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		id[i] = temp;
		hashTable[temp]++;    //��������Ϊhash����
	}
	for (int i = 0; i < n; i++) {
		if (hashTable[id[i]] == 1) {
			printf("%d\n", id[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}