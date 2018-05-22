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
	char name[20];
	int age;
	int worth;
}people[100005];
struct query {
	int num;
	int Amin, Amax;
}queries[10005];
int n, k;
bool cmp1(G a, G b) {
	return a.age < b.age;
}
bool cmp2(G a, G b) {
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d", &people[i].name, &people[i].age, &people[i].worth);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &queries[i].num, &queries[i].Amin, &queries[i].Amax);
	}
	sort(people, people + n, cmp1);
	vector<G> processing;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (people[j].age <= queries[i].Amax&&people[j].age >= queries[i].Amin) {
				processing.push_back(people[j]);
			}
		}
		printf("Case #%d:\n", i + 1);
		if (processing.size() == 0) {
			printf("None\n"); continue;
		}
		sort(processing.begin(), processing.end(), cmp2);
		for (int j = 0; j < queries[i].num; j++) {
			if (j > processing.size() - 1) continue;
			printf("%s %d %d\n", processing[j].name, processing[j].age, processing[j].worth);
		}
		processing.clear();
	}
	return 0;
}