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

int n,m;
map<int, set<int>> graph;


int main() {
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x;
		vector<int> cur;
		scanf("%d", &x);
		bool flag = 1;
		for (int j = 0; j < x; j++) {
			int tmp;
			scanf("%d", &tmp);
			for (int p = 0; p < cur.size(); p++) {
				if (graph[tmp].find(cur[p]) == graph[tmp].end()) flag = 0;
			}
			cur.push_back(tmp);
		}
		if (!flag) {
			printf("Not a Clique\n");
			continue;
		}
		else
		{
			for (auto j = graph.begin(); j != graph.end(); j++) {
				int x = 0;
				for (int p = 0; p < cur.size(); p++) {
					if (j->second.find(cur[p]) != j->second.end()) x++;
				}
				if (x == cur.size()) flag = 0;
			}
			if (!flag) {
				printf("Not Maximal\n");
			}
			else
			{
				printf("Yes\n");
			}
		}
	}
	

	system("PAUSE");
	return 0;
}