//一开始使用的是邻接矩阵，但是会爆内存，后来用邻接表就OK了
#include <bits/stdc++.h>

using namespace std;

const int INF = 0xfffffff;
const int maxn = 10005;
int n;
vector<int> maps[maxn];
bool used[maxn];
int de[maxn];
int maxd = -1, tmax = -1;

void dfs(int root) {
    used[root] = 1;
    for (int i = 0; i < maps[root].size(); i++) {
        if (!used[maps[root][i]]) {
            dfs(maps[root][i]);
        }
    }
}

void dfs2(int root, int depth) {
    used[root] = 1;
    if (depth > tmax) tmax = depth;
    for (int i = 0; i < maps[root].size(); i++) {
        if (!used[maps[root][i]]) {
            dfs2(maps[root][i],depth+1);
        }
    }
}

int main() {
    scanf("%d",&n);
    memset(used, 0, sizeof(used));
    memset(de,0,sizeof(de));

    for (int i = 1; i <= n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        //cin>>a>>b;
        maps[a].push_back(b);
        maps[b].push_back(a);
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
            t++;//如果不是连通图，那直接就是错误的
        }
    }
    if (t > 1) {
        printf("Error: %d components", t);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        memset(used, 0, sizeof(used));
        tmax = 0;
        dfs2(i, 0);//以每个顶点作为root跑一遍dfs，获得深度
        de[i] = tmax;
        if (tmax > maxd) maxd = tmax;
    }
    t=0;
    for(int i=1;i<=n;i++){
        if(de[i]==maxd){
            if(t==0)cout<<i;
            else{
                printf("\n%d",i);
            }
            t++;
        }
    }

}
