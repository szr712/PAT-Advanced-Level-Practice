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

int n, start, k;
struct node
{
	int add, next;
	int data;
	int pos;
};

map<int, node> chain;
vector<node> order;

bool cmp(node a, node b) {
	return a.data < b.data;
}
bool cmp2(node a, node b) {
	return a.pos < b.pos;
}

int main() {
	scanf("%d %d %d", &start,&n,&k);
	for (int i = 0; i < n; i++) {
		node tmp;
		scanf("%d %d %d", &tmp.add, &tmp.data, &tmp.next);
		chain[tmp.add] = tmp;
	}
	int begin = chain[start].add;
	int t = 1,neg=0,gra=0;
	while (begin != -1) {
		chain[begin].pos = t;
		if (chain[begin].data < 0) neg++;
		if (chain[begin].data <= k) gra++;
		t++;
		order.push_back(chain[begin]);
		begin = chain[begin].next;
	}
	sort(order.begin(), order.end(), cmp);
	//printf("%d", (order.begin() + gra)->data);
	//k = max(neg, gra);
	sort(order.begin(), order.begin() + neg , cmp2);
	if (gra >= neg) {
		sort(order.begin() + neg, order.begin() + gra, cmp2);
		sort(order.begin() + gra, order.end(), cmp2);
	}
	else
	{
		sort(order.begin() + neg, order.end(), cmp2);
	}
	
	for (int i = 0; i < order.size()-1; i++) {
		printf("%05d %d %05d\n", order[i].add, order[i].data, order[i + 1].add);
	}
	printf("%05d %d -1", order[order.size() - 1].add, order[order.size() - 1].data);
	
	system("PAUSE");
	return 0;
}