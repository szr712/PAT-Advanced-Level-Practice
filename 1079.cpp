//dfs搜索
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

int n;
double p, r;
map<int, vector<int>> chain;
double sum;

void dfs(double price,int cur) {
	if (chain[cur][0] == 0) {
		sum += price * chain[cur][1];
		return;
	}
	double tp = price * (1 + r / 100);
	for (int i = 0; i < chain[cur].size(); i++) {
		dfs(tp, chain[cur][i]);
	}
	return;
}

int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) {
			chain[i].push_back(0);
			int t;
			scanf("%d", &t);
			chain[i].push_back(t);
		}
		for (int j = 0; j < tmp; j++) {
			int t;
			scanf("%d", &t);
			chain[i].push_back(t);
		}
	}
	sum = 0;
	dfs(p, 0);
	printf("%.1lf", sum);
	system("PAUSE");
}