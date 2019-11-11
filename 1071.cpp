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
map<string, int>ans;
set<string> t;
bool isAlphanumerical(char a) {
	if (a >= '0'&&a <= '9')return 1;
	else if (a >= 'A' && a <= 'Z') return 1;
	else if (a >= 'a'&&a <= 'z')return 1;
	else return 0;
}

bool isUp(char a) {
	if (a >= 'A'&&a <= 'Z')return 1;
	else return 0;
}

char tolow(char a) {
	return a + 'a' - 'A';
}

int main() {
	getline(cin, n);
	string tmp = "";
	for (int i = 0; i < n.length(); i++) {
		if (isAlphanumerical(n[i])) {
			if (isUp(n[i])) {
				n[i] = tolow(n[i]);
			}
			tmp = tmp + n[i];
		}
		else {
			if (ans.find(tmp) == ans.end()&&tmp!="") {
				ans[tmp] = 1;
				tmp = "";
			}
			else if(tmp!=""){
				ans[tmp] += 1;
				tmp = "";
			}
		}
	}
	if (ans.size() == 0) {
		cout << n << " " << 1 << endl;
		return 0;
	}
	int max = -1;
	string index = "";
	for (auto i = ans.begin(); i != ans.end(); i++) {
		if (max < i->second) {
			t.clear();
			max = i->second;
			index = i->first;
			t.insert(i->first);
		}
		if (max == i->second) {
			t.insert(i->first);
		}
	}
	cout << *t.begin() << " " << max << endl;
	system("PAUSE");
}