//使用了类似1007的思路
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int n, m;
vector<int> chain;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		chain.push_back(tmp);
	}
	bool flag = 0;
	while (!flag) {
		int sum = chain[0];
		int left = 0, right = 0;
		while (left < chain.size() && right < chain.size()) {
			if (sum == m) {
				flag = 1;
				printf("%d-%d\n", left + 1, right + 1);
				sum -= chain[left];
				left++;
			}
			if (sum < m) {
				right++;
				if (right == chain.size())continue;
				sum += chain[right];
			}
			else if (sum > m) {
				sum -= chain[left];
				left++;
			}
		}
		m++;//变换m的值，直到找到一样的
	}
	system("PAUSE");
}