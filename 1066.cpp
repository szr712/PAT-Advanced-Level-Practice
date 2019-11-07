//AVL树的平衡
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
struct node
{
	int data;
	node *left, *right;
};

node *rotateleft(node *root) {
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

node *rotateright(node *root) {
	node* t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

node *rotateleftright(node *root) {
	root->left = rotateleft(root->left);
	root = rotateright(root);
	return root;
}

node *rotaterightleft(node *root) {
	root->right = rotateright(root->right);
	root = rotateleft(root);
	return root;
}

int getHeight(node *root) {
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

node *insert(node* root, int data) {
	//不光是一开始插入的时候用这句，以后插入的时候运行到叶子结点的时候也会用到
	if (root == NULL) {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	if (root->data > data) {
		root->left = insert(root->left, data);
		int lh = getHeight(root->left);
		int rh = getHeight(root->right);
		if (lh - rh >= 2) {
			if (root->left->data > data) {
				root = rotateright(root);
			}
			else {
				root=rotateleftright(root);
			}
		}

	}
	else
	{
		root->right = insert(root->right, data);
		int lh = getHeight(root->left);
		int rh = getHeight(root->right);
		if (rh - lh >= 2) {
			if (root->right->data < data) {
				root=rotateleft(root);
			}
			else {
				root=rotaterightleft(root);
			}
		}
	}
	return root;
}


int main() {
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		root = insert(root, tmp);
	}
	printf("%d", root->data);
	system("PAUSE");
}