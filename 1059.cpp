//一开始想要把素数表直接写在代码里，发现会超出代码长度限制，这里用了打素数表的方法
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
const int maxn = 50000;

bool prime[maxn] = { 0 };
long long n;

int main() {
	for (int i = 2; i*i <= maxn; i++) {
		for (int j = 2; j*i <= maxn; j++) {
			prime[j * i] = 1;
		}
	}
	scanf("%lld", &n);
	printf("%lld=", n);
	if (n == 1) printf("1");
	bool flag = 0;
	for (int i = 2; i < maxn&&n >= 2; i++) {
		long long count = 0;
		while (n%i==0&&!prime[i]) {
			count++;
			n /= i;
		}
		if (!flag&&count>=1) {
			printf("%d", i);
			flag = 1;
		}
		else if(count>=1){
			printf("*%d",i);
		}
		if (count > 1)printf("^%lld", count);
	}
	if (n > 1) {
		if(!flag) printf("%lld", n);
		else printf("*%lld", n);
	}
	system("PAUSE");
}