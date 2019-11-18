/*
string两个查找函数有所不同：
find(): 查找字符串中第一次出现字符c、字符串s的位置；
find_first_of(): 查找字符串中字符c、字符数组s中任意一个字符第一次出现的位置。
*/
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

int n;
string ans, tmp;

int main() {
	scanf("%d\n", &n);
	getline(cin, ans);
	for (int i = 1; i < n; i++) {
		getline(cin, tmp);
		string ta = "";
		int l = ans.length();
		while (l > 0) {
			int j = 0;
			bool flag = 0;
			for (; j + l <= ans.length(); j++) {
				ta = ans.substr(j, l);
				int t = tmp.find(ta);
				if (t != tmp.npos) {
					flag = 1;
					break;
				}
			}
			if (flag) break;
			ta = "";
			l--;
		}
		ans = ta;
	}
	if (ans.length() == 0) {
		cout << "nai" << endl;
	}
	else cout << ans;
	system("PAUSE");
}