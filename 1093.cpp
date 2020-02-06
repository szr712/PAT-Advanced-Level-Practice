//思维题，方法是计算每个A前面有几个P，后面有几个T
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
typedef long long ll;

char str[100005];
ll cnt[100005];
const ll mod = 1000000007;

int main() {
	cin >> str;
	memset(cnt, 0, sizeof(cnt));
	int t = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'P') t++;
		if (str[i] == 'A') cnt[i] = t;
	}
	ll ans = 0;
	t = 0;
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] == 'T') t++;
		if (str[i] == 'A') {
			ans += cnt[i] * t;
			ans = ans % mod;
		}
	}
	cout << ans;
	system("PAUSE");
}