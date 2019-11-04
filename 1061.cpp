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

string date[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
string a, b;

int main() {
	string ans;
	int h, m;
	bool flag = 0;
	cin >> a >> b;
	for (int i = 0; i < a.length() && b.length(); i++) {
		if (a[i] == b[i]) {
			if (!flag&&a[i] >= 'A'&&a[i] <= 'G') {
				ans = ans + date[int(a[i] - 'A')];
				flag = 1;
			}
			else if (flag) {
				if (a[i] >= '0'&&a[i] <= '9') {
					h = a[i] - '0';
					break;
				}
				else if (a[i] >= 'A'&&a[i] <= 'N') {
					h = (a[i] - 'A') + 10;
					break;
				}
			}
		}
	}
	cin >> a >> b;
	for (int i = 0; i < a.length() && b.length(); i++) {
		if (a[i] == b[i]) {
			if (a[i] <= 'z'&&a[i] >= 'a') {
				m = i;
				break;
			}
			else if (a[i] <= 'Z'&&a[i] >= 'A') {
				m = i;
				break;
			}
		}
	}
	cout << ans << " ";
	printf("%02d:%02d", h, m);
	system("PAUSE");
}