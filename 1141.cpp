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
struct testee
{
	string id;
	int score;
	string school;
};
struct total
{
	string school;
	double tws;
	int ns;
};
map<string, vector<testee>> tests;
vector<total> ranklist;

bool cmp(total a, total b) {
	if (a.tws > b.tws) return true;
	else if (a.tws == b.tws) {
		if (a.ns < b.ns) return true;
		else if (a.ns == b.ns) {
			if (a.school < b.school) return true;
		}
	}
	return false;
}


int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		char id[10];
		int score;
		char school[10];
		scanf("%s %d %s", id, &score, school);
		testee tmp;
		tmp.id = id;
		for (int i = 0; i < strlen(school); i++) {
			if (school[i] >= 'A'&&school[i] <= 'Z') {
				school[i] += 'a' - 'A';
			}
		}
		tmp.school = school;
		tmp.score = score;
		tests[tmp.school].push_back(tmp);
	}
	for (auto i = tests.begin(); i != tests.end(); i++) {
		total tmp;
		tmp.tws = 0;
		tmp.ns = i->second.size();
		tmp.school = i->first;
;		for (int j = 0; j < i->second.size(); j++) {
			if (i->second[j].id[0] == 'B') tmp.tws += (i->second[j].score / 1.5);
			else if (i->second[j].id[0] == 'A') tmp.tws += i->second[j].score;
			else if(i->second[j].id[0]=='T')tmp.tws += (i->second[j].score * 1.5);
		}
		tmp.tws = int(tmp.tws);
		ranklist.push_back(tmp);
	}
	sort(ranklist.begin(), ranklist.end(), cmp);
	printf("%d\n", ranklist.size());
	int r = 1;
	printf("%d %s %.0lf %d\n", r, ranklist[0].school.c_str(), ranklist[0].tws, ranklist[0].ns);
	for (int i = 1; i < ranklist.size(); i++) {
		if (ranklist[i].tws != ranklist[i - 1].tws) r = i + 1;
		printf("%d %s %.0lf %d\n", r, ranklist[i].school.c_str(), ranklist[i].tws, ranklist[i].ns);
	}

	system("PAUSE");
	return 0;
}