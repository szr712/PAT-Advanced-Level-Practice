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

int n, k;
struct person
{
	char name[10];
	int height;
	int pos;
};

vector<person> all, row;

bool cmp(person a, person b) {
	if (a.height > b.height) {
		return true;
	}
	else if (a.height == b.height)
	{
		if (strcmp(a.name, b.name) < 0) {
			return true;
		}
		else return false;
	}
	else return false;
}

void display() {
	printf(row[0].name);
	for (int i = 1; i < row.size(); i++) {
		printf(" ");
		printf(row[i].name);
	}
	printf("\n");
}

bool cmp2(person a, person b) {
	return a.pos < b.pos;
}


int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		person tmp;
		scanf("%s %d", tmp.name, &tmp.height);
		all.push_back(tmp);
	}
	sort(all.begin(), all.end(), cmp);
	int cnt = 0;
	int num = n / k;
	int last = n - num * (k - 1);
	//先出最后一排
	int cen = last / 2 + 1;
	for (int i = 0; i < last; i++) {
		if (i % 2 == 0) {
			all[cnt].pos = cen + i;
		}
		else {
			all[cnt].pos = cen - i;
		}
		row.push_back(all[cnt]);
		cnt++;
	}
	sort(row.begin(), row.end(), cmp2);
	display();

	//剩下的排
	for (int j = 0; j < k - 1; j++) {
		cen = num / 2 + 1;
		row = vector<person>();
		for (int i = 0; i < num; i++) {
			if (i % 2 == 0) {
				all[cnt].pos = cen + i;
			}
			else {
				all[cnt].pos = cen - i;
			}
			row.push_back(all[cnt]);
			cnt++;
		}
		sort(row.begin(), row.end(), cmp2);
		display();
	}

	system("PAUSE");
	return 0;
}