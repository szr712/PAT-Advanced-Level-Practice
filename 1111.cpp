//要注意看题，时间最快的要求是经过结点最少
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

const int INF = 0x3fffffff;
int n, m;
int dis[505][505], times[505][505];
int d[505];
int ti[505];
bool used[505];
int pre[505];//记录路径
int source, des;
vector<int> path;

void dijlength() {
	fill(d, d + 505, INF);
	fill(ti, ti + 505, INF);
	memset(used, 0, sizeof(used));
	memset(pre, -1, sizeof(pre));
	d[source] = 0;
	ti[source] = 0;
	while (1) {
		int v = -1, min = INF;
		for (int i = 0; i < n; i++) {
			if (!used[i] && min > d[i]) {
				min = d[i];
				v = i;
			}
		}
		if (v == -1) break;
		used[v] = 1;
		for (int i = 0; i < n; i++) {
			if (d[i] > d[v] + dis[v][i]) {
				d[i] = d[v] + dis[v][i];
				ti[i] = ti[v] + times[v][i];
				pre[i] = v;
			}
			else if(d[i] == d[v] + dis[v][i])
			{
				if (ti[i] > ti[v] + times[v][i]) {
					ti[i] = ti[v] + times[v][i];
					pre[i] = v;
				}
			}
		}
	}
	//轨迹
	path=vector<int>();
	int p = des;
	path.push_back(p);
	while (pre[p] != -1) {
		path.push_back(pre[p]);
		p = pre[p];
	}
}
void dijtime() {
	fill(d, d + 505, INF);
	fill(ti, ti + 505, INF);
	memset(used, 0, sizeof(used));
	memset(pre, -1, sizeof(pre));
	d[source] = 0;
	ti[source] = 0;
	while (1) {
		int v = -1, min = INF;
		for (int i = 0; i < n; i++) {
			if (!used[i] && min > ti[i]) {
				min = ti[i];
				v = i;
			}
		}
		if (v == -1) break;
		used[v] = 1;
		for (int i = 0; i < n; i++) {
			if (ti[i] > ti[v] + times[v][i]) {
				d[i] = d[v] + 1;//是经过的结点最少
				ti[i] = ti[v] + times[v][i];
				pre[i] = v;
			}
			else if (ti[i] == ti[v] + times[v][i])
			{
				if (d[i] > d[v] + 1) {
					d[i] = d[v] + 1;
					pre[i] = v;
				}
			}
		}
	}
	//轨迹
	path = vector<int>();
	int p = des;
	path.push_back(p);
	while (pre[p] != -1) {
		path.push_back(pre[p]);
		p = pre[p];
	}
}

int main() {
	scanf("%d %d", &n, &m);
	fill(dis[0], dis[0] + 505 * 505, INF);
	fill(times[0], times[0] + 505 * 505, INF);
	for (int i = 0; i < m; i++) {
		int v1, v2, way, length, t;
		scanf("%d %d %d %d %d", &v1, &v2, &way, &length, &t);
		if (way == 1) {
			dis[v1][v2] = length;
			times[v1][v2] = t;
		}
		else {
			dis[v1][v2] = length;
			times[v1][v2] = t;
			dis[v2][v1] = length;
			times[v2][v1] = t;
		}
	}
	scanf("%d %d", &source, &des);
	dijlength();
	int dans = d[des];
	vector<int> dpath = path;
	dijtime();
	if (path == dpath) {
		printf("Distance = %d; Time = %d: %d", dans, ti[des], path[path.size() - 1]);
		for (int i = path.size() - 2; i >= 0; i--) {
			printf(" -> %d", path[i]);
		}
	}
	else
	{
		printf("Distance = %d: %d", dans, dpath[dpath.size() - 1]);
		for (int i = dpath.size() - 2; i >= 0; i--) {
			printf(" -> %d", dpath[i]);
		}
		printf("\n");
		printf("Time = %d: %d", ti[des], path[path.size() - 1]);
		for (int i = path.size() - 2; i >= 0; i--) {
			printf(" -> %d", path[i]);
		}
	}
	
	


	system("PAUSE");
	return 0;
}