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

string ge[] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string shi[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int main() {
	scanf("%d\n", &n);
	while (n--) {
		string num;
		getline(cin, num);
		if (num[0] <= '9'&&num[0] >= '0') {
			int t = stoi(num);
			if ( t < 13) {
				cout << ge[t] << endl;
			}
			else {
				cout << shi[t / 13 ] ;
				if (t % 13 != 0) {
					cout <<" " <<ge[t % 13];
				}
				cout<<endl;
			}
		}
		else
		{
			int n1=0, n2=0;
			string a, b;
			a = num.substr(0, 3);
			if (num.length() > 3) {
				b = num.substr(4, 3);
			}
			for (int i = 0; i < 13; i++) {
				if (a == shi[i]) n1 = i;
				if (b == ge[i] || a == ge[i]) n2 = i;
			}
			cout << n1 * 13 + n2 << endl;
			
		}
	}
	system("PAUSE");
	return 0;

}