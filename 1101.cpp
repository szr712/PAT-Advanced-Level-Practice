// 两个问题
// 1.快排作为分割点的数，除了左侧都比他小，右侧都比他大，还有需要在最后排序的位置
// 2.需要特别注意输出是0的情况，此题输出为0时，需要多打一个空行
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
	bool l, r, p;
};

vector<node> seq;
vector<int> num;
set<int> mins, maxs;

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		node tmp;
		tmp.r = 0;
		tmp.l = 0;
		tmp.p = 0;
		scanf("%d", &tmp.data);
		num.push_back(tmp.data);
		seq.push_back(tmp);
	}
	sort(num.begin(), num.end());
	seq[0].l = seq[0].r = seq[seq.size() - 1].l = seq[seq.size() - 1].r = 1;
	if (seq[0].data == num[0]) seq[0].p = 1;
	if (seq[n - 1].data == num[n - 1]) seq[n - 1].p = 1;
	mins.insert(seq[0].data);
	maxs.insert(seq[n - 1].data);
	for (int i = 1; i < n - 1; i++) {
		if (*mins.rbegin() < seq[i].data) {
			seq[i].l = 1;
		}
		if (seq[i].data == num[i]) {
			seq[i].p = 1;
		}
		mins.insert(seq[i].data);
	}
	for (int i = n - 2; i >= 1; i--) {
		if (*maxs.begin() > seq[i].data) {
			seq[i].r = 1;
		}
		maxs.insert(seq[i].data);
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (seq[i].l&&seq[i].r&&seq[i].p) {
			ans.push_back(seq[i].data);
		}
	}
	if (!ans.empty()) {
		printf("%d\n%d", ans.size(), ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
	}
	else {
		printf("0\n\n");
	}

	system("PAUSE");
	return 0;

}