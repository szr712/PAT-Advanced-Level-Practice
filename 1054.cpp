#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<stack>
using namespace std;

int n, m;
map<int, int> ans;

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (ans.find(tmp) != ans.end()) {
				ans[tmp] += 1;
			}
			else {
				ans[tmp] = 1;
			}
		}
	}
	int max = -1,color;
	for (auto iterator = ans.begin(); iterator != ans.end(); iterator++) {
		if (max < iterator->second) {
			max = iterator->second;
			color = iterator->first;
		}
	}
	printf("%d\n", color);
	system("PAUSE");
}