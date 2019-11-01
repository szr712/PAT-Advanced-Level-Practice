// 非常容易超时的一道题
// 一开始用年龄最为map的key值，怎么弄都超时的，后来发现输出的要求是首先按照钱排序，所以后来将map的key改成了钱
// 并且可以在输入完成后就对map的value排序，这样输出的时候就不用排序了
// 剪枝的部分在，如果ans数组内的内容超过m个就不需要再去查找接下来的内容了
// 如果同样钱的情况下，年龄超过max了，接下来也不需要考虑了
// 中间用到了，map反过来遍历，迭代器等于rbegin()和rend()
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<stack>
using namespace std;

struct person
{
	char name[10];
	int age;
	int worth;
};
map<int, vector<person>> people;
int n, k;
bool cmp(person a, person b) {
	if (a.worth > b.worth) return 1;
	else if (a.worth == b.worth) {
		if (a.age < b.age) return 1;
		else if (a.age == b.age) {
			if (strcmp(a.name, b.name) <= 0) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		person tmp;
		scanf("%s %d %d", tmp.name, &tmp.age, &tmp.worth);
		people[tmp.worth].push_back(tmp);
	}
	for (auto i = people.begin(); i != people.end(); i++) {
		sort(i->second.begin(), i->second.end(), cmp);
	}
	int t = 1;
	for (int i = 0; i < k; i++) {
		int m, amin, amax;
		scanf("%d %d %d", &m, &amin, &amax);
		printf("Case #%d:\n", t);
		vector<person> ans;
		for (auto i = people.rbegin(); i != people.rend(); i++) {
			for (int j = 0; j < i->second.size(); j++) {
				if (i->second[j].age > amax) break;
				if (i->second[j].age <= amax && i->second[j].age >= amin) {
					ans.push_back(i->second[j]);
					if (ans.size() == m) break;
				}
			}
			if (ans.size() == m) break;
		}
		if (ans.size() == 0) {
			printf("None\n");
			continue;
		}
		for (int i = 0; i < ans.size() && i < m; i++) {
			printf("%s %d %d\n", ans[i].name, ans[i].age, ans[i].worth);
		}
		t++;
	}
	system("PAUSE");
}