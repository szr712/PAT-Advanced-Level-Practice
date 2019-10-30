//此题十分的巧妙，在于比较函数的写法，是比较a+b与b+a的大小，这样能够保证整体字符串是最小的
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n;
vector<string> num;
bool cmp(string a,string b) {
	return a+b < b+a;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end(), cmp);
	bool flag = 0;
	string out;
	for (int i = 0; i < num.size(); i++) {
		out += num[i];
	}
	for (int i = 0; i < out.length(); i++) {
		if (out[i] != '0' && !flag) {
			cout << out[i];
			flag = 1;
		}
		else if (flag == 1) {
			cout << out[i];
		}
	}
	if (!flag) {
		cout << "0";
	}
	system("PAUSE");
}