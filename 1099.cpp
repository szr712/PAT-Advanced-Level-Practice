//因为是二叉搜索树，所以中序遍历这棵树得到的结点顺序应该是给出的数值序列从小到大的排列顺序，所以把数值序列排序后，可以在中序遍历的时候直接赋值当前tree[root].data～
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

struct node
{
	int data, l, r,index;
};

int n;
vector<node> tree;
vector<int> num;

int x = 0;

void inorder(node root) {
	if (root.l != -1) {
		inorder(tree[root.l]);
	}
	tree[root.index].data = num[x];
	x++;
	if (root.r != -1) {
		inorder(tree[root.r]);
	}
}

void level(node root) {
	int num = 0;
	queue<node> que;
	que.push(root);
	while (!que.empty())
	{
		node tmp = que.front();
		que.pop();
		num++;
		printf("%d", tmp.data);
		if (num != n) {
			printf(" ");
		}
		if (tmp.l != -1) {
			que.push(tree[tmp.l]);
		}
		if (tmp.r != -1) {
			que.push(tree[tmp.r]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		node tmp;
		tmp.index = i;
		scanf("%d %d", &tmp.l, &tmp.r);
		tree.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	sort(num.begin(),num.end());
	inorder(tree[0]);
	level(tree[0]);
	system("PAUSE");
	return 0;

}