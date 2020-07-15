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
vector<int> chain;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		chain.push_back(tmp);
	}
	sort(chain.begin(), chain.end());
	double ans = chain[0];
	for (int i = 1; i < chain.size(); i++) {
		ans = (ans + chain[i]) / 2;
	}
	cout << int(ans) << endl;
	system("PAUSE");
	return 0;
}