//这一题超坑，用了substr等字符串有关的函数
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
const int maxn = 50000;

int n;
string a, b;
string suba, subb;
int Aexponent = 0, Bexponent = 0;

void processstring(string t, string &subt, int &exponent) {
	if (t.find_first_not_of('0') == t.npos) {
		subt += "0";
		exponent = 0;
		return;
	}
	t = t.substr(t.find_first_not_of('0'), t.length());//去除高位多的零
	//没有小数点
	if (t.find('.') == t.npos) {
		//字符串长度不够
		if (t.length() <= n) {
			subt = t;
			for (int i = subt.length() + 1; i <= n; i++) {
				subt = subt + '0';
			}
			exponent = t.length();
		}
		//字符串长度够的
		else {
			exponent = t.length();
			subt = t.substr(0, n);
		}
	}
	else {
		for (int i = 0; i <= 100; i++) {//防止字符串不够长
			t = t + '0';
		}
		int postion = t.find('.');
		int nonzero = t.find_first_not_of('0');
		//不是纯小数
		if (nonzero < postion) {
			//整数部分够长了
			if (postion >= n) {
				exponent = postion;
				subt = t.substr(0, n);
			}
			//不够长就加上小数部分
			else {
				exponent = postion;
				subt = t.substr(0, postion) + t.substr(postion + 1, n - postion);
			}
		}
		//是纯小数
		else {
			t = t.substr(postion + 1, t.length());//留下纯小数的部分
			nonzero = t.find_first_not_of('0');
			if (nonzero == t.npos) {
				subt = "0";
				exponent = 0;
				return;
			}
			exponent = 0 - nonzero;
			subt = t.substr(nonzero, n);
		}
	}
}

int main() {
	scanf("%d", &n);
	cin >> a >> b;
	processstring(a, suba, Aexponent);
	processstring(b, subb, Bexponent);
	if (suba == subb && Aexponent == Bexponent) {
		printf("YES 0.");
		if (suba == "0") {
			for (int i = 0; i < n; i++) {
				cout << suba;
			}
		}
		else {
			cout << suba;
		}

		printf("*10^%d", Aexponent);

	}
	else {
		printf("NO 0.");
		cout << suba;
		printf("*10^%d", Aexponent);
		printf(" 0.");
		cout << subb;
		printf("*10^%d", Bexponent);
	}
	system("PAUSE");
}