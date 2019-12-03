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

vector<int>in;
int n;

struct node
{
	int data;
	node* left;
	node* right;
};

bool flag = 0;

void postOrderTraverse1(node* root) {
	if (root != NULL) {
		postOrderTraverse1(root->left);
		postOrderTraverse1(root->right);
		if (flag) {
			printf(" %d", root->data);
		}
		else
		{
			flag = 1;
			printf("%d", root->data);
		}
	}
}

node* create(int l, int r) {
	if (l >= r)return NULL;
	node* root=new node();
	root->data = in[l];
	int count = 1, pc = 0;
	int i;
	for (i = l+1; i <= r; i++) {
		if (in[i] != -1) {
			count++;
		}
		else
		{
			pc++;
		}
		if (pc == count) break;
	}
	root->left = create(l + 1, i - 1);
	root->right = create(i + 1, r);
	return root;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * 2; i++) {
		char cmd[10];
		scanf("%s", cmd);
		if (strcmp(cmd, "Push") == 0) {
			int x;
			scanf("%d", &x);
			in.push_back(x);
		}
		else {
			in.push_back(-1);
		}
	}
	node* root = new node();
	root=create(0, in.size() - 1);
	postOrderTraverse1(root);
	system("PAUSE");
}