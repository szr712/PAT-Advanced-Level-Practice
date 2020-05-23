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
	int l, r;
};
vector<int> num,in;
vector<node> tree;

int t = 0;

void level(node root) {
	queue<node> que;
	que.push(root);
	while (!que.empty()) {
		node tmp = que.front();
		que.pop();
		t++;
		printf("%d", tmp.data);
		if (t != n) {
			printf(" ");
		}
		if (tmp.r != -1) {
			que.push(tree[tmp.r]);
		}
		if (tmp.l != -1) {
			que.push(tree[tmp.l]);
		}
	}
}

void inorder(node root) {
	if (root.r != -1) {
		inorder(tree[root.r]);
	}
	in.push_back(root.data);
	if (root.l != -1) {
		inorder(tree[root.l]);
	}
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		node tmp;
		tmp.data = i;
		char a[3], b[3];
		scanf("%s %s", a, b);
		if (strcmp(a, "-") == 0) {
			tmp.l = -1;
		}
		else {
			tmp.l = atoi(a);
			num.push_back(tmp.l);
		}
		if (strcmp(b, "-") == 0) {
			tmp.r = -1;
		}
		else {
			tmp.r = atoi(b);
			num.push_back(tmp.r);
		}
		tree.push_back(tmp);
	}
	sort(num.begin(), num.end());
	node root=*tree.rbegin();
	for (int i = 0; i < n-1; i++) {
		if (num[i] != num[i + 1] - 1) {
			root = tree[num[i] + 1];
			break;
		}
	}
	level(root);
	inorder(root);
	printf("\n%d", in[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", in[i]);
	}
	system("PAUSE");
	return 0;

}