// 将数列中的每个数字读取到temp中，假设我们选取的片段中包括temp，且这个片段的首尾指针分别为p和q，
// 那么对于p，有i种选择，即12…i，对于q，有n-i+1种选择，即i, i+1, … n，所以p和q组合形成的首尾片段有i * (n-i+1)种，
// 因为每个里面都会出现temp，所以temp引起的总和为temp * i * (n – i + 1)；遍历完所有数字，将每个temp引起的总和都累加到sum中，
// 最后输出sum的值～
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

int main() {
	cin >> n;
	double sum = 0.0, tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		sum += tmp * i*(n - i + 1);
	}
	printf("%.2f", sum);
	system("PAUSE");
	return 0;

}