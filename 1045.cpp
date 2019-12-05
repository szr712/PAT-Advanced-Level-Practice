//这是目前碰到的第一道dp，类最长上升子序列的做法
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int n,m,l;
vector<int> color;
vector<int> stripe;
int dp[205][10005];

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		color.push_back(tmp);
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int tmp;
		scanf("%d", &tmp);
		stripe.push_back(tmp);
	}
	for (int i = 0; i < color.size(); i++) {
		for (int j = 0; j < stripe.size(); j++) {
			if (color[i] == stripe[j])dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]) + 1;//i代表color遍历到哪了，j代表stripe遍历到哪了
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	cout << dp[m][l];
	system("PAUSE");
}