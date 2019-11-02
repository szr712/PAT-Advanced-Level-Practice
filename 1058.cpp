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

long long a1, b1, c1, a2, b2, c2;

int main() {
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &b1, &c1, &a2, &b2, &c2);
	long long ans[3] = { 0 };
	long long tmp = 0;
	ans[0] = c2 + c1;
	if (ans[0] >= 29) {//要有等于号
		tmp = ans[0] / 29;
		ans[0] = ans[0] - tmp * 29;
	}
	ans[1] = b2 + b1 + tmp;
	tmp = 0;//进位要重新置零
	if (ans[1] >= 17) {
		tmp = ans[1] / 17;
		ans[1] = ans[1] - tmp * 17;
	}
	ans[2] = a1 + a2 + tmp;
	printf("%lld.%lld.%lld\n", ans[2], ans[1], ans[0]);
	system("PAUSE");
}