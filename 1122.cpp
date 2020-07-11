// 汉密尔顿路径要求经过所有结点，并且除起点外只经过一次
// 所以这就有两个条件
// 1 是否经过所有结点
// 2 是不是通路
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

int n, m;
map <int, set<int>>maps;

vector<int> que;
set<int> num;
bool flag1 = true, flag2 = true;



int main() {
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		maps[a].insert(b);
		maps[b].insert(a);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int t;
		scanf("%d", &t);
		flag1 = true;
		flag2 = true;
		que = vector<int>();
		num = set<int>();
		for (int j = 0; j < t; j++) {
			int tmp;
			scanf("%d", &tmp);
			que.push_back(tmp);
			num.insert(tmp);
		}
		if (t - 1 != n || que[0] != que[t - 1] || num.size() != n) {
			flag1 = false;
		}
		for (int i = 0; i < que.size()-1; i++) {
			if (maps[que[i]].find(que[i + 1]) == maps[que[i]].end()) {
				flag2 = false;
			}
		}
		if (flag2&&flag1)printf("YES\n");
		else
		{
			printf("NO\n");
		}
	}
	system("PAUSE");
	return 0;
}