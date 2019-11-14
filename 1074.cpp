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
	int data;
	int pos;
};
map<int, pair<int,int>> ns;
vector<node>link;

bool cmp(node a, node b) {
	return a.pos > b.pos;
}

int start,n,k;

int main() {
	scanf("%d %d %d", &start, &n, &k);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ns[a].first = b;
		ns[a].second = c;
	}
	int tmpa=start,i=0;
	while (start != -1) {
		i++;
		node tmp;
		tmp.add = start;
		tmp.pos = i;
		tmp.data = ns[start].first;
		link.push_back(tmp);
		start = ns[start].second;
	}
	for (int i = 0; i < link.size(); i++) {
		if ((i + 1) % k == 0) {
			sort(link.begin() + i+1 - k, link.begin() + i + 1,cmp);
		}
	}
	for (int i = 0; i < link.size(); i++) {
		if (i != link.size() - 1) {
			printf("%05d %d %05d\n", link[i].add, link[i].data, link[i+1].add);
		}
		else {
			printf("%05d %d -1", link[i].add, link[i].data);
		}
	}
	
	system("PAUSE");
}