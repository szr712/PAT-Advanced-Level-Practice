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
string ans;

int main() {
	cin >> ans >> n;
	for (int i = 2; i <= n; i++) {
		string tmp ;
		for (int j = 0; j < ans.length();j=m) {
			for (m = j; m < ans.length()&&ans[j]==ans[m]; m++) {
				//if (ans[j] != ans[m]) break;
			}
			tmp +=  ans[j]+to_string(m-j);
			//tmp = tmp + ans[j] + to_string(m - j);
		}
		ans = tmp;
	}
	cout << ans;
	//system("PAUSE");
	return 0;
}