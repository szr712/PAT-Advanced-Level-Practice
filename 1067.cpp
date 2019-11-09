/*
基本思路（有两个测试样例超时）：1.因为元素位0~n-1，刚好与数组下标相对应，假设0元素所在下标位i,元素i的下标为j，数组为array，于是可以将 array[i]与array[j]交换，然后更新0元素下标为j，假如0元素的下标为0，则遍历数组找到第一个array[k]!=k

的元素，然后将array[k]与array[i]交换，之后重复以上过程，直至遍历数组时k==n时说明排序完毕。（因为每次都要查找元素array[j],所以遍历开销较大，超时）

优化后的思路：运用对称性，array[i]中存储元素a ，可理解为a元素占据了i的位置即array[a]==i。将要交换的元素变为数组的角标，可利用数组的随机存储性，在常数时间内找到钥交换的元素，这样就能解决超时问题。（关于数组与脚标的关系，可阅读《剑指offer》c++版第二章）
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

int n;
int num[100005];

int main() {
	memset(num, -1, sizeof(num));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		num[i] = tmp;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] != i) {
			while (num[0] != 0) {
				swap(num[0], num[num[0]]);//所谓的运用了对称性就体现在这里，因为在此题中数字和下标实际上是等价的，因此与下标0交换实际上就是和数字0交换
				ans++;
			}
			if (num[i] != i) {
				swap(num[i], num[0]);//这里就是普通思路，交换数字0
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	system("PAUSE");
}