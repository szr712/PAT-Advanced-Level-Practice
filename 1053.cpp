//对path的排序与网上代码有点不同，是直接控制dfs的顺序来保证输出的顺序
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

struct node
{
	int weight;
	int id;
};

int n, m;
long long s;
map<int, vector<node>> tree;
vector<int> weight;
int start;

bool cmp(node a, node b) {
	return a.weight > b.weight;
}

void find(vector<int> path,long long sum,int root) {
	sum = sum + weight[root];
	path.push_back(weight[root]);
	if (tree.find(root) == tree.end()&& sum==s) {//一定要保证是叶子，也就是在tree中没有child的结点
		printf("%d", path[0]);
		for (int i = 1; i < path.size(); i++) {
			printf(" %d", path[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < tree[root].size(); i++) {
		find(path, sum, tree[root][i].id);
	}
	return;
}

int main() {
	scanf("%d %d %lld", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		weight.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		int id, child;
		scanf("%d %d", &id, &child);
		for (int j = 0; j < child; j++) {
			node tmp;
			scanf("%d", &tmp.id);
			tmp.weight = weight[tmp.id];//这里可以考虑用set的，不需要要结构体，上面weight已经建立映射了，用了set连排序都免了（但还没验证）
			tree[id].push_back(tmp);
		}
		sort(tree[id].begin(), tree[id].end(), cmp);
	}
	vector<int> path;
	find(path, 0, 00);
	system("PAUSE");
}