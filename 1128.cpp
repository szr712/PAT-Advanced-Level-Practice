// 不要提前输出，有时候可能会导致重复输出，尽量用flag，然后最后统一输出
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

const int maxn = 0x3fffffff;

int k, n;

bool judge(int a1, int b1, int a2, int b2) {
	if (abs(a1 - a2) == abs(b1 - b2))return true;
	else return false;
}



int main() {
	scanf("%d", &n);
	while (n--)
	{
		set<int> num;
		vector<int> chess;
		bool flag = 0;
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (num.find(tmp) != num.end()) {
				//printf("NO\n");
				flag = 1;
			}
			num.insert(tmp);
			chess.push_back(tmp);
		}
		//if (flag ==1) continue;
		for (int i = 0; i < k - 1; i++) {
			for (int j = i + 1; j < k; j++) {
				if (judge(i, chess[i], j, chess[j])) {
					//printf("NO\n");
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) printf("YES\n");
		else
		{
			printf("NO\n");
		}
	}

	system("PAUSE");
	return 0;
}