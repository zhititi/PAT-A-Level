#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
/*
ȷ����֪���е�value
ȷ��radix�������ޣ�����Ϊδ֪���е����Ԫ��ֵ+1������Ϊ�����ޣ�value���нϴ��һ��
���ֲ���radix��ֵ
����Ӧд��ǰ�����Ҫ����
������ҪһЩ������ַ���ת���Ƚϣ�������Ӻ�����д
*/
struct Node {//��ʵû��Ҫд�ṹ�����飬���ý������е�λ�ã�ʹ�ṹ����ࡣ����ֱ����string x[2]������Ϊ��ǣ����������������������١�
	string num;
	long long index = 0;
	long long value;
};
Node x[2];
long long change(string a, long long radix)//��string��indexת��Ϊֵ
{
	long long ans = 0;
	int temp;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] <= '9') {
			temp = a[i] - '0';
		}
		else {
			temp = a[i] - 'a' + 10;
		}
		ans = ans*radix + temp;//��=����+=���������ӣ�������д�������ǰ��������ַ����ó���ֵ��attention����
	}
	return ans;
}
long long cmp(string a, long long radix, long long value)//�Ƚ�a��radix������ֵ��value��Ƚϡ�
{
	long long ans = 0;
	long long temp = change(a, radix);
	//cout <<a<<' '<<radix<<' '<< temp << endl;
	if (temp<0 || temp>value) {   //������ߴ���value
		return -1;
	}
	else if (temp == value) return 0;
	else return 1;  //tempС��value
}
long long binarysearch(string a, long long value, long long left, long long right) {
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		//cout << mid << endl;
		int temp = cmp(a, mid, value);
		if (temp == 0) return mid;
		else if (temp == -1) right = mid - 1;
		else if (temp == 1) left = mid + 1;
	}
	return -1;
}
int main()
{
	long long flag = 0, ind;//flag�����ĸ�index��֪
	cin >> x[0].num >> x[1].num >> flag >> ind;
	if (flag == 2) {
		string m;
		m = x[0].num;
		x[0].num = x[1].num;
		x[1].num = m;
	}
	long long value = change(x[0].num, ind);//x[0].num����֪��
	string num = x[1].num;            //numΪ���У�valueΪĿ��ֵ�����0д��1�ˡ���
	long long radix;

	char max = '0';   //���´���ȷ��radix��������
	for (int i = 0; i < num.length(); i++) {
		if (num[i] > max) max = num[i];
	}
	long long left;
	if (max <= '9') {//num[0]����Ӧ����maxô������
		left = max - '0' + 1;  //left��¼index������
	}
	else {
		left = max - 'a' + 10 + 1;
	}
	long long right = value > left ? value : left;
	right++;

	/*cout << num << ' ' << value << endl;
	cout << left << ' ' << right << endl;*/
	long long ans = binarysearch(num, value, left, right);
	if (ans == -1) printf("Impossible");
	else printf("%d", ans);
}
