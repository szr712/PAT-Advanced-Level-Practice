// 就所给样例来说，将输入数据从小到大排序后序列为：2 3 6 6 7 7 8 8 9 10

// （1）很明显所给数据中骑车超过0公里的天数为10天，自然满足有0天骑车超过0公里的条件，此时E=0

// （2）骑车超过1公里的天数为10天，自然满足有1天骑车超过1公里的条件，此时E=1

// （3）骑车超过2公里的天数为9天，自然满足有2天骑车超过2公里的条件，此时E=2

// （4）骑车超过3公里的天数为8天，自然满足有3天骑车超过3公里的条件，此时E=3

// （5）骑车超过4、5公里的天数均为8天，自然满足有4天或5天骑车超过4或5公里的条件，由于5>4此时E=5

// （6）骑车超过6公里的天数均为6天，自然满足有6天骑车超过6公里的条件，此时E=6

// （7）骑车超过7公里的天数均为4天，不满足有7天骑车超过7公里的条件，E=6，查找爱丁顿数结束，爱丁顿数为6

// 注意点
// 爱丁顿数不一定为给定的骑车距离中的某一个数
// 即使骑车超过K公里的天数大于K，我们也可以认为满足有K天骑车超过K公里，K即为爱丁顿数的一个备选
// 查找范围的左界应为0，例如输入数据全为0时，爱丁顿数为0

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
vector<int> days;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		days.push_back(tmp);
	}
	sort(days.begin(), days.end(), cmp);
	int e = 0;
	for (int i = 0; i < days.size(); i++) {
		if (days[i] > e + 1) {
			e++;
		}
		else break;

		
	}
	printf("%d", e);
	system("PAUSE");
	return 0;
}