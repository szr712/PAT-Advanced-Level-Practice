//postorder sequences 后序遍历 inorder traversal 中序遍历
//level order traversal 层次遍历
//Preorder traversal 前序遍历
//后序遍历：左右中；中序遍历：左中右；前序遍历：中左右
//后续遍历：
//public void postOrderTraverse1(TreeNode root) {
//    if (root != null) {
//        postOrderTraverse1(root.left);
//        postOrderTraverse1(root.right);
//        System.out.print(root.val+"  ");
//    }
//}
//中序遍历：
//public void inOrderTraverse1(TreeNode root) {
//    if (root != null) {
//        inOrderTraverse1(root.left);
//        System.out.print(root.val+"  ");
//        inOrderTraverse1(root.right);
//    }
//}
//前序遍历：
//public void preOrderTraverse1(TreeNode root) {
//    if (root != null) {
//        System.out.print(root.val+"  ");
//        preOrderTraverse1(root.left);
//        preOrderTraverse1(root.right);
//    }
//}
#include <bits/stdc++.h>

using namespace std;
int n;
struct node {
    int data;
    node *lchild;
    node *rchild;
};

int post[35], in[35], lev[35];

node *creat(int lp, int rp, int li, int ri) {
    if (lp > rp) {
        return NULL;
    }
    node *root = new node;
    root->data = post[rp];
    int i;
    for (i = li; i <= ri; i++) {
        if (in[i] == post[rp]) {
            break;
        }
    }
    int numl = i - li;//左子树的数量
    root->lchild = creat(lp, lp + numl - 1, li, i - 1);//此处注意参数的写法要剔除现在的root
    root->rchild = creat(lp + numl, rp - 1, i + 1, ri);//rp-1是因为要剪掉后序遍历的root
    return root;
}

int num = 0;

void level(node *root) {
    queue<node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        node *tmp = queue.front();
        queue.pop();
        num++;
        printf("%d", tmp->data);
        if (num != n) {
            printf(" ");
        }
        if (tmp->lchild != NULL) {
            queue.push(tmp->lchild);
        }
        if (tmp->rchild != NULL) {
            queue.push(tmp->rchild);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    node *root = creat(0, n - 1, 0, n - 1);
    level(root);
}
