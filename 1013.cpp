#include<bits/stdc++.h>

using namespace std;

int n, m, k;
int maps[1005][1005];
bool flag[1005];

void dfs(int node) {
    flag[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (maps[node][i] == 1 && flag[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    memset(maps, 0, sizeof(maps));
    memset(flag, 0, sizeof(flag));
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        maps[a][b] = 1;
        maps[b][a] = 1;
    }
    int tmp = 0;
    for (int t = 0; t < k; t++) {
        scanf("%d", &tmp);
        memset(flag, 0, sizeof(flag));
        int ans = 0;
        flag[tmp] = 1;
        for (int i = 1; i <= n; i++) {
            if(flag[i]==0){
                dfs(i);
                ans++;
            }
        }
        printf("%d\n",ans-1);
    }
}