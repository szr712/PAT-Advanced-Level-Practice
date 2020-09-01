// 坑点在输入就是连续的时候，输出应该是最后一个数
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
set<int> pos;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) pos.insert(tmp);
	}
	if (pos.size() == 0) {
		printf("1");
	}
	else
	{
		int i = 1;
		bool flag = 0;
		for (auto iter = pos.begin(); iter != pos.end(); iter++) {
			if (*iter != i) {
				flag = 1;
				printf("%d", i);
				break;
			}
			i++;
		}
		if (!flag) printf("%d", i);
	}
	system("PAUSE");
	return 0;
}