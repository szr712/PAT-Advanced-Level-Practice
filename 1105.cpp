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
pair<int, int> s;
int minnum;
vector<int> seq;
vector<vector<int>> ans;

bool cmp(int a, int b) {
	return b < a;
}

int main() {
	cin >> n;
	minnum = n;
	for (int i = sqrt(n); i >= 1; i--) {
		if (n%i == 0&&(n/i-i)<minnum) {
			minnum = n / i - i;
			s.first = n / i;
			s.second = i;
		}
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end(),cmp);
	for (int i = 0; i <= s.first; i++) {
		vector<int>t;
		t.resize(s.second+1);
		ans.push_back(t);
	}
	int x= s.first, y = s.second;
	int sum = 0;
	while (sum < n) {
		for (int i = s.second-y+1; i <= y; i++) {
			ans[s.first - x + 1][i] = seq[sum];
			sum++;
			
		}
		y--;
		for (int i = s.first - x+2; i <= x; i++) {
			ans[i][y + 1] = seq[sum];
			sum++;
		}
		x--;
		for (int i = y; i >= s.second - y; i--) {
			ans[x+1][i] = seq[sum];
			sum++;
		}
		for (int i = x; i > s.first - x; i--) {
			if (sum == n) {//去除质数的情况
				break;
			}
				ans[i][s.second - y] = seq[sum];
				sum++;
			
		}	
	}
	for (int i = 1; i <= s.first; i++) {
		printf("%d", ans[i][1]);
		for (int j = 2; j <= s.second; j++) {
			printf(" %d", ans[i][j]);
		}
		printf("\n");
	}
	system("PAUSE");
	return 0;

}