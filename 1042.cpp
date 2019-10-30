#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
using namespace std;

string word[] = { "S","H","C","D","J" };
string num[] = { "1","2","3","4","5","6","7","8","9","10" ,"11","12","13" };
string card[60];
int n;
int order[60];
struct match
{
	string c;
	int o;
};
vector<match> ans;

bool cmp(match m, match n) {
	return m.o < n.o;
}

int main() {
	int t = 1;
	for (int i = 0; i < 5; i++) {
		if (word[i] != "J") {
			for (int j = 0; j < 13; j++) {
				card[t] = word[i] + num[j];
				t++;
			}
		}
		else {
			card[t] = word[i] + "1";
			card[t + 1] = word[i] + "2";
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < 54; i++) {
		scanf("%d", &order[i]);
	}
	for (int i = 1; i <= 54; i++) {
		match tmp;
		tmp.c = card[i];
		ans.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 54; j++) {
			ans[j].o = order[j];
		}
		sort(ans.begin(), ans.end(), cmp);
	}
	for (int i = 0; i < 53; i++) {
		cout << ans[i].c << " ";
	}
	cout << ans[53].c;
	system("PAUSE");
}