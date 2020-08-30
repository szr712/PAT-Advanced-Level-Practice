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

int p, m, n;
struct grade
{
	string name;
	int  online, mid, fin, tot;
};

map<string, grade> students;
vector<grade>que;

void getin() {
	for (int i = 0; i < p; i++) {
		char a[25];
		grade g;
		g.online = -1;
		g.mid = -1;
		g.fin = -1;
		g.tot = -1;
		scanf("%s %d", a, &g.online);
		string name = a;
		students[name] = g;
	}
	for (int i = 0; i < m; i++) {
		char a[25];
		int mi;
		grade g;
		g.online = -1;
		g.mid = -1;
		g.fin = -1;
		g.tot = -1;
		scanf("%s %d", a, &mi);
		string name = a;
		if (students.find(name) != students.end()) {
			students[name].mid = mi;
		}
		else {
			g.mid = mi;
			students[name] = g;
		}
	}
	for (int i = 0; i < n; i++) {
		char a[25];
		int fi;
		grade g;
		g.online = -1;
		g.mid = -1;
		g.fin = -1;
		g.tot = -1;
		scanf("%s %d", a, &fi);
		string name = a;
		if (students.find(name) != students.end()) {
			students[name].fin = fi;
		}
		else {
			g.fin = fi;
			students[name] = g;
		}
	}
}

void certificate() {
	for (auto i = students.begin(); i != students.end(); i++) {
		i->second.name = i->first;
		if (i->second.mid > i->second.fin) {
			i->second.tot = (i->second.mid*0.4 + i->second.fin*0.6)+0.5;
		}
		else
		{
			i->second.tot = i->second.fin;
		}
		if (i->second.online >= 200 && i->second.tot >= 60 && i->second.tot <= 100) {
			que.push_back(i->second);
		}
	}
}

bool cmp(grade a, grade b) {
	if (a.tot > b.tot) return true;
	else if (a.tot == b.tot) {
		return a.name < b.name;
	}
	return false;
}



int main() {
	scanf("%d %d %d", &p, &m, &n);
	getin();
	certificate();
	sort(que.begin(), que.end(), cmp);
	for (int i = 0; i < que.size(); i++) {
		printf("%s %d %d %d %d\n", que[i].name.c_str(), que[i].online, que[i].mid, que[i].fin, que[i].tot);
	}

	
	system("PAUSE");
	return 0;
}