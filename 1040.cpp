//很简单，不断反转需要判断的字符串部分，然后与原来的字符串比对
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int main() {
	string ans;
	getline(cin, ans);
	//cout << ans;
	int i;
	for (i = ans.length();i >= 1; i--) {
		for (int j = 0; j + i <= ans.length(); j++) {
			string tmp = ans;
			reverse(tmp.begin() + j, tmp.begin() + i + j);
			if (tmp == ans) {
				printf("%d", i);
				system("PAUSE");
				return 0;
			}
		}
	}
	
}