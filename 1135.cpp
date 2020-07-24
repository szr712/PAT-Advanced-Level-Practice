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
vector<int> tree;
struct node
{
	int data;
	node *right, *left;
	int black;
};

node* create(int l, int r,int bla) {
	if (l > r) return NULL;
	node *tmp = new node();
	tmp->data = tree[l];
	if (tree[l] > 0) tmp->black = bla + 1;
	else
	{
		tmp->black = bla;
	}
	int i=l;
	for (i = l; i <= r; i++) {
		if (abs(tree[i]) > abs(tree[l])) break;
	}
	tmp->left = create(l + 1, i - 1,tmp->black);
	tmp->right = create(i, r,tmp->black);
	return tmp;
}


int main() {
	scanf("%d", &n);
	while (n--)
	{
		int m;
		scanf("%d", &m);
		tree = vector<int>();
		for (int i = 0; i < m; i++) {
			int tmp;
			scanf("%d", &tmp);
			tree.push_back(tmp);
		}
		node *root = create(0, m - 1,0);
		bool flag = 1;
		if (root->data < 0) flag = 0;
		queue<node*>q;
		vector<node*>leaf;
		q.push(root);
		while (!q.empty())
		{
			node *t = q.front();
			q.pop();
			if (t->data < 0) {
				if (t->left != NULL) {
					if (t->left->data < 0) flag = 0;
				}
				if (t->right != NULL) {
					if (t->right->data < 0) flag = 0;
				}
			}
			if (t->left == NULL && t->right == NULL) {
				node *tmp = new node();
				tmp->black = t->black + 1;
				leaf.push_back(tmp);
			}
			else if (t->left == NULL) {
				node *tmp = new node();
				tmp->black = t->black + 1;
				leaf.push_back(tmp);
			}
			else if (t->right == NULL) {
				node *tmp = new node();
				tmp->black = t->black + 1;
				leaf.push_back(tmp);
			}
			if (t->left != NULL) {
				q.push(t->left);
			}
			if (t->right != NULL) {
				q.push(t->right);
			}
		}
		int x = leaf[0]->black;
		for (int i = 0; i < leaf.size(); i++) {
			if (leaf[i]->black != x) flag = 0;
		}
		if (flag) {
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		
	}
	
	system("PAUSE");
	return 0;
}