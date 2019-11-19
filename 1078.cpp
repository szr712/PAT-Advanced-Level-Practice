/*
用了构造哈希表的二次探测法（Quadratic probing ）
*/
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

bool used[10005];
int tsize, n;

bool isprime(int a) {
	if (a <= 1)return 0;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a%i == 0)return 0;
	}
	return 1;
}

int main() {
	memset(used, 0, sizeof(used));
	scanf("%d %d", &tsize, &n);
	while (!isprime(tsize)) {
		tsize++;
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		int m = tmp % tsize;
		if (!used[m]) {
			used[m] = 1;
			if (i == 0) {
				printf("%d", m);
			}
			else
			{
				printf(" %d", m);
			}
		}
		else
		{
			int step = 1;
			for (; step < tsize; step++) {
				m = (tmp + step*step) % tsize;
				if (!used[m]) {
					used[m] = 1;
					if (i == 0) {
						printf("%d", m);
					}
					else
					{
						printf(" %d", m);
					}
					break;
				}
			}
			if (step >= tsize) {
				if (i > 0)printf(" ");
				printf("-");
			}
		}
	}
	system("PAUSE");
}