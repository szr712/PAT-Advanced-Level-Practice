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

struct node
{
	char id[10];
	int time;
	int flag = 0;
};

int n,k;

bool cmp1(node a, node b) {
	if (strcmp(a.id, b.id) != 0) {
		return strcmp(a.id, b.id) < 0;
	}
	else {
		return a.time < b.time;
	}
}

bool cmp2(node a, node b) {
	return a.time < b.time;
}


int main() {
	scanf("%d %d", &n, &k);
	vector<node> record;
	for (int i = 0; i < n; i++) {
		node tmp;
		int h, m, s;
		char f[5];
		scanf("%s %d:%d:%d %s", tmp.id, &h, &m, &s, f);
		tmp.time = h * 3600 + m * 60 + s;
		if (strcmp(f, "in") == 0) {
			tmp.flag = 1;
		}
		else tmp.flag = -1;
		record.push_back(tmp);
	}
	sort(record.begin(), record.end(), cmp1);//按照车牌排序
	vector<node> car;
	map<string, int> mp;

	int maxtime = -1;
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(record[i].id, record[i + 1].id) == 0 && record[i].flag==1 && record[i + 1].flag==-1) {
			car.push_back(record[i]);
			car.push_back(record[i + 1]);
			mp[record[i].id] += (record[i + 1].time - record[i].time);
			if (maxtime < mp[record[i].id]) {
				maxtime = mp[record[i].id];
			}
		}
	}
	sort(car.begin(), car.end(), cmp2);//按照时间排序
	vector<int> cnt;//记录每次在的车辆数
	for (int i = 0; i < car.size(); i++) {
		if (i == 0)cnt.push_back(car[i].flag);
		else
		{
			cnt.push_back(cnt[i - 1] + car[i].flag);
		}
	}
	int index = 0;
	for (int i = 0; i < k; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int tmp = h * 3600 + m * 60 + s;
		int j;
		for (j = index; j < car.size(); j++) {
			if (car[j].time > tmp) {
				printf("%d\n", cnt[j - 1]);
				break;
			}
			else if(j==car.size()-1)
			{
				printf("%d\n", cnt[j]);
			}
		}
		index = j;
	}
	for (auto i = mp.begin(); i != mp.end(); i++) {
		if (i->second == maxtime) {
			printf("%s ", i->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
	system("PAUSE");
	return 0;
	
}