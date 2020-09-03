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
int maps[10005][10005] = {0};

int main() {
	scanf("%d %d", &n, &m);
	//memset(maps, 0, sizeof(maps));
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		maps[a][b] = 1;
		maps[b][a] = 1;
	}
	int k;
	scanf("%d", &k);
	while (k--)
	{
		map<int, vector<int>> color;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			color[tmp].push_back(i);
		}
		bool flag = 1;
		for (auto i = color.begin(); i != color.end(); i++) {
			if (flag) {
				for (int j = 0; j < i->second.size() - 1; j++) {
					for (int x = j + 1; x < i->second.size(); x++) {
						if (maps[i->second[j]][i->second[x]] == 1) {
							flag = 0;
							break;
						}
					}
				}
			}
		}
		if (flag) {
			printf("%d-coloring\n", color.size());
		}
		else
		{
			printf("No\n");
		}
	}
	system("PAUSE");
	return 0;
}