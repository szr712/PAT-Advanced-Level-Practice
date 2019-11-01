//很烦的一道模拟题
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

struct mice
{
	int w;
	int rank;
	int o1;
	int o2;
};
int n, g;
vector<mice> weight;
queue<mice*> line;
queue<mice*> group;
bool cmp1(mice a, mice b) {
	return a.rank > b.rank;
}
bool cmp2(mice a, mice b) {
	return a.o1 < b.o1;
}

int main() {
	scanf("%d %d", &n, &g);
	for (int i = 0; i < n; i++) {
		mice tmp;
		scanf("%d", &tmp.w);
		tmp.rank = -1;
		tmp.o1 = i;
		weight.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		line.push(&weight[tmp]);
	}
	int r = 1;
	int count = 0;
	mice *maxm = line.front();
	while (line.size() != 1 || !group.empty()) {
		if (!line.empty()) {
			if (line.front()->rank != r && !line.empty()) {
				mice* tmp = line.front();
				line.pop();
				tmp->rank = r;
				count++;
				if (count == 1) {
					maxm = tmp;
					group.push(tmp);
				}
				else {
					if (maxm->w < tmp->w) maxm = tmp;
					group.push(tmp);
				}
				if (count == g) {
					line.push(maxm);
					count = 0;
					group = queue<mice*>();
				}
			}
			else
			{
				if (!group.empty()) {
					line.push(maxm);
					count = 0;
					group = queue<mice*>();
				}
				else {
					r++;
				}
			}
		}
		else
		{
			if (!group.empty()) {
				line.push(maxm);
				count = 0;
				group = queue<mice*>();
			}
			else {
				r++;
			}
		}


	}
	line.front()->rank = r+1;
	count = 1;
	r = 1;
	sort(weight.begin(), weight.end(), cmp1);
	weight[0].o2 = 1;
	for (int i = 1; i < weight.size(); i++) {
		count++;
		if (weight[i].rank != weight[i - 1].rank) {
			r = count;
		}
		weight[i].o2 = r;
	}
	sort(weight.begin(), weight.end(), cmp2);
	printf("%d", weight[0].o2);
	for (int i = 1; i < weight.size(); i++) {
		printf(" %d", weight[i].o2);
	}
	system("PAUSE");
}