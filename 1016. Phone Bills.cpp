#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int rate[24];//记录费率
int record;  //有记录的数量
int num = 0; //总人数
map<int, string> intToString;
map<string, int> stringToInt;
struct G {
	int onlinet[1000];
	int offlinet[1000];
	int onlinect = 0;
	int offlinect = 0;
	int mix[2010];
	int resOn[1005];
	int resOff[1005];
	int resct = 0;
}ID[1005], ID1[1005];
int change(string str) {
	if (stringToInt.find(str) != stringToInt.end()) //map容器中find的用法：失配时返回map.end()
	{
		return stringToInt[str];
	}
	else {//失配，没找到
		stringToInt[str] = num;
		intToString[num] = str;
		//cout << intToString[num] << endl;
		return num++;
	}
}
int timetoint(string str) {
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ':') {
			sum = sum * 10 + str[i] - '0';
		}
	}
	return sum;
}
bool judge(string str) {
	if (str[1] == 'n') {
		return true;
	}
	else return false;
}
void output(int time) {
	int dd, hh, mm;
	mm = time % 100;
	hh = (time / 100) % 100;
	dd = (time / 10000) % 100;
	printf("%02d:%02d:%02d", dd, hh, mm);
}
//dd:hh:mm
void calculate(int on, int off, int&time, int&value) {
	long long a1 = (on % 100) + ((on / 100) % 100) * 60 + ((on / 10000) % 100) * 24 * 60;
	long long a2 = (off % 100) + ((off / 100) % 100) * 60 + ((off / 10000) % 100) * 24 * 60;
	time = a2 - a1;
	int i = on;
	while(i<off) {
		//cout << i << ' ' << value << endl;
		if (i % 100 == 59) {
			value += rate[(i / 100) % 100];
			i += 41;
			continue;
		}
		else if (i % 100 == 0) { //新的一个小时
			if ((i / 100) % 100 >= 24) {
				i = i - 2400 + 10000;
			}
			if (i + 100 <= off) {
				value += 60 * rate[(i / 100) % 100];
				i = i + 100;
			}
			else {
				value += rate[(i / 100) % 100];
				i++;
			}
		}
		else {
			value += rate[(i / 100) % 100];
			i++;
		}
	}
	//cout << i << ' ' << value << endl;
}
int main() {
	for (int i = 0; i < 24; i++) {
		cin >> rate[i];
	}
	cin >> record;
	string id, strtime, onoroff;
	for (int i = 0; i < record; i++) {
		cin >> id >> strtime >> onoroff;
		int temp = change(id);
		int time = timetoint(strtime);
		if (judge(onoroff) == true) {
			ID[temp].onlinet[ID[temp].onlinect++] = time;
		}
		else {
			ID[temp].offlinet[ID[temp].offlinect++] = time;
		}
	}
	for (int i = 0; i < num; i++) {
		int count = 0;
		for (int j = 0; j < ID[i].onlinect; j++) {
			ID[i].mix[count++] = ID[i].onlinet[j];
		}
		for (int j = 0; j < ID[i].offlinect; j++) {
			ID[i].mix[count++] = ID[i].offlinet[j];
		}
		//cout << count << endl;
		//cout << ID[i].onlinect+ ID[i].offlinect << endl;
		sort(ID[i].mix, ID[i].mix + count);
		sort(ID[i].onlinet, ID[i].onlinet + ID[i].onlinect);
		sort(ID[i].offlinet, ID[i].offlinet + ID[i].offlinect);
		for (int j = 0; j < ID[i].onlinect; j++) {
			for (int k = 0; k < count - 1; k++) {
				if (ID[i].mix[k] == ID[i].onlinet[j]) {//找到
					if (j == ID[i].onlinect - 1) {             //最后一个
						ID[i].resOn[ID[i].resct] = ID[i].mix[k];
						ID[i].resOff[ID[i].resct] = ID[i].mix[k + 1];
						ID[i].resct++;
					}
					else if (ID[i].onlinet[j + 1] != ID[i].mix[k + 1]) {//有匹配
						ID[i].resOn[ID[i].resct] = ID[i].mix[k];
						ID[i].resOff[ID[i].resct] = ID[i].mix[k + 1];
						ID[i].resct++;
					}
					continue;
				}
			}
		}
	}
	//cout << ID[2].resOn[0] << ' ' << ID[2].resOff[0] <<' '<< ID[2].resct << endl;
	int order[1005], ct = 0;
	bool vis[1005] = { false };
	for (int i = 0; i < num; i++) {
		int min = 99999999, temp = -1;
		for (int j = 0; j < num; j++) {
			if (ID[j].resOn[0] > 0&&ID[j].resOn[0] < min&&vis[j] == false) {
				min = ID[j].resOn[0];
				temp = j;
			}
		}
		if (temp == -1) break;//找不到
		//cout << min << endl;
		order[i] = temp;
		vis[temp] = true;
		ct++;
	}
	//cout << ct;
	//cout << order[0] << ' ' << order[1] << ' ' << order[2];
	/*for (map<int, string>::iterator it = intToString.begin(); it != intToString.end(); it++) {
		cout << it->second << endl;
	}*/
	int total = 0;
	for (int i = 0; i < ct; i++) {     //每个人
		for (int j = 1; j <= 12; j++) { //每个月
			bool flag = false;
			for (int k = 0; k < ID->resct; k++) {
				if (ID[order[i]].resOn[k] / 1000000 == j) {
					if (flag == false) {
						cout << intToString[order[i]];
						printf(" %02d\n", j);
						flag = true;
					}
					output(ID[order[i]].resOn[k]);
					printf(" ");
					output(ID[order[i]].resOff[k]);
					printf(" ");
					int t, v = 0;
					calculate(ID[order[i]].resOn[k], ID[order[i]].resOff[k], t, v);
					float temp = v * 0.01; //两个int数相除，结果还是int，所以这里只能 *
					printf("%d $%.2f", t, temp);
					//printf("%d $%d.%02d", t, v / 100, v % 100);
					printf("\n");
					total += v;
					v = 0;//???????????
				}
			}
			if (total!=0) {
				float temp = total * 0.01;
				printf("Total amount: $%.2f\n", temp);
				//printf("Total amount: $%d.%02d\n", total / 100, total % 100);
				total = 0;
			}
		}
	}
}
/*10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line*/