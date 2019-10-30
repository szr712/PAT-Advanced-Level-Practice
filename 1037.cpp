//使用贪心，正数最大的和最大乘，负数最小的和最小的乘，正反不能乘就放弃
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int c, p;
vector<int>co, po;
bool cmp(int a, int b) {
	return a > b;
}
bool cmp2(int a, int b) {
	return a < b;
}

int main() {
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		int tmp;
		scanf("%d", &tmp);
		co.push_back(tmp);
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		int tmp;
		scanf("%d", &tmp);
		po.push_back(tmp);
	}
	sort(co.begin(), co.end(), cmp);
	sort(po.begin(), po.end(), cmp);
	long long ans = 0;
	for (int i = 0; i < co.size(); i++) {
		if (co[i] <= 0 || po[i] <= 0) break;
		ans += co[i] * po[i];
	}
	sort(co.begin(), co.end(), cmp2);
	sort(po.begin(), po.end(), cmp2);
	for (int i = 0; i < co.size(); i++) {
		if (co[i] >= 0 || po[i] >= 0) break;
		ans += co[i] * po[i];
	}
	printf("%lld", ans);
	system("PAUSE");
}