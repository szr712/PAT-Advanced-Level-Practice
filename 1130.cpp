// 超级坑点，此处运算符不止加减乘除和取余，还有其他的，所以只能老老实实用判断叶子结点的方式判断该节点是否为运算数
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

const int maxn = 0x3fffffff;

int n;
struct node
{
	string data;
	int left, right;
};

vector<node> tree;

map<string,int> opera;

//stack<string> x;
/*
void in(int root) {
	if (tree[root].data != "+"&&tree[root].data != "-"&&tree[root].data != "*"&&tree[root].data != "/"&&tree[root].data != "%") {
		printf("%s", tree[root].data.c_str());
	}
	else
	{
		if (x.empty()) {
			x.push(tree[root].data);
			if(tree[root].left!=-1) in(tree[root].left);
			printf("%s", tree[root].data.c_str());
			x.pop();
			if (tree[root].right != -1)in(tree[root].right);
		}
		else
		{
			if (opera[tree[root].data] < opera[x.top()]) {
				printf("(");
				x.push(")");
			}
			x.push(tree[root].data);
			if (tree[root].left != -1) in(tree[root].left);
			printf("%s", tree[root].data.c_str());
			x.pop();
			if (tree[root].right != -1)in(tree[root].right);
			if (x.top() == ")") {
				printf(")");
				x.pop();
			}
			
		}
	}

}*/

string ans="";

void in(int root) {
	if (root == -1) return;
	
	/*if (tree[root].data != "+"&&tree[root].data != "-"&&tree[root].data != "*"&&tree[root].data != "/"&&tree[root].data != "%") {
		ans = ans + tree[root].data;
	}*/
	if (tree[root].left == -1 && tree[root].right == -1) {
		ans = ans + tree[root].data;
		return;
	}
	else {
		ans = ans + "(";
		in(tree[root].left);
		ans = ans + tree[root].data;
		in(tree[root].right);
		ans = ans + ")";
	}
	
	
}

int main() {
	scanf("%d", &n);
	tree.resize(n + 1);
		opera["+"] = 1;
		opera["-"] = 1;
		opera["*"] = 2;
		opera["/"] = 2;
		opera["%"] = 2;
	for (int i = 1; i <= n; i++) {
		char tmp[15];
		node t;
		scanf("%s %d %d", tmp,&t.left,&t.right);
		t.data = tmp;
		tree[i] = t;
	}
	vector<int> findroot;
	findroot.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		findroot[i]++;
		if (tree[i].left != -1) {
			findroot[tree[i].left]++;
		}
		if (tree[i].right != -1)
		{
			findroot[tree[i].right]++;
		}
	}
	int root;
	for (int i = 1; i <= n; i++) {
		if (findroot[i] % 2) {
			root = i;
			break;
		}
	}
	in(root);
	/*while(!x.empty()) {
		printf("%s", x.top());
		x.pop();
	}*/
	if(ans[0]=='(')ans=ans.substr(1, ans.size() - 2);
	cout << ans;
	system("PAUSE");
	return 0;
}