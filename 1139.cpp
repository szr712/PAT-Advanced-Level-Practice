// 3.A在寻找同性朋友时，需要避免找到他想要的伴侣B，所以当当前朋友就是B或者B的同性朋友就是A时舍弃该结果
// 4.输出时候要以4位数的方式输出，所以要%04d
// 5.如果用int接收一对朋友，-0000和0000对于int来说都是0，将无法得知这个人的性别，也就会影响他找他的同性朋友的那个步骤，所以考虑用字符串接收，因为题目中已经表示会以符号位加四位的方式给出输入，所以只要判断字符串是否大小相等，如果大小相等说明这两个人是同性
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

int n,m;
int k;
map<int, set<int>> friends;
set<int> girls, boys;

struct pairs
{
	int a, b;
};

bool cmp(pairs a, pairs b) {
	if (abs(a.a) < abs(b.a)) return true;
	else if(a.a==b.a){
		return abs(a.b) < abs(b.b);
	}
	return false;
}

bool judge(int a, int b) {
	if (girls.find(a) != girls.end() && girls.find(b) != girls.end()) return true;
	else if (boys.find(a) != boys.end() && boys.find(b) != boys.end()) return true;
	else return false;
}


int main() {
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		char a[10], b[10];
		scanf("%s %s", a, b);
		int x, y;
		x = stoi(a);
		y = stoi(b);
		if (strlen(a) != 4) {
			girls.insert(x);
		}
		else boys.insert(x);
		if (strlen(b) != 4) {
			girls.insert(y);
		}
		else
		{
			boys.insert(y);
		}
		friends[x].insert(y);
		friends[y].insert(x);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vector<pairs> ans;
		for (auto i = friends[a].begin(); i!= friends[a].end(); i++) {
			if (judge(a,*i)&&(*i)!=b) {
				for (auto j = friends[b].begin(); j != friends[b].end();j++) {
					if (judge(b,*j) && friends[*i].find(*j)!=friends[*i].end()&&(*j)!=a) {
						pairs p;
						p.a = *i;
						p.b = *j;
						ans.push_back(p);
					}
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%04d %04d\n", abs(ans[i].a), abs(ans[i].b));
		}
	}

	system("PAUSE");
	return 0;
}