/*
这是思维题
主要思路是
例子是2120
1.如果当前位数字为0，那么该位的1的个数由更高位的数字确定。比如2120，个位为1的个数为212 * 1 = 212（个位的单位为1）。
2.如果当前位数字为1，那么该位的1的个数不但由高位决定，还由低位数字决定。比如2120百位为1，那么百位数字1的个数为2 * 100 + 20 + 1 = 221个（百位的单位为100）。
3.如果当前位数字大于1，那么该位数字1的个数为（高位数+ 1） * 位数单位。比如2120十位为2，那么十位数字1的个数为（21 + 1） * 10 = 220个（十位的单位为10）
*/

#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	long long wei = 1,low=0,high=0,cur=0;
	long long ans = 0;
	while (n / wei) {
		high = n / (wei * 10);
		low = n - (n / wei)*wei;
		cur = (n / wei) % 10;
		if (cur == 0) {
			ans += high * wei;
		}
		else if(cur==1)
		{
			ans += high * wei + low + 1;
		}
		else {
			ans += (high + 1)*wei;
		}
		wei *= 10;
	}
	//cout << ans;
	printf("%lld", ans);
	system("PAUSE");
}