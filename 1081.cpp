/*
一开始最后一个点过不了，当结果整数和分数部分都是0的话，需要特判
*/
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

ll integer=0, numerator=0, denominator=0;
int n;

ll gcd(ll a,ll b) {
	if (!b) return a;
	return gcd(b, a%b);
}

void add(ll tnum, ll tden) {
	ll g = gcd(max(tden, denominator), min(tden, denominator));
	numerator *= tden / g;
	tnum *= denominator / g;
	denominator = g * (tden / g)*(denominator / g);
	numerator += tnum;
	integer += numerator / denominator;
	numerator = numerator % denominator;
	g = gcd(denominator, abs(numerator));
	denominator /= g;
	numerator /= g;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			scanf("%lld/%lld", &numerator, &denominator);
			integer = numerator / denominator;
			numerator -= integer * denominator;
		}
		else {
			ll tnum, tden;
			scanf("%lld/%lld", &tnum, &tden);
			add(tnum, tden);
		}
	}
	if (integer != 0) {
		printf("%lld",integer);
	}
	if (numerator != 0) {
		if (integer == 0) {
			printf("%lld/%lld", numerator, denominator);
		}
		else
		{
			printf(" %lld/%lld", numerator, denominator);
		}
		
	}
	if (integer == 0 && numerator == 0) {
		printf("0");
	}
	
	system("PAUSE");
}