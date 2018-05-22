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
//散列思想
int hashTable[10005];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		hashTable[temp]++;
	}
	int m1 = (m + 1) / 2;   //设为(m+1)/2
	bool flag = false;
	int i;
	for (i = 0; i <= m1; i++) {
		if (m != 2 * i &&hashTable[i] > 0 && hashTable[m - i] > 0) {
			flag = true;
			break;
		}
		else if (m == 2 * i&&hashTable[i] > 1) {
			flag = true;
			break;
		}
	}
	if (flag == true) {
		printf("%d %d", i, m - i);
	}
	else {
		printf("No Solution");
	}
	return 0;
}