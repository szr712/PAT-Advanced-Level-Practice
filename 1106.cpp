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

int n, num;
double p, r;
double minp;
map<int, vector<int>> chain;

void dfs(double price,int node) {
	if (*chain[node].begin() == -1) { 
		if (minp == price) {
			num++;
		}
		else if (price < minp || minp < 0) {
			minp = price;
			num = 1;
		}
		return;
	}
	for (int i = 0; i < chain[node].size(); i++) {
		if (price*(r + 1.0) <= minp || minp < 0) {
			dfs(price*(r + 1.0), chain[node][i]);
		}
	}
	return;
}

int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	minp = -1; num = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) {
			chain[i].push_back(-1);
			continue;
		}
		while (tmp--)
		{
			int t;
			scanf("%d", &t);
			chain[i].push_back(t);
		}
	}
	dfs(p, 0);
	printf("%.4lf %d", minp, num);
	
	system("PAUSE");
	return 0;
}