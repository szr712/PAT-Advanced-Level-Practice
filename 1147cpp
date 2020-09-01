//不能建树,会炸内存
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

int m, n;
vector<int> level;
bool flag = 1;
vector<int> post;

struct node
{
	int data;
	node *left, *right;
};

node* create(int t) {
	node *root = new node();
	root->data = level[t-1];
	if (t * 2 > level.size()) root->left = NULL;
	else root->left = create(t * 2);
	if (t * 2 + 1 > level.size()) root->right = NULL;
	else root->right = create(t * 2 + 1);
	return root;
}

void postmin(int t) {
	if (t * 2 <= level.size()) {
		postmin(t * 2);
		if (level[t * 2 - 1] < level[t-1]) flag = 0;
	}
	if (t * 2 + 1 <= level.size()) {
		postmin(t * 2 + 1);
		if (level[t * 2] < level[t-1]) flag = 0;
	}
	post.push_back(level[t - 1]);
}

void postmax(int t) {
	if (t * 2 <= level.size()) {
		postmax(t * 2);
		if (level[t * 2 - 1] > level[t - 1]) flag = 0;
	}
	if (t * 2 + 1 <= level.size()) {
		postmax(t * 2 + 1);
		if (level[t * 2] > level[t - 1]) flag = 0;
	}
	post.push_back(level[t - 1]);
}


/*
void postmin(node *root) {
	if (root->left != NULL) {
		postmin(root->left);
		if (root->left->data < root->data) flag = 0;
	}
	if (root->right != NULL) {
		postmin(root->right);
		if (root->right->data < root->data) flag = 0;
	}
	post.push_back(root->data);
}

void postmax(node *root) {
	if (root->left != NULL) {
		postmax(root->left);
		if (root->left->data > root->data) flag = 0;
	}
	if (root->right != NULL) {
		postmax(root->right);
		if (root->right->data > root->data) flag = 0;
	}
	post.push_back(root->data);
}

void clearnode(node *root) {
	if (root->left != NULL) {
		clearnode(root->left);
	}
	if (root->right != NULL) clearnode(root->right);
	delete(root);
}*/

void display() {
	for (int i = 0; i < post.size(); i++) {
		if (i == 0) printf("%d", post[i]);
		else printf(" %d", post[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d %d", &m, &n);
	while (m--)
	{
		level.clear();
		post.clear();
		flag = 1;
		node *root = NULL;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			level.push_back(tmp);
			//root = create(1);
		}
		vector<int> t = level;
		sort(t.begin(), t.end());
		//小堆或不是
		if (t[0] == level[0]) {
			postmin(1);
			if (flag) {
				printf("Min Heap\n");
				display();
			}
		}
		//大堆或不是
		else
		{
			postmax(1);
			if (flag) {
				printf("Max Heap\n");
				display();
			}
		}
		if (!flag) {
			printf("Not Heap\n");
			display();
		}
		//clearnode(root);
	}
	system("PAUSE");
	return 0;
}