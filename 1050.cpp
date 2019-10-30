//用到整行输入
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
using namespace std;

string s1,s2;
set<char> sub;

int main() {
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.length(); i++) {
		char tmp = s2[i];
		sub.insert(tmp);
	}
	for (int i = 0; i < s1.length(); i++) {
		char tmp = s1[i];
		if (sub.find(tmp) == sub.end()) {
			printf("%c", tmp);
		}
	}
	system("PAUSE");
}