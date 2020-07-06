//创建BST树
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
	int num;
	int level;
	node* left;
	node* right;
};
int maxlevel = -1;

node* create(node *p,int t,int level) {
	if (p == NULL) {
		node *root = new node;
		root->num = t;
		root->right = root->left = NULL;
		root->level = level;
		if (maxlevel < level)
			maxlevel = level;
		return root;
	}
	else {
		if (t > p->num) {
			p->right = create(p->right, t,level+1);
		}
		else if(t<=p->num){
			p->left = create(p->left, t,level+1);
		}
		return p;
	}
}
int n1 = 0, n2 = 0;
void post(node *root) {
	if (root != NULL) {
		post(root->left);
		post(root->right);
		if (root->level == maxlevel) {
			n2++;
		}
		else if(root->level == maxlevel-1)
		{
			n1++;
		}
	}
}

vector<int> num(1000);
int maxdepth = -1;


int main() {
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		root = create(root, tmp,0);
	}
	post(root);
	printf("%d + %d = %d", n2, n1, n1 + n2);
	system("PAUSE");
	return 0;
}