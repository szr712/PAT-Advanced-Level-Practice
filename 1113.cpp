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
vector<int> num;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	if (n % 2 == 0) {
		printf("0 ");
		int low = 0, high = 0;
		for (int i = 0; i < n / 2; i++) {
			low += num[i];
		}
		for (int i = n/2; i < n ; i++) {
			high += num[i];
		}
		printf("%d", high - low);
	}
	else
	{
		printf("1 ");
		int low = 0, high = 0;
		for (int i = 0; i < n / 2; i++) {
			low += num[i];
		}
		for (int i = n / 2; i < n; i++) {
			high += num[i];
		}
		printf("%d", high - low);
	}

	system("PAUSE");
	return 0;
}