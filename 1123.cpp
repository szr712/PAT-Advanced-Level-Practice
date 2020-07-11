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

node *roateleft(node *root) {
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

node *roateright(node *root) {
	node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

node *rotateleftright(node *root) {
	root->left = roateleft(root->left);
	root = roateright(root);
	return root;
}

node *rotaterightleft(node *root) {
	root->right = roateright(root->right);
	root = roateleft(root);
	return root;
}

int getHeight(node *root) {
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

node *insert(node *root, int data) {
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
				root = roateright(root);
			}
			else
			{
				root = rotateleftright(root);
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
				root = roateleft(root);
			}
			else
			{
				root = rotaterightleft(root);
			}
		}
	}
	return root;
}

vector<int> ans;

void level(node *root) {
	queue<node*>queue;
	queue.push(root);
	while (!queue.empty())
	{
		node *tmp = queue.front();
		queue.pop();
		ans.push_back(tmp->data);
		if (tmp->left != NULL) {
			queue.push(tmp->left);
		}
		if (tmp->right != NULL) {
			queue.push(tmp->right);
		}
	}
}

bool flag = true;

void judge(node *root) {
	queue<node*>queue;
	queue.push(root);
	while (!queue.empty())
	{
		node *tmp = queue.front();
		if (tmp->left != NULL && tmp->right != NULL) {
			queue.pop();
			queue.push(tmp->left);
			queue.push(tmp->right);
		}
		else if (tmp->left == NULL && tmp->right != NULL) {
			flag = false;
			return;
		}
		else
		{
			queue.pop();//要把原来的pop掉
			if (tmp->left != NULL) {
				queue.push(tmp->left);
			}
			while (!queue.empty())
			{
				node *t = queue.front();
				if (t->left == NULL && t->right == NULL) {
					queue.pop();
				}
				else
				{
					flag = false;
					return;
				}
			}
			if (queue.empty()) {
				flag = true;
				return;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		root=insert(root, tmp);
	}
	level(root);
	if (ans.size() > 0) {
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
		judge(root);
		if (flag) {
			printf("\nYES");
		}
		else
		{
			printf("\nNO");
		}
	}
	
	
	system("PAUSE");
	return 0;
}