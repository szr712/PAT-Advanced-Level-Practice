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
bool visit[10005];
map<int, vector<int>> lines;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lines[a].push_back(i);
		lines[b].push_back(i);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int k;
		scanf("%d", &k);
		memset(visit, 0, sizeof(visit));
		//vector<int> setv;
		for (int i = 0; i < k; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (lines.find(tmp) != lines.end()) {
				for (int j = 0; j < lines[tmp].size(); j++) {
					visit[lines[tmp][j]] = 1;
				}
			}
		}
		bool flag = 0;
		for (int i = 0; i < m; i++) {
			if (!visit[i]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
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