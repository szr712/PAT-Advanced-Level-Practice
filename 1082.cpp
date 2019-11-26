/*
要考虑单零的情况！！！！！！否则测试点3过不去
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

string num[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string wei[] = { "","","Shi","Bai","Qian","Wan","","","","Yi" };
string n;

int main() {
	cin >> n;
	if (n == "0")cout << "ling";
	bool flag = 0;
	if (n[0] == '-') {
		cout << "Fu";
		flag = 1;
		n = n.substr(1, n.length() - 1);
	}
	string qian="", wan="", yi="";
	if (n.length() <= 4) {
		qian = n;
	}
	else if(n.length()<=8){
		qian = n.substr(n.length() - 4, 4);
		wan = n.substr(0, n.length() - 4);
	}
	else {
		qian = n.substr(n.length() - 4, 4);
		wan = n.substr(n.length()-8, 4);
		yi = n.substr(0, n.length() - 8);
	}
	if (yi != "") {
		bool f = 0;
		for (int i = 0; i < yi.length(); i++) {
			if (yi[i] != '0') {
				if (flag)cout << " ";
				cout << num[yi[i] - '0'];
				flag = 1;
				f = 1;
				if (i != yi.length() - 1) {
					cout<<" "<<wei[yi.length()-i];
				}
				
			}
			else {
				for (int j = i; j < yi.length(); j++) {
					if (yi[j] != '0') {
						i = j-1;
						cout << " " << "ling";
						break;
					}
				}
			}
		}
		if(f) cout << " " << "Yi";
	}
	if (wan != "") {
		bool f = 0;
		for (int i = 0; i < wan.length(); i++) {
			if (wan[i] != '0') {
				if (flag)cout << " ";
				flag = 1;
				cout << num[wan[i] - '0'];
				f = 1;
				if (i != wan.length() - 1) {
					cout << " " << wei[wan.length() - i];
				}

			}
			else {
				for (int j = i; j < wan.length(); j++) {
					if (wan[j] != '0') {
						i = j-1;
						cout << " " << "ling";
						break;
					}
				}
			}
		}
		if (f) cout << " " << "Wan";
	}
	if (qian != "") {
		bool f = 0;
		for (int i = 0; i < qian.length(); i++) {
			if (qian[i] != '0') {
				if (flag)cout << " ";
				flag = 1;
				cout << num[qian[i] - '0'];
				f = 1;
				if (i != qian.length() - 1) {
					cout << " " << wei[qian.length() - i];
				}

			}
			else {
				for (int j = i; j < qian.length(); j++) {
					if (qian[j] != '0') {
						i = j-1;
						cout << " " << "ling";
						break;
					}
				}
			}
		}
	}
	system("PAUSE");
}