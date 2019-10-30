/*
这一题解法很巧妙，一开始的思路是重建树，然后将它中序输出，看看是不是和题目给出的一样
后来参考的思路是
对于二叉排序树，左子树的所有元素都比跟结点小的，右子树都要大的
所以就找到左右子树的分界，然后比整个的大小就行了
在前序输出的过程中，与判断的时候一样，找出左右子树的分界点，然后开始递归左子树右子树，碰到叶子就输出，然后再输出中间的结点就可以了
*/
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int n;
vector<int> s;
bool flag = 0;
bool f = 1;

bool judge(int l, int r) {
	if (l > r) return 1;
	int i;
	for (i = l + 1; i <= r; i++) {
		if (flag) {
			if (s[i] >= s[l]) break;
		}
		else
		{
			if (s[i] < s[l]) break;
		}
	}
	for (int j = i; j <= r; j++) {
		if (flag) {
			if (s[j] < s[l]) return 0;
		}
		else {
			if (s[j] >= s[l]) return 0;
		}
	}
	if (i > r) return 1;
	if (judge(l + 1, i - 1) && judge(i, r))return 1;
	else return 0;
}

void print(int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (f) f = 0;
		else {
			printf(" ");
		}
		printf("%d", s[l]);
		return;
	}
	int i;
	for (i = l + 1; i <= r; i++) {
		if (flag) {
			if (s[i] >= s[l]) break;
		}
		else
		{
			if (s[i] < s[l]) break;
		}
	}
	print(l + 1, i - 1);//左子树
	print(i, r);//右子树
	//下面打印的是中
	if (f) f = 0;
	else {
		printf(" ");
	}
	printf("%d", s[l]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		s.push_back(tmp);
	}
	if (s[0] > s[1])flag = 1;
	if (judge(0, s.size() - 1)) {
		printf("YES\n");
		print(0, s.size() - 1);
	}
	else
	{
		printf("NO\n");
	}
	
	system("PAUSE");
}