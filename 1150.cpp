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
int maps[205][205];
int visit[205];


int main() {
	scanf("%d %d", &n, &m);
	memset(maps, -1, sizeof(maps));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		maps[a][b] = c;
		maps[b][a] = c;
	}
	int k;
	scanf("%d", &k);
	int minindex, mindis = 0x3fffffff;
	int index = 1;
	while (k--)
	{
		memset(visit, 0, sizeof(visit));
		int x, a, b;
		int dis = 0;
		scanf("%d %d", &x, &a);
		if (x == 1) {
			printf("Path %d: NA (Not a TS cycle)\n", index);
			index++;
			continue;
		}
		int start = a;
		bool flag = 1;
		for (int i = 1; i < x; i++) {
			scanf("%d", &b);
			if (flag) {
				if (maps[a][b] != -1) {
					dis += maps[a][b];
					visit[a]++;
					a = b;
				}
				else
				{
					flag = 0;
				}
			}
		}
		if (!flag) printf("Path %d: NA (Not a TS cycle)\n", index);
		else
		{
			bool f = 0;
			for (int i = 1; i <= n; i++) {
				if (visit[i] == 0) {
					printf("Path %d: %d (Not a TS cycle)\n", index, dis);
					f = 1;
					break;
				}
				if (start != b) {
					printf("Path %d: %d (Not a TS cycle)\n", index, dis);
					f = 1;
					break;
				}
			}
			if (!f) {
				bool fl = 0;
				for (int i = 1; i <= n; i++) {
					if (visit[i] > 1) {
						printf("Path %d: %d (TS cycle)\n", index, dis);
						fl = 1;
						break;
					}
				}
				if (!fl) {
					printf("Path %d: %d (TS simple cycle)\n", index, dis);
				}
				if (dis < mindis) {
					mindis = dis;
					minindex = index;
				}
			}
		}
		index++;
	}
	printf("Shortest Dist(%d) = %d\n", minindex, mindis);
	system("PAUSE");
	return 0;
}