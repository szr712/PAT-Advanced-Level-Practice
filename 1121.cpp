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
map<int, int>couples;
set<int> ans, guests;



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		couples[a] = b;
		couples[b] = a;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		guests.insert(tmp);
	}
	for (auto i = guests.begin(); i != guests.end(); i++) {
		if (couples.find(*i) == couples.end()) {
			ans.insert(*i);
		}
		else {
			if (guests.find(couples[*i]) == guests.end()) {
				ans.insert(*i);
			}
		}
	}
	if (ans.size() == 0) {
		printf("0\n");
		return 0;
	}
	printf("%d\n%05d", ans.size(),*ans.begin());
	for (auto i = ++ans.begin(); i != ans.end(); i++) {
		printf(" %05d", *i);
	}
	system("PAUSE");
	return 0;
}