// 完全二叉树判定方法：
// 1>如果树为空，则直接返回错
// 　　2>如果树不为空：层序遍历二叉树
// 　　2.1>如果一个结点左右孩子都不为空，则pop该节点，将其左右孩子入队列；
// 　　2.1>如果遇到一个结点，左孩子为空，右孩子不为空，则该树一定不是完全二叉树；
// 　　2.2>如果遇到一个结点，左孩子不为空，右孩子为空；或者左右孩子都为空；则该节点之后的队列中的结点都为叶子节点；该树才是完全二叉树，否则就不是完全二叉树；
// 树寻找根节点：
// 每个节点的id在输入父节点时被输入一次，输入本身时一次，两个子节点时又两次，所以其输入次数肯定为偶数
// 根节点只会被输入奇数次

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
	int index;
	int left, right;
};

vector<node> tree;
int root = -1;

void level() {
	queue<node> que;
	que.push(tree[root]);
	while (!que.empty()) {
		node tmp = que.front();
		if (tmp.left != -1 && tmp.right != -1) {
			que.pop();
			que.push(tree[tmp.left]);
			que.push(tree[tmp.right]);
		}
		else {
			//右孩子有左孩子没的，直接就不是完全二叉树
			if (tmp.left == -1 && tmp.right != -1) {
				printf("NO %d", root);
			}
			//右孩子没的，左孩子不知道有没有，判断队列内剩余结点是不是都是叶子
			else
			{
				//如果有左孩子，就压进去
				if (tmp.left != -1) {
					que.push(tree[tmp.left]);
				}
				node t=que.front();//此处是对只有一个结点的情况特意改的，即“- -”
				que.pop();
				while (!que.empty())
				{
					t = que.front();
					if (t.left == -1 && t.right == -1) {
						que.pop();
					}
					else {
						printf("NO %d", root);
						break;
					}
				}
				if (que.empty()) {
					printf("YES %d", t.index);
				}
			}
			break;
		}
	}

}


int main() {
	int isroot[25] = { 0 };
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		node tmp;
		tmp.index = i;
		isroot[i]++;
		string a, b;//结点可能是两位数
		cin >> a >> b;
		if (a != "-") {
			tmp.left = stoi(a);
			isroot[tmp.left]++;
		}
		else {
			tmp.left = -1;
		}
		if (b != "-") {
			tmp.right = stoi(b);
			isroot[tmp.right]++;
		}
		else
		{
			tmp.right = -1;
		}
		tree.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		if (isroot[i] % 2 != 0&&isroot[i]!=0) {
			root = i;
			break;
		}
	}
	level();

	system("PAUSE");
	return 0;
}