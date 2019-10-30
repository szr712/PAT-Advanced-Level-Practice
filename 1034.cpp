/*
 * 这道题我一开始的思路是融合1022和1021的思路，用map来模拟邻接表，所有都用string来作为下标
 * 但是这会存在很多问题，包括used矩阵，都需要变
 * 后来参考代码使用map建立一个string到int的映射关系
 * 这一题主要的问题在于，是用电话作为遍历项，还是用人作为遍历项
 * 用人作为遍历项思路比较直接，而且一个人打出与接听的所有电话不需要一条条存取，直接把他们合并即可，因为对于个人而言所需要知道的是接听或拨打电话的总时长
 */
#include <bits/stdc++.h>

using namespace std;
int n, k;
int call[2005][2005];
bool used[2005];
map<string, int> fx;
map<int, string> fy;
int vmax = 0;
int weight[2005];
map<string, int> ans;

int yingshe(string a) {
    if (fx.find(a) != fx.end()) {
        return fx[a];
    } else {
        fx[a] = vmax;
        fy[vmax] = a;
        vmax++;
        return fx[a];
    }
}

void dfs(int root, int &head, int &num, int &total) {
    num++;
    if (weight[root] > weight[head]) {
        head = root;
    }
    used[root] = 1;
    for (int i = 0; i < n; i++) {
        if (call[root][i] != 0) {
            total += call[root][i];
            call[root][i] = call[i][root] = 0;//关键点在于此，为防止回头，就用好此边后就去掉
            if (!used[i]) {
                dfs(i, head, num, total);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    memset(used, 0, sizeof(used));
    memset(call, 0, sizeof(call));
    memset(weight, 0, sizeof(weight));
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int t;
        cin >> n1 >> n2 >> t;
        int a = yingshe(n1);
        int b = yingshe(n2);
        call[a][b] += t;
        call[b][a] += t;
        weight[a] += t;
        weight[b] += t;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            int head = i, num = 0, total = 0;
            dfs(i, head, num, total);
            if (num > 2 && total > k) {
                ans[fy[head]] = num;
            }
        }
    }
    cout << ans.size() << endl;
    if (!ans.empty()) {
        for (auto iterator = ans.begin(); iterator != ans.end(); iterator++) {
            cout << iterator->first << " " << iterator->second << endl;
        }
    }
}

