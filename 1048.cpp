//还可能有同一面值有好几个的情况
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int n, m;
int flag[1005];

int main() {
	memset(flag, 0, sizeof(flag));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		flag[t] += 1;
	}
	int l = 1;
	int r = m - l;
	while (l < r) {
		if (flag[l] && flag[r]) {
			printf("%d %d", l, r);
			system("PAUSE");
			return 0;
		}
		l++;
		r--;
	}
	if (m % 2 == 0 && flag[m / 2] >= 2) {
		printf("%d %d\n", m / 2, m / 2);
		system("PAUSE");
		return 0;
	}
	printf("No Solution\n");
	system("PAUSE");
}