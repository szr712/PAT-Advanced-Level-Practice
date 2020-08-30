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
vector<int> pre, in;
vector<int> post;

struct node
{
	int data;
	node *left, *right;
};

node* create(int pl, int pr, int il, int ir) {
	if (pr < pl&&ir < il) {
		return NULL;
	}
	node *root = new node();
	root->data = pre[pl];
	int i;
	for (i = il; i <= ir; i++) {
		if (in[i] == pre[pl]) break;
	}
	root->left = create(pl + 1, pl + i - il, il, i - 1);
	root->right = create(pl + 1 + i - il, pr, i + 1, ir);
	return root;
}

void postorder(node *root) {
	if(root->left!=NULL)postorder(root->left);
	if(root->right != NULL) postorder(root->right);
	post.push_back(root->data);
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
		in.push_back(tmp);
	}
	node *root = create(0, n-1, 0, n-1);
	postorder(root);
	printf("%d", post[0]);
	
	system("PAUSE");
	return 0;
}