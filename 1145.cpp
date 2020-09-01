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

int msize, n, m;

bool isprime(int a) {
	if (a <= 1) return 0;
	for (int i = 2; i <= sqrt(a)+1; i++) {
		if (a%i == 0) return 0;
	}
	return 1;	 
}

vector<int> hashtable;

int main() {
	scanf("%d %d %d", &msize, &n, &m);
	while (!isprime(msize)) {
		msize++;
	}
	hashtable.resize(msize);
	fill(hashtable.begin(), hashtable.end(), 0);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		bool flag = 0;
		for (int step = 0; step < msize; step++) {
			int t = (tmp + step * step) % msize;
			if (hashtable[t]==0) {
				flag = 1;
				hashtable[t] = tmp;
				break;
			}
		}
		if (!flag) printf("%d cannot be inserted.\n", tmp);
	}
	double ans = 0.0;
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		int cnt = 1;
		int step = 0;
		for (step = 0; step < msize; step++) {
			int t = (tmp + step * step) % msize;
			if (hashtable[t] == 0 || hashtable[t] == tmp) {
				break;
			}
			cnt++;
		}
		ans += cnt;
	}
	ans = ans / m;
	printf("%.1lf", ans);
	
	system("PAUSE");
	return 0;
}