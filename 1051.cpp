//一开始以为是思维题，后来仔细思考，只需要模拟生成序列的过程就行了
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<stack>
using namespace std;

int m, n, k;


int main() {
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		vector<int> seq;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			seq.push_back(tmp);
		}
		int goal = seq[0];
		int tmp = 0;
		stack<int> test;
		for (int i = 1; i <= n; i++) {
			test.push(i);
			if (test.size() > m) {
				break;
			}
			while (!test.empty()) {
				if (test.top() == goal) {
					test.pop();
					tmp++;
					if (tmp >= seq.size())break;
					goal = seq[tmp];
				}
				else {
					break;
				}
			}
			
		}
		if (test.empty()) {
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	
	}
	system("PAUSE");
}