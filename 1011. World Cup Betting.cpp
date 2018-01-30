#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int main() {
	float x[3][3];
	int res[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		float max = 0;
		for (int j = 0; j < 3; j++) {
			cin >> x[i][j];
			if (x[i][j] > max) {
				max = x[i][j];//อüะดมหกฃกฃ
				res[i] = j;
			}
		}
		//cout << res[i] << endl;
	}
	for (int i = 0; i < 3; i++) {
		if (res[i] == 0) printf("W ");
		else if (res[i] == 1) printf("T ");
		else if (res[i] == 2) printf("L ");
	}
	float ans = (x[0][res[0]] * x[1][res[1]] * x[2][res[2]] * 0.65 - 1) * 2;
	printf("%.2f",ans);
}