//首先要注意，1的时候number不加s，其他内容注意islegal里面的内容
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

int N;
string tmp;
int cnt = 0;
double ans = 0.0;

bool islegal() {
	//判断有没有出现除了数字，负号和小数点外的字符
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '-'&&i == 0) {
			continue;
		}
		if (tmp[i] == '.') {
			continue;
		}
		if (tmp[i] > '9' || tmp[i] < '0') {
			return false;
		}
	}
	//判断是不是只有一个‘.’或者‘-’
	if (tmp.length() == 1 && (tmp[0] == '.'||tmp[0]=='-')) {
		return false;
	}
	//判断有没有出现两个以上的负号或小数点
	if (count(tmp.begin(), tmp.end(), '-') >= 2 || count(tmp.begin(), tmp.end(), '.') >= 2) {
		return false;
	}
	//判断有没有两位以上小数,前提需要判断小数点存不存在
	if (tmp.find('.')!=tmp.npos) {
		if (tmp.length() - tmp.find('.') > 3) {
			return false;
		}
	}
	
	//判断有没有超出目标范围
	double t = stod(tmp);
	if (t < -1000 || t>1000) {
		return false;
	}
	return true;
}


int main() {
	scanf("%d", &N);
	while (N--)
	{
		cin >> tmp;
		if (islegal()) {
			double t = stod(tmp);
			ans += t;
			cnt++;
		}
		else {
			printf("ERROR: ");
			cout << tmp;
			printf(" is not a legal number\n");
		}
	}
	if (cnt == 0) {
		printf("The average of 0 numbers is Undefined");
	}
	else if (cnt == 1) {
		printf("The average of %d number is %.2lf", cnt, ans / (double)cnt);
	}
	else
	{
		printf("The average of %d numbers is %.2lf", cnt, ans / (double)cnt);
	}
	system("PAUSE");
	return 0;
}