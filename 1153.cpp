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

int n, m;

struct node
{
	string num;
	int level, site, date, testee;
	int score;
};

struct sites
{
	int site;
	int cnt;
};

vector<node> lev[26], sit[1005], dat[1000005];

//map<string, vector<node>> lev, sit,dat;

bool cmp(node a, node b) {
	if (a.score > b.score) return true;
	else if (a.score == b.score) {
		if (a.num < b.num) return true;
	}
	return false;
}

bool cmp2(sites a, sites b) {
	if (a.cnt > b.cnt) return true;
	if (a.cnt == b.cnt) {
		if (a.site < b.site) return true;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char t[20];
		node tmp;
		scanf("%s %d", t, &tmp.score);
		tmp.num = t;
		tmp.level = tmp.num[0]-'A';
		tmp.site = stoi(tmp.num.substr(1, 3));
		tmp.date = stoi(tmp.num.substr(4, 6));
		tmp.testee = stoi(tmp.num.substr(10, 3));
		lev[tmp.level].push_back(tmp);
		sit[tmp.site].push_back(tmp);
		dat[tmp.date].push_back(tmp);
	}
	int index = 1;
	while (m--)
	{
		int type;
		char t[20];
		//int input;
		scanf("%d %s", &type, t);
		//string in = t;
		printf("Case %d: %d %s\n", index, type, t);
		map<int, int> l;
		if (type == 1) {
			int input = -1;
			if (strcmp(t, "A") == 0) {
				input = 0;
			}
			else if (strcmp(t, "B") == 0) {
				input = 1;
			}
			else if (strcmp(t, "T") == 0) {
				input = 'T' - 'A';
			}
			if (lev[input].size() == 0) {
				printf("NA\n");
			}
			else
			{
				if (l[input] == 0) {
					sort(lev[input].begin(), lev[input].end(), cmp);
					l[input] = 1;
				}
				for (int i = 0; i < lev[input].size(); i++) {
					printf("%s %d\n", lev[input][i].num.c_str(), lev[input][i].score);
				}
			}
		}
		else if (type == 2) {
			int input = stoi(t);
			if (sit[input].size() == 0) {
				printf("NA\n");
			}
			else
			{
				printf("%d ", sit[input].size());
				int ans = 0;
				for (int i = 0; i < sit[input].size(); i++) {
					ans += sit[input][i].score;
				}
				printf("%d\n", ans);
			}
		}
		else if (type == 3) {
			int input = stoi(t);
			if (dat[input].size() == 0) {
				printf("NA\n");
			}
			else {
				int s[1005] = { 0 };
				for (int i = 0; i < dat[input].size(); i++) {
					s[dat[input][i].site]++;
				}
				vector<sites> ans;
				for (int i = 0; i < 1005; i++) {
					if (s[i] != 0) {
						sites tmp;
						tmp.cnt = s[i];
						tmp.site = i;
						ans.push_back(tmp);
					}
				}
				sort(ans.begin(), ans.end(), cmp2);
				for (int i = 0; i < ans.size(); i++) {
					printf("%03d %d\n", ans[i].site, ans[i].cnt);
				}
			}
		}
		index++;
	}

	system("PAUSE");
	return 0;
}