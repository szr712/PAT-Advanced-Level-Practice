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

struct num
{
	ll numerator, denominators;
	ll integer;
};
num num1, num2;

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a%b);
}

void simple(num &tmp) {
	if (tmp.denominators < 0) {
		tmp.denominators = 0- tmp.denominators;
		tmp.numerator = 0- tmp.numerator;
	}
	tmp.integer = 0;
	ll t = abs(gcd(max(tmp.numerator, tmp.denominators), min(tmp.numerator, tmp.denominators)));
	tmp.numerator /= t;
	tmp.denominators /= t;
	tmp.integer = tmp.numerator / tmp.denominators;
	tmp.numerator -= tmp.denominators*tmp.integer;
	if (tmp.integer < 0)tmp.numerator = abs(tmp.numerator);
}

void display(num tmp) {
	simple(tmp);
	bool flag = 0;
	if (tmp.integer == 0 && tmp.numerator == 0) {
		printf("0 ");
		return;
	}
	if (tmp.integer < 0 || tmp.numerator < 0) {
		flag = 1;
		printf("(");
		if (tmp.integer != 0 && tmp.denominators != 1) {
			printf("%lld %lld/%lld", tmp.integer, tmp.numerator, tmp.denominators);
			printf(") ");
			return;
		}
		if (tmp.integer != 0) {
			printf("%lld", tmp.integer); 
			printf(") ");
			return;
		}
		if (tmp.denominators != 1) {
			printf("%lld/%lld) ", tmp.numerator, tmp.denominators);
			return;
		}
	}
	if (tmp.integer != 0) {
		printf("%lld ", tmp.integer);
	}
	if (tmp.denominators != 1) {
		printf("%lld/%lld ", tmp.numerator,tmp.denominators);
	}
}

void display2(num tmp) {
	simple(tmp);
	bool flag = 0;
	if (tmp.integer == 0 && tmp.numerator == 0) {
		printf("0");
		return;
	}
	if (tmp.integer < 0 || tmp.numerator < 0) {
		flag = 1;
		printf("(");
		if (tmp.integer != 0 && tmp.denominators != 1) {
			printf("%lld %lld/%lld", tmp.integer, tmp.numerator, tmp.denominators);
			printf(")");
			return;
		}
		if (tmp.integer != 0) {
			printf("%lld", tmp.integer);
			printf(")");
			return;
		}
		if (tmp.denominators != 1) {
			printf("%lld/%lld)", tmp.numerator, tmp.denominators);
			return;
		}
	}
	else {
		if (tmp.integer != 0 && tmp.denominators != 1) {
			printf("%lld %lld/%lld", tmp.integer, tmp.numerator, tmp.denominators);
			return;
		}
		if (tmp.integer != 0) {
			printf("%lld", tmp.integer);
			return;
		}
		if (tmp.denominators != 1) {
			printf("%lld/%lld", tmp.numerator, tmp.denominators);
			return;
		}
	}
}

void add(num num1, num num2) {
	display(num1);
	printf("+ ");
	display(num2);
	printf("= ");
	num ans;
	ll t = gcd(max(num1.denominators, num2.denominators),min(num1.denominators, num2.denominators));
	num1.numerator *= num2.denominators / t;
	num2.numerator *= num1.denominators / t;
	ans.numerator = num1.numerator + num2.numerator;
	ans.denominators = num1.denominators*num2.denominators / t;
	//simple(ans);
	display2(ans);
	printf("\n");
}

void dif(num num1, num num2) {
	display(num1);
	printf("- ");
	display(num2);
	printf("= ");
	num ans;
	ll t = gcd(max(num1.denominators, num2.denominators), min(num1.denominators, num2.denominators));
	num1.numerator *= num2.denominators / t;
	num2.numerator *= num1.denominators / t;
	ans.numerator = num1.numerator - num2.numerator;
	ans.denominators = num1.denominators*num2.denominators / t;
	//simple(ans);
	display2(ans);
	printf("\n");
}

void mul(num num1, num num2) {
	display(num1);
	printf("* ");
	display(num2);
	printf("= ");
	num ans;
	ans.numerator = num1.numerator * num2.numerator;
	ans.denominators = num1.denominators*num2.denominators;
	//simple(ans);
	display2(ans);
	printf("\n");
}

void quo(num num1, num num2) {
	display(num1);
	printf("/ ");
	display(num2);
	printf("= ");
	num ans;
	ans.numerator = num1.numerator * num2.denominators;
	ans.denominators = num1.denominators*num2.numerator;
	if (ans.denominators == 0) {
		printf("Inf");
		return;
	}
	//simple(ans);
	display2(ans);
	printf("\n");
}

int main() {
	scanf("%lld/%lld %lld/%lld", &num1.numerator, &num1.denominators, &num2.numerator, &num2.denominators);
	//simple(num1);
	//simple(num2);
	add(num1, num2);
	dif(num1, num2);
	mul(num1, num2);
	quo(num1, num2);
	system("PAUSE");
}