// only the ones whose grades of talent and virtue are both not below this line will be ranked的意思是俩个里面只要有一个低于最低线就不行，要注意逻辑
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

int n, l, h;
struct person
{
	char id[10];
	int v, t, all;
};
vector<person> sages, noblemen, fool, small;

bool cmp(person a, person b) {
	if (a.all > b.all) return 1;
	else if (a.all == b.all) {
		if (a.v > b.v)return 1;
		else if (a.v == b.v) {
			if (strcmp(a.id,b.id)<0) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &n, &l, &h);
	for (int i = 0; i < n; i++) {
		person tmp;
		scanf("%s %d %d", tmp.id, &tmp.v,&tmp.t);
		tmp.all = tmp.v + tmp.t;
		if (tmp.v < l||tmp.t < l) continue;
		else if (tmp.v >= h && tmp.t >= h) {
			sages.push_back(tmp);
		}
		else if (tmp.t < h&&tmp.v >= h) {
			noblemen.push_back(tmp);
		}
		else if (tmp.t < h&&tmp.v < h&&tmp.v >= tmp.t) {
			fool.push_back(tmp);
		}
		else if (tmp.t >= l && tmp.v >= l) {
			small.push_back(tmp);
		}
	}
	int size = sages.size() + noblemen.size() + fool.size() + small.size();
	printf("%d\n", size);
	sort(sages.begin(), sages.end(), cmp);
	for (int i = 0; i < sages.size(); i++) {
		printf("%s %d %d\n", sages[i].id, sages[i].v, sages[i].t);
	}
	sort(noblemen.begin(), noblemen.end(), cmp);
	for (int i = 0; i < noblemen.size(); i++) {
		printf("%s %d %d\n", noblemen[i].id, noblemen[i].v, noblemen[i].t);
	}
	sort(fool.begin(), fool.end(), cmp);
	for (int i = 0; i < fool.size(); i++) {
		printf("%s %d %d\n", fool[i].id, fool[i].v, fool[i].t);
	}
	sort(small.begin(), small.end(), cmp);
	for (int i = 0; i < small.size(); i++) {
		printf("%s %d %d\n", small[i].id, small[i].v, small[i].t);
	}
	system("PAUSE");
}