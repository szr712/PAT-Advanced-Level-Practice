//可以用dfs也可以用01背包，用dfs要剪枝，因为如果本身加起来就不够的话那是肯定不可以的
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
vector<int>coin;
vector<int>ans,t;

bool flag = 0;
void dfs(int index,int sum) {//计数的num是不需要的
	if (flag) return;
	if (sum == m) {
		ans = t;
		flag = 1;
		return;
	}
	if (sum > m) return;
	for (int i = index; i < n; i++) {
		t.push_back(coin[i]);
		dfs(i + 1, sum + coin[i]);
		t.erase(t.end() - 1);
	}
	return;
}


int main() {
	scanf("%d %d", &n, &m);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
		coin.push_back(tmp);
	}
	if (sum < m) {
		printf("No Solution\n");
		return 0;
	}
	sort(coin.begin(), coin.end());
	dfs(0, 0);
	if (ans.size() == 0)printf("No Solution\n");
	else {
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
	}
	system("PAUSE");
}