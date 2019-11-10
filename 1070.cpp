//数量也要是double
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

struct kind
{
	double weight;
	double price;
	double per;
};

int n, d;
vector<kind> kinds;

bool cmp(kind a, kind b) {
	return a.per > b.per;
}

int main() {
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		kind tmp;
		scanf("%lf", &tmp.weight);
		kinds.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		double tmp=0.0;
		scanf("%lf", &tmp);
		kinds[i].price = tmp;
		kinds[i].per = kinds[i].price / kinds[i].weight;
	}
	sort(kinds.begin(), kinds.end(), cmp);
	int i = 0;
	double ans = 0.0;
	while (d != 0&& i<n) {
		if (kinds[i].weight <= d) {
			ans += kinds[i].price;
			d -= kinds[i].weight;
		}
		else {
			ans += d * kinds[i].per;
			d = 0;
			

		}
		i++;
	}
	printf("%.2lf", ans);
	system("PAUSE");
}