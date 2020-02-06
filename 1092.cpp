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

char shop[1005], eva[1005];
map<char, int> str;

int main() {
	cin >> shop >> eva;
	for (int i = 0; i < strlen(shop); i++) {
		if (str.find(shop[i]) == str.end()) {
			str[shop[i]] = 1;
		}
		else str[shop[i]]++;
	}
	int miss = 0;
	for (int i = 0; i < strlen(eva); i++) {
		if (str.find(eva[i]) != str.end()) {
			if (str[eva[i]] > 0)str[eva[i]]--;
			else {
				miss++;
			}
		}
		else {
			miss++;
		}
		
	}
	if (miss == 0) {
		cout << "Yes " << strlen(shop) - strlen(eva);
	}
	else {
		cout << "No " << miss;
	}
	system("PAUSE");
}