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

int n, k;
int prime[10005];


struct node
{
	int id;
	int ans;
	int pos;
	bool flag;
};
map<int, node> ranklist;
void primetable(int n) {
	for (int i = 2; i*i <= n; i++) {
		for (int j = 2; j*i <= n; j++) {
			prime[j*i] = 1;
		}
	}
}


int main() {
	memset(prime, 0, sizeof(prime));
	scanf("%d", &n);
	primetable(n);
	for (int i = 1; i <= n; i++) {
		node tmp;
		scanf("%d", &tmp.id);
		tmp.pos = i;
		if (i == 1) {
			tmp.ans = 0;
		}
		else if (prime[i] == 0) {
			tmp.ans = 1;
		}
		else if (prime[i] == 1) {
			tmp.ans = 2;
		}
		tmp.flag = 0;
		ranklist[tmp.id] = tmp;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (ranklist.find(tmp) == ranklist.end()) {
			printf("%04d: Are you kidding?\n", tmp);
		}
		else if (ranklist[tmp].flag == 0) {
			if (ranklist[tmp].ans == 0)
			{
				printf("%04d: Mystery Award\n", tmp);
			}
			else if (ranklist[tmp].ans == 1)
			{
				printf("%04d: Minion\n", tmp);
			}
			else if (ranklist[tmp].ans == 2)
			{
				printf("%04d: Chocolate\n", tmp);
			}
			ranklist[tmp].flag = 1;
		}
		else {
			printf("%04d: Checked\n", tmp);
		}

	}
	system("PAUSE");
	return 0;
}