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

struct application
{
	int pos;
	int exam, inter;
	int total;
	vector<int> choice;
};

int n, m, k;
int quota[105];
map<int, vector<application>> app[205];
vector<int> admit[105];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	memset(quota, 0, sizeof(quota));
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		quota[i] = tmp;
	}
	for (int i = 0; i < n; i++) {
		application tmp;
		tmp.pos = i;
		scanf("%d %d", &tmp.exam, &tmp.inter);
		tmp.total = tmp.exam + tmp.inter;
		for (int j = 0; j < k; j++) {
			int t;
			scanf("%d", &t);
			tmp.choice.push_back(t);
		}
		app[tmp.total][tmp.exam].push_back(tmp);
	}
	for (int i = 200; i >= 0; i--) {
		if (!app[i].empty()) {
			for (auto iter = app[i].rbegin(); iter != app[i].rend(); iter++) {
				if (iter->second.size() == 1) {
					int pos = iter->second[0].pos;
					vector<int> choice = iter->second[0].choice;
					for (int j = 0; j < k; j++) {
						if (quota[choice[j]] > 0) {
							quota[choice[j]]--;
							admit[choice[j]].push_back(pos);
							break;
						}
					}
				}
				else {
					set<int> tmp;
					for (int j = 0; j < iter->second.size(); j++) {
						int pos = iter->second[j].pos;
						vector<int> choice = iter->second[j].choice;
						for (int t = 0; t < k; t++) {
							if (quota[choice[t]] > 0 || tmp.find(choice[t]) != tmp.end()) {
								quota[choice[t]]--;
								admit[choice[t]].push_back(pos);
								tmp.insert(choice[t]);
								break;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		bool flag = 0;
		sort(admit[i].begin(), admit[i].end());
		for (int j = 0; j < admit[i].size(); j++) {
			if (!flag) {
				flag = 1;
				printf("%d", admit[i][j]);
			}
			else {
				printf(" %d", admit[i][j]);
			}
		}
		printf("\n");

	}
	system("PAUSE");
}