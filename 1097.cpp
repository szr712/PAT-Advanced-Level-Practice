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
	int add;
	int num;
};
int start,n;
map<int, pair<int, int>> ori;
vector<node>result, removed;
set<int> k;

int main() {
	scanf("%d %d", &start, &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pair<int, int>tmp;
		tmp.first = b;
		tmp.second = c;
		ori[a] = tmp;
	}
	while (start != -1) {
		node tmp;
		tmp.add = start;
		tmp.num = ori[start].first;
		if (k.find(abs(tmp.num)) == k.end()) {
			k.insert(abs(tmp.num));
			result.push_back(tmp);
		}
		else
		{
			removed.push_back(tmp);
		}
		start = ori[start].second;
	}
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() -1) {
			printf("%05d %d -1\n", result[result.size() - 1].add, result[result.size() - 1].num);
		}
		else {
			printf("%05d %d %05d\n", result[i].add, result[i].num, result[i + 1].add);
		}
	}
	
	for (int i = 0; i < removed.size(); i++) {
		if (i == removed.size() -1) {
			printf("%05d %d -1\n", removed[removed.size() - 1].add, removed[removed.size() - 1].num);
		}
		else {
			printf("%05d %d %05d\n", removed[i].add, removed[i].num, removed[i + 1].add);
		}
	}
	system("PAUSE");
	return 0;
	
}