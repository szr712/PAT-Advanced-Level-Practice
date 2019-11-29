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

string a, b;
set<char>detected, out;

int main() {
	cin >> a >> b;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] <= 'z'&&b[i] >= 'a') {
			out.insert(b[i]);
			out.insert(b[i]-'a'+'A');
		}
		else if(b[i]<='Z'&&b[i]>='A'){
			out.insert(b[i]);
			out.insert(b[i] + 'a' - 'A');
		}
		else
		{
			out.insert(b[i]);
		}
	}
	for (int i = 0; i < a.length(); i++) {
		if (detected.find(a[i]) != detected.end()) {
			continue;
		}
		else if (out.find(a[i]) == out.end()) {
			if (a[i] <= 'z'&&a[i] >= 'a') {
				detected.insert(a[i]);
				detected.insert(a[i] - 'a' + 'A');
				printf("%c", a[i] - 'a' + 'A');
			}
			else if (a[i] <= 'Z'&&a[i] >= 'A') {
				detected.insert(a[i]);
				detected.insert(a[i] + 'a' - 'A');
				printf("%c", a[i]);
			}
			else
			{
				detected.insert(a[i]);
				printf("%c", a[i]);
			}
		}
	}
	system("PAUSE");
}