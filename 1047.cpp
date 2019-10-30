//也考察了输入输出的问题，用string超时
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

struct student
{
	char name[10];
};

int n, k;
vector<student> course[2505];

bool cmp(student a, student b) {
	if (strcmp(a.name, b.name) < 0)return 1;
	else return 0;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		student tmp;
		scanf("%s", tmp.name);
		int c;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			int t;
			scanf("%d", &t);
			course[t].push_back(tmp);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++) {
			printf("%s\n", course[i][j].name);

		}
	}
	system("PAUSE");
}