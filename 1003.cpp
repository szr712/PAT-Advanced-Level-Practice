//此题与一般的dijkstra不同在需要对最短路相同的情况进行特判，一开始的思路是用广搜找出所有路径，但时间和空间开销太大
#include<bits/stdc++.h>
using namespace std;
int n, m, c1, c2;//与题目字母相同
const int INF = 0x3fffffff;
int maps[505][505];//maps是由题目输入转换过来的邻接矩阵，对角线上的内容为城市所含救援队
int team[505] = {0}, dis[505], num[505];//team代表最大救援队，dis代表当前最短路，num代表最短路径数量
bool flag[505] = {0};

void dijkstra() {
    fill(dis, dis + 505, INF);
    memset(flag, 0, sizeof(flag));
    memset(num, 0, sizeof(num));
    dis[c1] = 0;
    num[c1] = 1;
    while (true) {
        //找到距离最小的点 一开始就是起点
        int v = -1, min = INF;
        for (int u = 0; u < n; u++) {
            if (!flag[u] && min > dis[u]) {
                v = u;
                min=dis[u];
            }
        }
        if (v == -1) break;
        flag[v] = true;
        //下面生成目前点到各自点的最短路
        for (int i = 0; i < n; i++) {
            if (i == v) continue;
            if (!flag[i] && maps[v][i] != INF) {
                //如果所存在的路径比找到的最短路要短
                if ((dis[v] + maps[v][i]) < dis[i]) {
                    dis[i] = dis[v] + maps[v][i];
                    num[i] = num[v];
                    team[i] = team[v] + maps[i][i];
                } else if ((dis[v] + maps[v][i]) == dis[i]) {//如果找到的路径与目前最短路相同，那就要判断救援队人数
                    num[i] += num[v];
                    if ((team[v] + maps[i][i]) > team[i]) {
                        team[i] = team[v] + maps[i][i];
                    }
                }
            }
        }
    }
}

int main() {
    fill(maps[0], maps[0] + 505*505, INF);
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &maps[i][i]);
        team[i] = maps[i][i];
    }
    for (int i = 0; i < m; i++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        maps[a][b] = l;
        maps[b][a] = l;
    }
    dijkstra();
    cout << num[c2] << " " << team[c2] << endl;
}
