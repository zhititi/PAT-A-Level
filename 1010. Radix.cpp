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
确定已知序列的value
确定radix的上下限，下限为未知序列的最大元素值+1，上限为（下限，value）中较大的一个
二分查找radix的值
函数应写在前面否则要声明
这种需要一些处理的字符串转换比较，最好用子函数来写
*/
struct Node {//其实没必要写结构体数组，巧用交换已有的位置，使结构更简洁。这里直接用string x[2]更好因为不牵扯多个变量，变量数量较少。
	string num;
	long long index = 0;
	long long value;
};
Node x[2];
long long change(string a, long long radix)//将string和index转化为值
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
		ans = ans*radix + temp;//是=不是+=！！猪脑子！！这种写法允许从前往后遍历字符串得出其值，attention！！
	}
	return ans;
}
long long cmp(string a, long long radix, long long value)//比较a和radix产生的值与value相比较。
{
	long long ans = 0;
	long long temp = change(a, radix);
	//cout <<a<<' '<<radix<<' '<< temp << endl;
	if (temp<0 || temp>value) {   //溢出或者大于value
		return -1;
	}
	else if (temp == value) return 0;
	else return 1;  //temp小于value
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
	long long flag = 0, ind;//flag表明哪个index已知
	cin >> x[0].num >> x[1].num >> flag >> ind;
	if (flag == 2) {
		string m;
		m = x[0].num;
		x[0].num = x[1].num;
		x[1].num = m;
	}
	long long value = change(x[0].num, ind);//x[0].num是已知的
	string num = x[1].num;            //num为序列，value为目标值，妈的0写成1了。。
	long long radix;

	char max = '0';   //以下代码确定radix的上下限
	for (int i = 0; i < num.length(); i++) {
		if (num[i] > max) max = num[i];
	}
	long long left;
	if (max <= '9') {//num[0]？不应该是max么。。。
		left = max - '0' + 1;  //left记录index的下限
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
