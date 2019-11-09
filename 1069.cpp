//注意题目描述的输入数据类型，虽然本题一直在说是四位数，但是说的是用整数输入，就意味着可能有个位数两位数三位数
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

char n[5];
bool cmp(char a, char b)
{
	return a < b;
}
bool cmp2(char a, char b) {
	return a > b;
}

int char2int(char *a) {
	int x = 0;
	for (int i = 0; i < strlen(a); i++) {
		char tmp = a[i] - '0';
		x += tmp * pow(10,(strlen(a) - i - 1));
	}
	return x;
}

void int2char(int a,char x[]) {
	for (int i = 0; i < 4; i++) {
		int t = pow(10, 3 - i);
		x[i] = a / t + '0';
		a %= t;
	}
}

int main() {
	int t;
	cin >> t;
	int2char(t, n);
	sort(n, n + 4, cmp2);
	char x[5];
	strcpy(x, n);
	sort(x, x + 4, cmp);
	int p, q;
	p = char2int(n);
	q = char2int(x);
	int dev = 0;
	if (p == q) {
		printf("%04d - %04d = 0000\n", p, p);
	}
	else {
		while (dev != 6174) {
			dev = p - q;
			printf("%04d - %04d = %04d\n", p, q, dev);
			int2char(dev, n);
			sort(n, n + 4, cmp2);
			strcpy(x, n);
			sort(x, x + 4, cmp);
			p = char2int(n);
			q = char2int(x);
		}

	}
	system("PAUSE");
}