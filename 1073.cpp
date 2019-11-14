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

string a, num;

int main() {
	cin >> a;
	bool flag = 0, ex = 0;
	if (a[0] == '+') flag = 1;
	if (a.find_last_of('+') != a.npos&&a.find_last_of('+') != 0) {
		ex = 1;
	}
	int exponent = 0;
	string e = a.substr(a.find_first_of('E') + 2, a.length() - a.find_first_of('E') + 2);
	exponent = stoi(e);
	if (!ex) exponent -= 0;
	string num = a.substr(1, a.find_first_of('E') - 1);
	if (!ex) {
		if (!flag) {
			printf("-");
		}
		printf("0.");
		for (int i = 0; i < exponent - 1; i++) {
			printf("0");
		}
		for (int i = 0; i < num.length(); i++) {
			if (num[i] != '.') {
				cout << num[i];
			}
		}
	}
	else {
		if (!flag) {
			printf("-");
		}
		int t = 0;
		int i;
		cout << num[0];
		for (i = 2; t != exponent; i++) {
			if (i < num.length()) {
				cout << num[i];
				t++;
			}
			else {
				cout << 0;
				t++;
			}
		}
		if (i < num.length()) {
			cout << ".";
			for (; i < num.length(); i++) {
				cout << num[i];
			}
		}
	}
	system("PAUSE");
}