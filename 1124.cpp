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

int m,n,s;
vector<string> forwards;
vector<string> ans;
set<string> winner;


int main() {
	scanf("%d %d %d", &m,&n,&s);
	for (int i = 0; i < m; i++) {
		char tmp[25];
		scanf("%s", tmp);
		string t = tmp;
		forwards.push_back(t);
	}
	if (s > forwards.size()) {
		printf("Keep going...");
	}
	else
	{
		for (int i = s - 1; i < forwards.size(); i+=n) {
			if (winner.find(forwards[i]) == winner.end()) {
				winner.insert(forwards[i]);
				ans.push_back(forwards[i]);
			}
			else
			{
				for (int j = i; j < forwards.size(); j++) {
					if (winner.find(forwards[j]) == winner.end()) {
						winner.insert(forwards[j]);
						ans.push_back(forwards[j]);
						i = j;
						break;
					}
				}
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			printf("%s\n", ans[i].c_str());
		}
	}

	
	
	system("PAUSE");
	return 0;
}