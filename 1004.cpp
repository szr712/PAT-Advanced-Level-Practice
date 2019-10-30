#include <bits/stdc++.h>

using namespace std;
vector<int> tree[100];
int n, m;
int depth = 0, maxd = -1;
int ans[100];

void dfs(int start, int depth) {
    if (tree[start].size() == 0) {
        ans[depth]++;
        maxd = max(depth, maxd);
        return;
    }
    for (int i = 0; i < tree[start].size(); i++) {
        dfs(tree[start][i], 1+depth);
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int id, k, idk;
        cin >> id >> k;
        while (k--) {
            cin >> idk;
            tree[id].push_back(idk);
        }
    }
    dfs(1, 0);
    cout << ans[0];
    for (int i = 1; i <= maxd; i++) {
        cout << " " << ans[i];
    }
}