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


int k;
string in, ans;
map<char, queue<int>> all;
set<char> stu;
map<char,bool> flag;

int main() {
	cin >>k>> in;
	for (int i = 0; i < in.length(); i++){
		all[in[i]].push(i);
	}
	for (auto i = all.begin(); i != all.end(); i++) {
		while (!i->second.empty()) {
			if (i->second.size() < k) {
				break;
			}
			int t = i->second.front();
			i->second.pop();
			int j;
			for (j = 1; j < k; j++) {
				if (t + 1 != i->second.front()) {
					break;
				}
				i->second.pop();
				t++;
			}
			if (j != k) {
				break;
			}

		}
		if (i->second.empty()) {
			stu.insert(i->first);
			flag[i->first] = 0;
		}
	}
	for (int i = 0; i < in.length(); i++) {
		if (stu.find(in[i]) != stu.end()) {
			if (!flag[in[i]]) {
				printf("%c", in[i]);
				flag[in[i]] = 1;
			}
			ans = ans + in[i];
			i += k;
			i--;

		}
		else {
			ans = ans + in[i];
		}
	}
	printf("\n");
	cout << ans;

	system("PAUSE");
	return 0;
}