//在图论中虽然深度优先遍历比广度优先遍历更常用一些，但对于类似于该题目这样的设置了遍历层数上限的题目，广度优先遍历要更加简洁，逻辑也更加清晰
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

int n, l, k;
map<int, vector<int>> tree;
bool used[1005];
int sum;
int level[1005];

void bfs(int root) {
	queue<int >q;
	q.push(root);
	used[root] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < tree[v].size(); i++) {
			if (!used[tree[v][i]] && level[v] < l) {
				sum++;
				used[tree[v][i]] = 1;
				level[tree[v][i]] = level[v] + 1;
				q.push(tree[v][i]);
			}
		}
	}
}

int main() {	
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			int tmp;
			scanf("%d", &tmp);
			tree[tmp].push_back(i);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		memset(used, 0, sizeof(used));
		memset(level, 0, sizeof(level));
		sum = 0;
		int tmp;
		scanf("%d", &tmp);
		bfs(tmp);
		printf("%d\n", sum);
	}
	system("PAUSE");
}