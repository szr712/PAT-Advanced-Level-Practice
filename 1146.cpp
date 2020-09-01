// 用邻接表v存储这个有向图，并将每个节点的入度保存在in数组中。对每一个要判断是否是拓扑序列的结点遍历，如果当前结点的入度不为0则表示不是拓扑序列，每次选中某个点后要将它所指向的所有结点的入度-1，最后根据是否出现过入度不为0的点决定是否要输出当前的编号i～flag是用来判断之前是否输出过现在是否要输出空格的～judge是用来判断是否是拓扑序列的～
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
map<int, vector<int>> graph;
int in[1010];//入度
bool flag = 0;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		in[b]++;
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int judge = 1;
		vector<int> tin(in, in + n + 1);//暂时的入度；
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			if (tin[a] != 0) judge = 0;
			for (int x = 0; x < graph[a].size(); x++) {
				tin[graph[a][x]]--;
			}
		}
		if (judge == 1) continue;
		if (!flag) {
			flag = 1;
			printf("%d", i);
		}
		else
		{
			printf(" %d", i);
		}
	}
	system("PAUSE");
	return 0;
}