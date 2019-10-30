#include <bits/stdc++.h>

using namespace std;
const int maxn = 250000;
int n, m, s, d;
int cost[505][505], maps[505][505];
bool used[505];
int dis[505], money[505];
int pre[505];

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &d);
    fill(maps[0], maps[0] + 505 * 505, maxn);
    fill(cost[0], cost[0] + 505 * 505, maxn);
    memset(used, 0, sizeof(used));
    memset(pre, -1, sizeof(pre));
    fill(money, money + 505, maxn);
    fill(dis, dis + 505, maxn);
    for (int i = 0; i < m; i++) {
        int c1, c2, di, co;
        scanf("%d %d %d %d", &c1, &c2, &di, &co);
        maps[c1][c2] = maps[c2][c1] = di;
        cost[c1][c2] = cost[c2][c1] = co;
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<maps[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<cost[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    dis[s] = 0;
    money[s] = 0;
    while (1) {
        int mind = INT_MAX, u = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i] && dis[i] < mind) {
                mind = dis[i];
                u = i;
            }
        }
        if (u == -1) break;
        used[u] = 1;
        for (int i = 0; i < n; i++) {
            if (dis[i] > dis[u] + maps[u][i]) {
                dis[i] = dis[u] + maps[u][i];
                money[i] = money[u] + cost[u][i];
                pre[i] = u;
            } else if (dis[i] == dis[u] + maps[u][i]) {
                if (money[i] > money[u] + cost[u][i]) {
                    money[i] = money[u] + cost[u][i];
                    pre[i] = u;
                }
            }
        }
    }
    vector<int> path;
    int p = d;
    path.push_back(d);
    while (pre[p] != -1) {
        path.push_back(pre[p]);
        p = pre[p];
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    cout << dis[d] << " ";
    cout << money[d];

}

