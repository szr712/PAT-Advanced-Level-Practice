//一个很巧妙的递归方法，排完顺序以后实际上这棵树就是以中序遍历的方式输出了，那就模拟中序遍历的方式得到层次遍历的顺序
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
int seq[1010], ans[1010];
int in = 0;

void level(int root) {
	if (root > n) return;
	level(root * 2);
	ans[root] = seq[in++];
	level(root * 2 + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	sort(seq, seq + n);
	level(1);
	printf("%d", ans[1]);
	for (int i = 2; i <= n; i++) {
		printf(" %d", ans[i]);
	}
	system("PAUSE");
}