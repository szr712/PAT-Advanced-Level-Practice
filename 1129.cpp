//重载运算符
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

int n, k;
struct node
{
	int item;
	int cou;
};

bool operator<(const node a, const node b) {
	return a.cou == b.cou ? a.item < b.item : a.cou>b.cou;
}

bool operator==(const node a, const node b) {
	if (a.item == b.item&&a.cou == b.cou) return true;
	else return false;
}


vector<int>seq;
set<node> qur;
map<int, int> coun;


int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	node begin;
	begin.cou = 1;
	begin.item = seq[0];
	qur.insert(begin);
	coun[seq[0]] = 1;
	for (int i = 1; i < n; i++) {
		printf("%d:", seq[i]);
		int cnt = 0;
		for(auto j=qur.begin();j!=qur.end()&&cnt<k;j++)
		{
			printf(" %d", j->item);
			cnt++;
		}
		printf("\n");
		if (coun.find(seq[i]) == coun.end()) {
			coun[seq[i]] = 1;
			node tmp;
			tmp.item = seq[i];
			tmp.cou = coun[seq[i]];
			qur.insert(tmp);
		}
		else {
			node tmp;
			tmp.item = seq[i];
			tmp.cou = coun[seq[i]];
			tmp = *qur.find(tmp);
			qur.erase(tmp);
			tmp.cou += 1;
			qur.insert(tmp);
			coun[seq[i]]++;
		}

		
	}


	system("PAUSE");
	return 0;
}