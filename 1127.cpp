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
	int data, l;
	node *left, *right;
};

int n;
vector<int> in, post;
map<int, vector<node*>> ans;

node* create(int il, int ir, int pl, int pr, int l) {
	if (pl > pr || il > ir) {
		return NULL;
	}
	node *root = new node();
	root->data = post[pr];
	root->l = l;

	int i = 0;
	for (i = il; i <= ir; i++) {
		if (in[i] == post[pr]) {
			root->left = create(il, i - 1, pl, pl + (i - il) - 1, l + 1);
			root->right = create(i + 1, ir, pl + (i - il), pr - 1, l + 1);
			break;
		}
	}

	return root;

}

void level(node* root) {
	queue<node*> q;
	q.push(root);

	while (!q.empty())
	{
		node* tmp;
		tmp = q.front();
		q.pop();
		ans[tmp->l].push_back(tmp);
		if (tmp->left != NULL) {
			q.push(tmp->left);
		}
		if (tmp->right != NULL) {
			q.push(tmp->right);
		}
	}
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		in.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		post.push_back(tmp);
	}
	node *root = create(0, n - 1, 0, n - 1, 0);
	level(root);
	printf("%d", root->data);
	for (auto i = ans.begin(); i != ans.end(); i++) {
		if (i->first % 2 == 0 && i->first != 0) {
			for (int j = i->second.size() - 1; j >= 0; j--) {
				printf(" %d", i->second[j]->data);
			}
		}
		else if (i->first != 0) {
			for (int j = 0; j <= i->second.size() - 1; j++) {
				printf(" %d", i->second[j]->data);
			}
		}
	}
	system("PAUSE");
	return 0;
}