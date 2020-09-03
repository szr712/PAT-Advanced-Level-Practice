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

int n;
vector<int>level, sorted;
vector<int>path;
bool flag = 1;
void display();

void getpath(int root) {
	path.push_back(level[root - 1]);
	if (root * 2 + 1 > n) {
		if (root * 2 > n) {
			display();
			path.pop_back();
			return;
		}
	}
	else
	{
		getpath(root * 2 + 1);
	}
	if (root * 2 > n) {
		display();
		path.pop_back();
		return;
	}
	else
	{
		getpath(root * 2);
	}
	path.pop_back();
	return;
}


bool checkmax() {
	if (flag)
	{
		for (int i = 1; i < path.size(); i++) {
			if (path[i] > path[i - 1]) flag = 0;
		}
	}
	return flag;
}

bool checkmin() {
	if (flag)
	{
		for (int i = 1; i < path.size(); i++) {
			if (path[i] < path[i - 1]) flag = 0;
		}
	}
	return flag;
}

void display() {
	if (sorted[0] == level[0]) {
		checkmin();
	}
	else
	{
		checkmax();
	}
	for (int i = 0; i < path.size(); i++) {
		if (i == 0)printf("%d", path[i]);
		else printf(" %d", path[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		level.push_back(tmp);
	}
	sorted = level;
	sort(sorted.begin(), sorted.end());
	getpath(1);
	if (!flag) {
		printf("Not Heap\n");
	}
	else if (sorted[0] == level[0]) {
		printf("Min Heap\n");
	}
	else {
		printf("Max Heap\n");
	}
	system("PAUSE");
	return 0;
}