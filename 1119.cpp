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
vector<int> in, pre, post;

struct node
{
	int num;
	node *left, *right;
};

bool uniq = 0;

node *create(int prel, int prer, int postl, int postr) {
	if (prer == prel) {
		node * tmp = new node;
		tmp->num = pre[prer];
		tmp->left = tmp->right=NULL;
		return tmp;
	}
	node *root = new node;
	root->num = pre[prel];
	int i;
	for (i = prel+1; i <= prer; i++) {
		if (pre[i] == post[postr-1]) break;
	}
	if (i - prel > 1) {
		root->left = create(prel + 1, i - 1, postl, postl + i - (prel + 1) - 1);
	}
	else
	{
		root->left = NULL;
		uniq = 1;//意味着与这颗树是没有兄弟的，也就是说他可以出现在左边也可以在右边，所以会出现不同，都归类到右儿子
	}
	root->right = create(i, prer, postl + i - (prel + 1), postr - 1);
	return root;
}

void inorder(node *root) {
	if (root == NULL) return;
	inorder(root->left);
	in.push_back(root->num);
	inorder(root->right);
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		pre.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		post.push_back(tmp);
	}
	node *root=create(0, n - 1, 0, n - 1);
	inorder(root);
	if (uniq) {
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
	}
	printf("%d", in[0]);
	for (int i = 1; i < in.size(); i++) {
		printf(" %d", in[i]);
	}
	printf("\n");
	system("PAUSE");
	return 0;
}