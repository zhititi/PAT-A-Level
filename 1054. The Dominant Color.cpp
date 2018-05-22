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
#include <stack>
using namespace std;
int hashTable[100000000];
int main() {
	int m, n, temp;
	int max = 0, ans;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &temp);
			hashTable[temp]++;
			if (hashTable[temp] > max) {
				max = hashTable[temp];
				ans = temp;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}