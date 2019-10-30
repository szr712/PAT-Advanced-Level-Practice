#include <bits/stdc++.h>

using namespace std;
const int maxn = 505;
const int INF = 0x3ffffff;

int c, n, s, m;
int d[maxn], cost[maxn][maxn];
bool used[maxn];
vector<int> pre[maxn];
vector<int> path, tmp;
int minsend = INF, minback = INF;

void dfs(int v) {
    tmp.push_back(v);
    if (v == 0) {
        int send = 0, back = 0;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            int id = tmp[i];
            if (cost[id][id] > 0) {
                back += cost[id][id];
            } else {
                if (back > abs(cost[id][id])) {
                    back -= abs(cost[id][id]);
                } else {
                    send += (abs(cost[id][id]) - back);
                    back = 0;
                }
            }
        }
        if (minsend > send) {
            minsend = send;
            minback = back;
            path = tmp;
        } else if (minsend == send && minback > back) {
            minback = back;
            path = tmp;
        }
        tmp.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    tmp.pop_back();
}

int main() {
    scanf("%d %d %d %d", &c, &n, &s, &m);
    fill(cost[0],cost[0]+maxn*maxn,INF);
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        tmp -= c / 2;
        cost[i][i] = tmp;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, tmp;
        scanf("%d %d %d", &a, &b, &tmp);
        cost[a][b] = tmp;
        cost[b][a] = tmp;
    }
    cost[0][0]=0;
    fill(d, d + maxn, INF);

    memset(used, 0, sizeof(used));
    d[0] = 0;
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= n; j++) {
//            cout << cost[i][j] << " ";
//        }
//        cout << endl;
//    }
    while (1) {
        int v = -1, min = INF;
        for (int i = 0; i <= n; i++) {
            if (!used[i] && min > d[i]) {
                v = i;
                min = d[i];
            }
        }
        if (v == -1) break;
        used[v] = 1;
        for (int i = 0; i <= n; i++) {
            if (d[i] > d[v] + cost[v][i] && v != i) {
                d[i] = d[v] + cost[v][i];
                pre[i].clear();
                pre[i].push_back(v);
            } else if (d[i] == d[v] + cost[v][i] && v != i) {
                pre[i].push_back(v);
            }
        }

    }
    dfs(s);
    printf("%d 0", minsend);
    for (int i = path.size() - 2; i >= 0; i--) {
        printf("->%d", path[i]);
    }
    printf(" %d\n", minback);
    return 0;
}
