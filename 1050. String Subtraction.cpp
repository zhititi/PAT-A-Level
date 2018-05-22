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
char str[10005], str1[10005];
bool hashTable[127];
int main() {
	gets(str);
	gets(str1);
	for (int i = 0; i < strlen(str1); i++) {
		hashTable[str1[i]] = true;
	}
	for (int i = 0; i < strlen(str); i++) {
		if (hashTable[str[i]] == false) {
			printf("%c", str[i]);
		}
	}
	return 0;
}