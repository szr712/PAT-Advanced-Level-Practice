// 分析：一遍DFS即可～DFS过程中要维护两个变量：minCnt-中途经停的最少的站; minTransfer-需要换乘的最小次数～
// 0.可以这样计算出一条线路的换乘次数：在line[10000][10000]的数组中保存每两个相邻站中间的线路是几号线～从头到尾遍历最终保存的路径，preLine为前一小段的线路编号，如果当前的结点和前一个结点组成的这条路的线路编号和preLine不同，说明有一个换乘，就将cnt+1，最后遍历完累加的cnt即是换乘的次数～
// update：由于新的PAT系统中会显示原解法有一个测试用例内存超限，考虑到line[10000][10000]存储的方式太暴力了，所以将line换成了unordered_map<int, int> line存储的方式，第一个int用来存储线路，每次将前四位存储第一个线路，后四位存储第二个线路，使用a[i-1]*10000+a[i]的方式存储，第二个int用来保存两个相邻中间的线路是几号线～
// 1.可以这样计算出一条线路中途停站的次数：在dfs的时候有个变量cnt，表示当前路线是所需乘的第几个站，每次dfs时候将cnt+1表示向下遍历一层～cnt就是当前中途停站的次数～
// 2.可以这样输出结果：和计算线路换乘次数的思路一样，每当preLine和当前Line值不同的时候就输出一句话～保存preTransfer表示上一个换乘站，最后不要忘记输出preTransfer和最后一个站之间的路即使最后一个站并不是换乘站～
// #include<iostream>
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
const int maxn = 0x3fffffff;
const int maxt = 10005;

int n;
int s, d;
vector<vector<int>> v(maxt);
map<int, int> line;
int mincnt = maxn, mintrans = maxn;
vector<int> tmppath,path;
int visit[maxt];

int trans(vector<int>a) {
	int cnt = -1, preline = 0;
	for (int i = 1; i < a.size(); i++) {
		if (line[a[i - 1] * 10000 + a[i]] != preline)cnt++;
		preline = line[a[i - 1] * 10000 + a[i]];
	}
	return cnt;
}

void dfs(int node, int cnt) {
	if (node == d && (cnt < mincnt || (cnt == mincnt && trans(tmppath) < mintrans))) {
		mincnt=cnt;
		mintrans = trans(tmppath);
		path = tmppath;
	}
	if (node == d) {
		return;
	}
	for (int i = 0; i < v[node].size(); i++) {
		if (visit[v[node][i]] == 0) {
			visit[v[node][i]] = 1;
			tmppath.push_back(v[node][i]);
			dfs(v[node][i], cnt + 1);
			visit[v[node][i]] = 0;
			tmppath.pop_back();
		}
	}
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int m,pre;
		scanf("%d %d", &m,&pre);
		for (int j = 1; j < m; j++) {
			int t;
			scanf("%d", &t);
			v[pre].push_back(t);
			v[t].push_back(pre);
			line[t * 10000 + pre] = line[pre * 10000 + t] = i + 1;
			pre = t;
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &s, &d);
		mincnt = maxn;
		mintrans = maxn;
		tmppath = vector<int>();
		tmppath.push_back(s);
		visit[s] = 1;
		dfs(s, 0);
		visit[s] = 0;
		printf("%d\n", mincnt);
		int preLine = 0, pretans = s;
		for (int j = 1; j < path.size(); j++) {
			if (line[path[j - 1] * 10000 + path[j]] != preLine) {
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, pretans, path[j - 1]);
				preLine = line[path[j - 1] * 10000 + path[j]];
				pretans = path[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, pretans, d);
	}
	system("PAUSE");
	return 0;
}