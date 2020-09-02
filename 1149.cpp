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

int n, m;
set<int> pairs[100005];


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pairs[a].insert(b);
		pairs[b].insert(a);
	}
	while(m--){
		int k;
		scanf("%d", &k);
		set<int> notin;
		bool flag = 1;
		for (int i = 0; i < k; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (flag) {
				if (notin.find(tmp) != notin.end()) flag = 0;
				else
				{
					for (auto iter = pairs[tmp].begin(); iter != pairs[tmp].end(); iter++) {
						notin.insert(*iter);
					}
				}
			}
		}
		if (flag)printf("Yes\n");
		else printf("No\n");

	}
	system("PAUSE");
	return 0;
}