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
//map的用法
//5个map变量分别建立书名、作者、关键词、出版社及出版年份与id的映射关系
map<string, set<int>> mpTitle, mpAuthor, mpKey, mpPub, mpYear;
void query(map<string, set<int>>& mp, string& str) {            //在mp中查找str
	if (mp.find(str) == mp.end()) printf("Not Found\n");        //找不到
	else {                                                      //找到str
		for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
			printf("%07d\n", *it);                              //输出str对应的所有id
		}
	}
}
int main() {
	int n, m, id, type;
	string title, author, key, pub, year;
	scanf("%d", &n);                                            //书的数目
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);                 //id
		char c = getchar();                      //接收掉id后面的换行
		getline(cin, title);                    //读入书名title
		mpTitle[title].insert(id);             //把id加入title对应的集合中
		getline(cin, author);                  //读入作者author
		mpAuthor[author].insert(id);           //把id加入author对应的集合中
		while (cin >> key) {                   //每次读入单个关键词key
			mpKey[key].insert(id);             //把id加入key对应的集合中
			c = getchar();                     //接收关键词key之后的字符
			if (c == '\n') break;              //如果是换行，说明关键词输入结束
		}
		getline(cin, pub);                     //输入出版社pub
		mpPub[pub].insert(id);                 //把id加入pub对应的集合中
		getline(cin, year);                    //输入年份year
		mpYear[year].insert(id);               //把id加入year对应的集合中
	}
	string temp;
	scanf("%d", &m);                           //查询次数
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &type);                  //查询类型
		getline(cin, temp);                    //欲查询的字符串
		cout << type << ": " << temp << endl;  //输出类型和该字符串
		if (type == 1) query(mpTitle, temp);   //查询书名对应的所有id
		else if (type == 2) query(mpAuthor, temp);//查询作者对应的所有id
		else if (type == 3) query(mpKey, temp);//查询关键词对应的所有id
		else if (type == 4) query(mpPub, temp);//查询出版社对应的所有id
		else query(mpYear, temp);              //查询出版年分对应的所有id
	}
	return 0;
}