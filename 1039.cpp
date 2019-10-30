//很简单，建立一个string和int的映射就全搞定了
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

int n, k;
map<string, vector<int>> course;
bool cmp(int a, int b) {
	return a < b;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int index, num;
		scanf("%d %d", &index, &num);
		for (int j = 0; j < num; j++) {
			string tmp;
			cin >> tmp;
			course[tmp].push_back(index);
		}
	}
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		sort(course[tmp].begin(), course[tmp].end(), cmp);
		cout << tmp;
		printf(" %d", course[tmp].size());
		for (int j = 0; j < course[tmp].size(); j++) {
			printf(" %d", course[tmp][j]);
		}
		printf("\n");
	}
	system("PAUSE");
}