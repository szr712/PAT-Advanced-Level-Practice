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
int father[10005],cnt[10005];
bool visit[10005];

int find(int x) {
	if (father[x] == x) {
		return x;
	}
	else
	{
		father[x] = find(father[x]);
		return father[x];
	}
}

void unite(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	father[fa] = fb;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 10005; i++) {
		father[i] = i;
		visit[i] = 0;
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int k,id;
		scanf("%d %d", &k,&id);
		visit[id] = 1;
		for (int j = 1; j < k; j++) {
			int tmp;
			scanf("%d", &tmp);
			unite(id, tmp);
			visit[tmp] = 1;
		}
	}
	for (int i = 0; i < 10005; i++) {
		if (visit[i]) {
			int root = find(i);
			cnt[root]++;
		}
	}
	int tree = 0, bird = 0;
	for (int i = 0; i < 10005; i++) {
		if (cnt[i] != 0) {
			tree++;
			bird += cnt[i];
		}
	}
	printf("%d %d\n", tree, bird);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (find(a) == find(b)) {
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	system("PAUSE");
	return 0;
}