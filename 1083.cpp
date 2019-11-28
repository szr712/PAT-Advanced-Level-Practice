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

struct student
{
	char name[15];
	char id[15];
};

vector<student> record[105];
int n;
int g1, g2;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		student tmp;
		int grade;
		scanf("%s %s %d", tmp.name, tmp.id, &grade);
		record[grade].push_back(tmp);
	}
	scanf("%d %d", &g1, &g2);
	bool flag = 0;
	for (int i = g2; i >= g1; i--) {
		if (!record[i].empty()) {
			flag = 1;
			printf("%s %s\n", record[i][0].name, record[i][0].id);
		}
	}
	if (!flag) {
		printf("NONE\n");
	}
	system("PAUSE");
}