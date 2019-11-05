//一开始题目看错了 所以还计算了总值，实际上不用的
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

int n, k;
map<int, pair<set<int>, int>>sets;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int m;
		scanf("%d", &m);
		set<int>tmp;
		int total = 0;
		for (int j = 0; j < m; j++) {
			int t;
			scanf("%d", &t);
			if (tmp.find(t) == tmp.end()) {
				tmp.insert(t);
				total += t;
			}

		}
		sets[i].first = tmp;
		sets[i].second = total;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		set<int> x, y;
		x = sets[a].first;
		y = sets[b].first;
		double ans = 0.0;
		vector<int> t;
		for (auto iter = y.begin(); iter != y.end(); iter++) {
			if (x.find(*iter) != x.end()) {
				t.push_back(*iter);
			}
		}
		ans = double(t.size()*1.0) / double((x.size() + y.size()-t.size())*1.0)*100.0;
		printf("%.1lf", ans);
		cout << "%" << endl;
	}
	system("PAUSE");
}