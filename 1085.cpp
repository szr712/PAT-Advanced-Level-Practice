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

long long n, p;
vector<long long> seq;

int main() {
	scanf("%lld %lld", &n, &p);
	int len = 0;
	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i < n; i++) {
		long long maxn = seq[i] * p;

		while (1) {
			if (len + i >= seq.size()) {
				break;
			}
			if (seq[len + i] > maxn) break;
			len++;
		}
	}
	printf("%d", len);
	system("PAUSE");
}