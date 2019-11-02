/*
这道题是真的难！！！！！！！
网上大部分的思路是用树状数组
我是维护了两个multiset集合
主要的wa的地方在于对重复元素的处理
此题用到技巧有：multiset可以储存重复元素
因为multiset中有重复元素，因此在删除的时候erase的参数应该是迭代器，不能是数字，否则会把所有相同数字的内容都删掉了
另：multimap可以储存相同key的不同对
*/
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
stack<int> mystack;
multiset<int> lset, rset;

int main() {
	scanf("%d", &n);
	char command[15];
	for (int i = 0; i < n; i++) {
		scanf("%s", command);
		if (strcmp(command, "Pop") == 0) {
			if (mystack.empty()) {
				printf("Invalid\n");
			}
			else {
				int top = mystack.top();
				if (lset.find(top) != lset.end()) {
					lset.erase(lset.find(top));
				}
				else {
					rset.erase(rset.find(top));
				}
				printf("%d\n", mystack.top());
				mystack.pop();
				int size = mystack.size();
				if (size % 2 == 0) {
					size /= 2;
				}
				else {
					size = (size + 1) / 2;
				}
				while (lset.size() > size) {
					auto it = lset.end();
					it--;
					rset.insert(*it);
					lset.erase(it);
				}
				while (lset.size() < size) {
					auto it = rset.begin();
					lset.insert(*it);
					rset.erase(it);
				}
			}
		}
		else if (strcmp(command, "PeekMedian") == 0) {
			int size = mystack.size();
			if (size == 0) {
				printf("Invalid\n");
			}
			else {
				printf("%d\n", *lset.rbegin());
			}
		}
		else if (strcmp(command, "Push") == 0) {
			int tmp;
			scanf("%d", &tmp);
			mystack.push(tmp);
			if (rset.empty() && lset.empty()) {
				lset.insert(tmp);
			}
			else if (rset.empty()) {
				lset.insert(tmp);
			}
			else if (lset.empty()) {
				rset.insert(tmp);
			}
			else if (tmp <= *lset.rbegin()) {
				lset.insert(tmp);
			}
			else {
				rset.insert(tmp);
			}
			int size = mystack.size();
			if (size % 2 == 0) {
				size /= 2;
			}
			else {
				size = (size + 1) / 2;
			}
			while (lset.size() > size) { 
				auto it = lset.end();
				it--;
				rset.insert(*it);
				lset.erase(it);
			}
			while (lset.size() < size) {
				auto it = rset.begin();
				lset.insert(*it);
				rset.erase(it);
			}
		}
	}
	system("PAUSE");
}