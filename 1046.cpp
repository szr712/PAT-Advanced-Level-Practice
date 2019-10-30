#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int n, m;
vector<long long> d;

int main() {
	scanf("%d", &n);
	long long total = 0;
	d.push_back(0);
	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		total += tmp;
		d.push_back(total);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b) {
			swap(a, b);
		}
		int tmp = d[b-1]-d[a-1];
		if (tmp > total - tmp) {
			printf("%d\n", total - tmp);
		}
		else
		{
			printf("%d\n", tmp);
		}
	}
	system("PAUSE");
}