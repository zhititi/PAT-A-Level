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
//map���÷�
//5��map�����ֱ������������ߡ��ؼ��ʡ������缰���������id��ӳ���ϵ
map<string, set<int>> mpTitle, mpAuthor, mpKey, mpPub, mpYear;
void query(map<string, set<int>>& mp, string& str) {            //��mp�в���str
	if (mp.find(str) == mp.end()) printf("Not Found\n");        //�Ҳ���
	else {                                                      //�ҵ�str
		for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
			printf("%07d\n", *it);                              //���str��Ӧ������id
		}
	}
}
int main() {
	int n, m, id, type;
	string title, author, key, pub, year;
	scanf("%d", &n);                                            //�����Ŀ
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);                 //id
		char c = getchar();                      //���յ�id����Ļ���
		getline(cin, title);                    //��������title
		mpTitle[title].insert(id);             //��id����title��Ӧ�ļ�����
		getline(cin, author);                  //��������author
		mpAuthor[author].insert(id);           //��id����author��Ӧ�ļ�����
		while (cin >> key) {                   //ÿ�ζ��뵥���ؼ���key
			mpKey[key].insert(id);             //��id����key��Ӧ�ļ�����
			c = getchar();                     //���չؼ���key֮����ַ�
			if (c == '\n') break;              //����ǻ��У�˵���ؼ����������
		}
		getline(cin, pub);                     //���������pub
		mpPub[pub].insert(id);                 //��id����pub��Ӧ�ļ�����
		getline(cin, year);                    //�������year
		mpYear[year].insert(id);               //��id����year��Ӧ�ļ�����
	}
	string temp;
	scanf("%d", &m);                           //��ѯ����
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &type);                  //��ѯ����
		getline(cin, temp);                    //����ѯ���ַ���
		cout << type << ": " << temp << endl;  //������ͺ͸��ַ���
		if (type == 1) query(mpTitle, temp);   //��ѯ������Ӧ������id
		else if (type == 2) query(mpAuthor, temp);//��ѯ���߶�Ӧ������id
		else if (type == 3) query(mpKey, temp);//��ѯ�ؼ��ʶ�Ӧ������id
		else if (type == 4) query(mpPub, temp);//��ѯ�������Ӧ������id
		else query(mpYear, temp);              //��ѯ������ֶ�Ӧ������id
	}
	return 0;
}