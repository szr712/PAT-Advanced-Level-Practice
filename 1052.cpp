/*
这道题坑点很多
首先是有可能一开始n就是0
然后有可能给出的结点不是全部都在链表中
最后一个最坑 就是可能给出的起始地址不在给出的结点的中
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
using namespace std;

int n;
map<int, pair<int, int>> link;
map<int, int> ans;
int start;

int main() {
	scanf("%d %d", &n, &start);
	if (n == 0) {
		printf("%d %05d\n", n, start);
		system("pause");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int a, next;
		int key;
		scanf("%d %d %d", &a, &key, &next);
		link[a].first = key;
		link[a].second = next;
	}
	if (link.find(start) == link.end()) {
		cout << 0 << " " << -1;
		system("pause");
		return 0;
	}
	while (start != -1) {
		ans[link[start].first] = start;
		start = link[start].second;
	}
	start = ans.begin()->second;
	printf("%d %05d\n", ans.size(), start);
	auto i = ans.begin();
	while (i != ans.end()) {
		printf("%05d %d", i->second, i->first);
		i++;
		if (i != ans.end()) {
			printf(" %05d\n", i->second);
		}
		else {
			printf(" -1\n");
		}
	}
	system("PAUSE");
}