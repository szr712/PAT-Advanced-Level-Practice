//dfs 比较巧妙的一题DFS
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

vector<int> num;
vector<int> ans,tmpa;
int maxsum= -1;
int n, k, p;

void dfs(int i, int tmpsum, int tmpk, int facsum) {
	if (tmpk == k) {
		if (tmpsum == n && facsum > maxsum) {
			ans = tmpa;
			maxsum = facsum;
		}
		return;
	}
	for (int j = i; j >= 1; j--) {
		if (tmpsum + num[j] <= n) {
			tmpa[tmpk] = j;
			dfs(j, tmpsum + num[j], tmpk + 1, facsum + j);
		}	
	}
	return;
}

int main() {
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 0; i < pow(n, 1.0 / p) + 1; i++) {
		num.push_back(pow(i,p));
	}
	tmpa.resize(k);//先建立一个K大的tmpans
	dfs(num.size() - 1, 0, 0, 0);
	if (maxsum == -1) {
		printf("Impossible");
	}
	else
	{
		printf("%d = ", n);
		for (int i = 0; i < ans.size(); i++) {
			if (i != 0) {
				printf(" + ");
			}
			printf("%d^%d", ans[i], p);
		}
	}
	
	system("PAUSE");
	return 0;

}