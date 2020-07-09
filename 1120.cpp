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
map<int, int>friends;
set<int> ans;

int sum(int a) {
	int s = 0;
	s = a % 10;
	if(a>=10){
		s+=sum(a / 10);
	}
	return s;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		friends[sum(tmp)]++;
	}
	for (auto i = friends.begin(); i != friends.end(); i++) {
		if (i->second >= 1) {
			ans.insert(i->first);
		}
	}
	printf("%d\n%d", ans.size(),*ans.begin());
	for (auto i = ++ans.begin(); i != ans.end(); i++) {
		printf(" %d", *i);
	}
	system("PAUSE");
	return 0;
}