#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

struct student
{
	char name[15],id[15];
	bool gender;
};
int n;
vector<student> grade[105];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		student tmp;
		char g;
		int s;
		scanf("%s %c %s %d", tmp.name, &g,tmp.id, &s);
		if (g == 'M')tmp.gender = 1;
		else tmp.gender = 0;
		grade[s].push_back(tmp);
	}
	int fe = -1, me = -1;
	for (int i = 100; i >= 0; i--) {
		for (int j = 0; j < grade[i].size(); j++) {
			if (grade[i][j].gender == 0) {
				fe = i;
				printf("%s %s\n", grade[i][j].name, grade[i][j].id);
				break;
			}
		}
		if (fe != -1)break;
	}
	if (fe == -1) {
		printf("Absent\n");
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j < grade[i].size(); j++) {
			if (grade[i][j].gender == 1) {
				me = i;
				printf("%s %s\n", grade[i][j].name, grade[i][j].id);
				break;
			}
		}
		if (me != -1) break;
	}
	if (me == -1) {
		printf("Absent\n");
	}
	if (me == -1 || fe == -1) {
		printf("NA\n");
	}
	else {
		printf("%d\n", fe - me);
	}
	system("PAUSE");
}