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

int n, m;
string num;

bool isprime(int a) {
	if (a <= 1) return false;
	for (int i = 2; i <= sqrt(a) ; i++) {
		if (a%i == 0) return false;
	}
	return true;
}


int main() {
	scanf("%d %d", &m, &n);
	cin >> num;
	bool flag = 0;
	for (int i = 0; i+n <= num.length(); i++) {
		string tmp = num.substr(i, n);
		if (isprime(stoi(tmp))) {
			cout << tmp;
			flag = 1;
			break;
		}
	}
	if (!flag) printf("404");
	system("PAUSE");
	return 0;
}