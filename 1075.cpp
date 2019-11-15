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

struct submision
{
	int id;
	int score;
};
struct total
{
	vector<int> sub;
	int id;
	int totscore;
	int perfect;
};

int n, k, m;
int full[6] = { 0 };
map<int, vector<submision>> sub;
vector<total> ans;

bool cmp(submision a, submision b) {
	return a.id < b.id;
}

bool cmp2(total a, total b) {
	if (a.totscore > b.totscore) return 1;
	else if (a.totscore == b.totscore) {
		if (a.perfect > b.perfect)return 1;
		else if (a.perfect == b.perfect) {
			if (a.id < b.id)return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &full[i]);
	}
	for (int i = 0; i < m; i++) {
		submision tmp;
		int id;
		scanf("%d %d %d", &id, &tmp.id, &tmp.score);
		if (sub.find(id) == sub.end()) {
			sub[id].push_back(tmp);
		}
		else {
			bool flag = 1;
			for (int i = 0; i < sub[id].size(); i++) {
				if (tmp.id == sub[id][i].id&&tmp.score > sub[id][i].score) {
					flag = 0;
					sub[id][i].score = tmp.score;
					break;
				}
				else if (tmp.id == sub[id][i].id&&tmp.score <= sub[id][i].score) {
					flag = 0;
				}
			}
			if(flag) sub[id].push_back(tmp);
		}

	}
	for (auto i = sub.begin(); i != sub.end(); i++) {
		sort(i->second.begin(), i->second.end(), cmp);
		int t = -2;
		total tmp;
		tmp.totscore = 0; tmp.perfect = 0;
		tmp.id = i->first;
		for (int i = 0; i < k; i++) {
			tmp.sub.push_back(t);
		}
		for (int j = 0; j < i->second.size(); j++) {
			if (i->second[j].score != -1) {
				tmp.totscore += i->second[j].score;
				if (full[i->second[j].id] == i->second[j].score) {
					tmp.perfect += 1;
				}
			}
			else {
				tmp.totscore += 0;
			}
			tmp.sub[i->second[j].id - 1] = i->second[j].score;
		}
		bool flag = 0;
		for (int i = 0; i < k; i++) {
			if (tmp.sub[i] > -1) {
				flag = 1;
				break;
			}
		}
		if (flag)ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end(), cmp2);
	int rank = 1, last = ans[0].totscore;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].totscore != last) {
			rank = i + 1;
			last = ans[i].totscore;
		}
		printf("%d %05d %d", rank, ans[i].id, ans[i].totscore);
		for (int j = 0; j < k; j++) {
			if (ans[i].sub[j] == -2) {
				printf(" -");
			}
			else if (ans[i].sub[j] == -1) {
				printf(" 0");
			}
			else
			{
				printf(" %d", ans[i].sub[j]);
			}
		}
		printf("\n");
	}
	system("PAUSE");
}