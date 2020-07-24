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

int n;
string z;

int main() {
	scanf("%d", &n);
	while (n--)
	{
		cin >> z;
		string a, b;
		a = z.substr(0, z.size() / 2);
		b = z.substr(z.size() / 2, z.size() / 2);
		//cout << b;
		long m, p, q;	
		m=stol(z);
		p=stol(a);
		q = stol(b);
		if ((p*q)&&(m % (p * q)) == 0) {
			printf("Yes\n");
		}
		else
		{
			printf("No\n");	
		}

	}
	system("PAUSE");
	return 0;
}