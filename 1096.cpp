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
int maxnum = -1;


int main() {
	int index;
	cin >> n;
	int m = sqrt(n);
	for (int start = 2; start <= m; start++) {
		int tmp = n;
		int t = start;
		while (tmp%t == 0&&tmp!=0) {
			tmp /= t;
			t++;
		}
		if ((t-start)>maxnum&&(t-start)>0) {
			maxnum = t - start;
			index = start;
		}
	}
	if (maxnum == -1) {
		cout << 1 << endl << n;
	}
	else {
		cout << maxnum<<endl<<index;
		for (int i = 2; i <= maxnum; i++) {
			cout << "*" << ++index;
		}
	}
	system("PAUSE");
	return 0;
	
}