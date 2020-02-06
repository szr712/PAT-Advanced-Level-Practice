//一个三维的广搜，有点难
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

struct node
{
	int x, y, z;
};

int m, n, l, t;
int arr[1300][130][65];
bool visit[1300][130][65];

//遍历的方向
int  X[6] = {1, 0, 0, -1, 0, 0};
int  Y[6] = {0, 1, 0, 0, -1, 0};
int  Z[6] = {0, 0, 1, 0, 0, -1};

int bfs(int x, int y, int z) {
	int v = 0;
	node tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	queue<node> q;
	q.push(tmp);
	visit[x][y][z] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		v++;
		for (int i = 0; i < 6; i++) {
			int tx = now.x + X[i];
			int ty = now.y + Y[i];
            int tz = now.z + Z[i];
			if (arr[tx][ty][tz] == 1&&visit[tx][ty][tz]==0) {
				visit[tx][ty][tz] = 1;
				node tmp;
				tmp.x = tx;
				tmp.y = ty;
				tmp.z = tz;
				q.push(tmp);
			}
		}
	}
	if (v >= t) {
		return v;
	}
	else {
		return 0;
	}
}

int main() {
	scanf("%d %d %d %d", &m, &n, &l, &t);
	fill(arr[0][0], arr[0][0] + 1300 * 120 * 65, -1);
	memset(visit, 0, sizeof(visit));
	for (int z = 1; z <= l; z++) {
		 for (int x = 1; x <= m; x++){
			for (int y = 1; y <= n; y++) {
				int tmp;
				scanf("%d", &tmp);
				arr[x][y][z] = tmp;
			}
		}
	}
	int ans = 0;
	for (int z = 1; z <= l; z++) {
		for (int x = 1; x <= m; x++) {
			for (int y = 1; y <= n; y++) {
				if (arr[x][y][z] == 1 && visit[x][y][z] == 0) {
					ans += bfs(x, y, z);
				}
			}
		}
	}
	cout << ans;
	system("PAUSE");
}