#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

vector<int> num;
int c[10005];
int n;

int main() {
	memset(c, 0, sizeof(c));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		c[tmp] += 1;
		num.push_back(tmp);
	}
	for (int i = 0; i < num.size(); i++) {
		if (c[num[i]] == 1) {
			printf("%d", num[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}