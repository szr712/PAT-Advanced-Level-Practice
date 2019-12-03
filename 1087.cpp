/*
引入了一个num数组用来记录当前结点与起点最短路的长度，以此来计算happy的平均值，典型的迪杰斯特拉
*/
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

const int maxn = 0x3ffffff;

int  n, k;
map<string, int> city2int;
map<int, string>int2city;
int maps[205][205];
int happy[205];
string start;
int dis[205];
bool used[205];
int num[205];//代表当前结点与起点之间的最短路经过几个结点
int pre[205];
int h[205];//当前最短路的happy和
int route[205];//最短路的条数

int main() {
	scanf("%d %d", &n, &k);
	cin >> start;
	city2int[start] = 0;
	int2city[0] = start;
	memset(happy, 0, sizeof(happy));
	fill(maps[0], maps[0] + 205 * 205, maxn);
	fill(dis, dis + 205, maxn);
	memset(pre, -1, sizeof(pre));
	memset(used, 0, sizeof(used));
	fill(num, num + 205, maxn);
	memset(h, 0, sizeof(h));
	for (int i = 1; i <= n - 1; i++) {
		string tmp;
		int h;
		cin >> tmp;
		scanf("%d", &h);
		city2int[tmp] = i;
		int2city[i] = tmp;
		happy[i] = h;
	}
	for (int i = 0; i < k; i++) {
		string c1, c2;
		cin >> c1 >> c2;
		int cost;
		scanf("%d", &cost);
		maps[city2int[c1]][city2int[c2]] = cost;
		maps[city2int[c2]][city2int[c1]] = cost;
	}
	//下面开始初始化起点位置
	dis[0] = 0;
	num[0] = 0;
	h[0] = 0;
	route[0] = 1;
	for (int i = 0; i < n; i++) {
		int v = -1, min = maxn;
		for (int j = 0; j < n; j++) {
			if (!used[j] && dis[j] < min) {
				min = dis[j];
				v = j;
			}
		}
		if (v == -1) break;
		used[v] = 1;
		for (int j = 0; j < n; j++) {
			if (maps[v][j] + dis[v] < dis[j]) {
				dis[j] = maps[v][j] + dis[v];
				pre[j] = v;
				num[j] = num[v] + 1;
				h[j] = h[v] + happy[j];
				route[j] = route[v];
			}
			else if (maps[v][j] + dis[v] == dis[j]) {
				route[j] += route[v];
				if (h[j] < h[v] + happy[j]) {
					pre[j] = v;
					num[j] = num[v] + 1;
					h[j] = h[v] + happy[j];

				}
				else if (h[j] == h[v] + happy[j]) {
					if (num[j] > num[v] + 1) {
						num[j] = num[v] + 1;
						pre[j] = v;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", route[city2int["ROM"]], dis[city2int["ROM"]], h[city2int["ROM"]], h[city2int["ROM"]] / num[city2int["ROM"]]);
	stack<int> r;
	int prenode = pre[city2int["ROM"]];
	while (prenode != -1) {
		r.push(prenode);
		prenode = pre[prenode];
	}
	while (!r.empty()) {
		cout << int2city[r.top()] << "->";
		r.pop();
	}
	cout << "ROM";
	system("PAUSE");
}