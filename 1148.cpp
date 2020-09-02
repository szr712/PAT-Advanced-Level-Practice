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
int state[105];


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &state[i]);
	}
	bool flag = 1;
	int wolf1, wolf2;
	for (int i = 1; i <= n-1; i++) {
		if (flag) {
			for (int j = i+1; j <= n; j++) {
				set<int> lair;
				for (int m = 1; m <= n; m++) {
					if (state[m] == (0 - i) || state[m] == (0 - j) || (state[m] != i && state[m] != j && state[m] > 0)) {
						continue;
					}
					else
					{
						lair.insert(m);
					}
				}
				//撒谎两个人，且有且仅有一个狼
				if (lair.size() == 2) {
					if (lair.find(i) != lair.end() && lair.find(j) == lair.end()) {
						flag = 0;
						wolf1 = i;
						wolf2 = j;
					}
					else if (lair.find(j) != lair.end() && lair.find(i) == lair.end()) {
						flag = 0;
						wolf1 = i;
						wolf2 = j;
					}
				}
			}
		}
		else break;
	}
	if (!flag) {
		printf("%d %d\n", wolf1, wolf2);
	}
	else
	{
		printf("No Solution\n");
	}
	system("PAUSE");
	return 0;
}