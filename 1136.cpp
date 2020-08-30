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
string n;

string add(string a) {
	string b = a;
	reverse(a.begin(), a.end());
	int flag = 0;
	string ans = "";
	for (int i = a.length() - 1; i >= 0; i--) {
		int tmp = a[i] - '0' + b[i] - '0' + flag;
		if (tmp >= 10) {
			flag = 1;
			tmp = tmp % 10;
		}
		else
		{
			flag = 0;
		}
		ans = char(tmp + '0') + ans;
	}
	if (flag == 1) {
		ans = "1" + ans;
	}
	return ans;
}


int main() {
	cin >> n;
	bool flag = false;
	string m = n;
	reverse(m.begin(), m.end());
	if (m == n) {
		printf("%s is a palindromic number.", n.c_str());
		return 0;
	}
	for (int i = 1; i <= 10; i++) {
		string tmp = add(n);
		string t = n;
		reverse(t.begin(), t.end());
		printf("%s + %s = %s\n", n.c_str(), t.c_str(), tmp.c_str());
		string x = tmp;
		reverse(tmp.begin(), tmp.end());
		if (x == tmp) {
			flag = true;
			printf("%s is a palindromic number.", x.c_str());
			break;
		}
		n = x;
	}
	if (!flag) printf("Not found in 10 iterations.\n");
	
	system("PAUSE");
	return 0;
}