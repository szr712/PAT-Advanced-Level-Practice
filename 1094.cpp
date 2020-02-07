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

map<int, vector<int>> tree;
map<int, int> gen;
int n,m;

void dfs(int id, int level) {
	for (int i = 0; i < tree[id].size(); i++) {
		gen[level]++;
		dfs(tree[id][i], level+1);
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int k,id;
		scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			int t;
			scanf("%d", &t);
			tree[id].push_back(t);
		}
	}
	gen[1] = 1;
	dfs(1, 2);
	/*for (auto it = tree.begin(); it != tree.end(); it++) {
		printf("%d ", it->first);
		for (int i = 0; i < it->second.size(); i++) {
			printf("%d ", it->second[i]);
		}
		printf("\n");
	}*/
	int max = -1,tl=0;
	for (auto it = gen.begin(); it != gen.end(); it++) {
		//printf("%d %d\n", it->first, it->second);
		if (max < it->second) {
			max = it->second;
			tl = it->first;
		}
	}
	printf("%d %d", max, tl);
	system("PAUSE");
}