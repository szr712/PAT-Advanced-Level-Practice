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

int n,m;
vector<int> pre;
set<int> nodes;

struct node
{
	int data;
	node *left, *right;
};

node* create(int l, int r) {
	node *root = new node();
	root->data = pre[l];
	int i = l + 1;
	for (; i <= r; i++) {
		if (pre[i] >= pre[l]) break;
	}
	root->left = create(l + 1, i - 1);
	root->right = create(i, r - 1);
	return root;
}


int main() {
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		pre.push_back(tmp);
		nodes.insert(tmp);
	}
	//node *root = create(0, n - 1);
	while (n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (nodes.find(a) == nodes.end() && nodes.find(b) == nodes.end()) {
			printf("ERROR: %d and %d are not found.\n", a, b);
		}
		else if (nodes.find(a) == nodes.end()) {
			printf("ERROR: %d is not found.\n", a);
		}
		else if (nodes.find(b) == nodes.end()) {
			printf("ERROR: %d is not found.\n", b);
		}
		else
		{
			int i;
			for (i = 0; i < m; i++) {
				if ((pre[i] >= a&&pre[i] <= b) || (pre[i]<=a&&pre[i]>=b)) {
					break;
				}
			}
			if (pre[i] == a) printf("%d is an ancestor of %d.\n", a, b);
			else if(pre[i]==b) printf("%d is an ancestor of %d.\n", b, a);
			else printf("LCA of %d and %d is %d.\n", a, b, pre[i]);
		}
	}

	system("PAUSE");
	return 0;
}